#include "likecan.hpp"
#include <ros/ros.h>

namespace ns_likecan{

// Public methods
LikeCan::LikeCan(){
    can_channel_cfg0.bMode = 0;  // 工作模式(0表示正常模式,1表示只听模式)
    can_channel_cfg0.dwAccCode = 0;
    can_channel_cfg0.dwAccMask = 0xffffffff;
    can_channel_cfg0.dwBtr[0] = 0x00; // BTR0   0014 -1M 0016-800K 001C-500K 011C-250K 031C-12K 041C-100K 091C-50K 181C-20K 311C-10K BFFF-5K
    can_channel_cfg0.dwBtr[1] = 0x1c; // BTR1
    can_channel_cfg0.dwBtr[2] = 0;
    can_channel_cfg0.dwBtr[3] = 0;
    can_channel_cfg0.nBtrType = 1; // 位定时参数模式(1表示SJA1000,0表示LPC21XX)
    can_channel_cfg0.nFilter = 0;  // 滤波方式(0表示未设置滤波功能,1表示双滤波,2表示单滤波)

    can_wakeup_cfg0.dwAccCode = (0x123<<21);   // 帧ID为0x123的标准帧 唤醒
    can_wakeup_cfg0.dwAccMask = 0x001FFFFF;     // 固定
    can_wakeup_cfg0.nFilter = 2; // 滤波方式(0表示未设置滤波功能-收到任意CAN数据都能唤醒,1表示双滤波,2表示单滤波,3-关闭唤醒功能)

    snd_arg0.channelId = 0;
    snd_arg0.sndType = can_para._useCanSendType; //CAN发送类型,0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
    snd_arg0.sndTimes = can_para._useCanSendTimes; // 发送次数
    // snd_arg0.sndFrames = can_para._useCanSendFrames;  
    snd_arg0.sndFrames = 1;

    rcv_arg0.channelId = 0;
    rcv_arg0.Run = TRUE;

    can_msgs::Frame frame;
    frame.id = 0x00000345;
    frame.dlc = 8;
    frame.is_error = 0;
    frame.is_extended = 1;
    frame.is_rtr = 0;
    for (int i = 0;i < 8;i++){
        frame.data[i] = i+3;
    }
    test_frames.push_back(frame);
}

void LikeCan::setCanParameters(Para para){
    can_para = para;
}

int LikeCan::openCanDevice(){
    if ( (dwDeviceHandle = CAN_DeviceOpen (ACUSB_132B,can_para._useCanDevIndex,0)) == 0){        
        exitCanProcedure();
        ROS_ERROR_STREAM("[likecan] Open device error! ");
    }
    ROS_INFO_STREAM("[likecan] Open device success! ");
    return 1;
}


void LikeCan::readCanDeviceInfo(){
    CAN_DeviceInformation DevInfo;
    if ( CAN_GetDeviceInfo(dwDeviceHandle, &DevInfo) != CAN_RESULT_OK ) {
      exitCanProcedure();
      ROS_ERROR_STREAM("[likecan] GetDeviceInfo error!");
   }
   // Print  device infomation
   ROS_INFO_STREAM(
       "\n******** CAN DEVICE PARAMETERS ********\n" << 
       "CAN Channel number: " << DevInfo.bChannelNumber << "\n" <<
       "CAN Hardware version: " << DevInfo.uHardWareVersion << "\n" <<
       "***************************************"
   );
}

void  LikeCan::sendProc(std::vector<can_msgs::Frame> &frames){
    ROS_INFO_STREAM("Queue size: " << frames.size());
    if (frames.empty()){
        ROS_WARN_STREAM("[likecan] No can frames in the queue size.");
    }else{
        // Send through CAN 0
        snd_arg_t * snd_arg = & (snd_arg0);
        CAN_DataFrame * send = new CAN_DataFrame[snd_arg->sndFrames];
        
        int channel_id = snd_arg ->channelId;
        for ( int j = 0; j < frames.size(); j++ ) {
            can_msgs::Frame frame = frames[j];
            send[j].uID = frame.id;         // ID
            send[j].nSendType = snd_arg->sndType;  // 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
            send[j].bRemoteFlag = frame.is_rtr;  // 0-数据帧；1-远程帧
            send[j].bExternFlag = frame.is_extended;  // 0-标准帧；1-扩展帧
            send[j].nDataLen = frame.dlc;     // DLC
            for ( int i = 0; i < send[j].nDataLen; i++ ) {
                send[j].arryData[i] = frame.data[i];
            }
        }
        unsigned long sndCnt = CAN_ChannelSend(dwDeviceHandle,channel_id,send,snd_arg->sndFrames);
        CanSendcount += sndCnt * frames.size();
        // frames.clear();

        ROS_INFO_STREAM("Sent frames number:  " << CanSendcount); 
    }
}

void LikeCan::recvProc(){
    rcv_arg_t * rcv_arg = & (rcv_arg0);
    if(rcv_arg->Run) {
        ROS_INFO_STREAM("[likecan] Receiving can messages...");
        int reclen = 0;
        CAN_DataFrame rec[100];
        CAN_ErrorInformation err;
        if( (reclen = CAN_ChannelReceive(dwDeviceHandle,rcv_arg -> channelId,rec,sizeof(rec),200)) >0){
            ROS_INFO("CAN0 Receive:ID 0x%08X, Frame: %02X %02X %02X %02X %02X %02X %02X %02X.",
                                    rec[reclen-1].uID, rec[reclen -1].arryData[0], rec[reclen -1].arryData[1],
                                    rec[reclen -1].arryData[2],rec[reclen -1].arryData[3],rec[reclen -1].arryData[4],
                                    rec[reclen -1].arryData[5],rec[reclen -1].arryData[6],rec[reclen -1].arryData[7]);
        CanRecvcount += reclen;
        can_msgs::Frame rcv_frame;
        rcv_frame.id = rec[reclen-1].uID;
        rcv_frame.dlc = sizeof(rec[reclen-1].arryData);
        for ( int i = 0; i < rcv_frame.dlc; i++){
            rcv_frame.data[i] = rec[reclen-1].arryData[i];  
        }
        rcv_frames.push_back(rcv_frame);

        // ROS_INFO_STREAM("CAN0 rcv count = " << rcv_frames.size());
        ROS_INFO_STREAM("CAN0 rcv count = " << CanRecvcount);
        }else{
            if (CAN_GetErrorInfo(dwDeviceHandle,rcv_arg -> channelId,&err) == CAN_RESULT_OK){
                CanRecvErrcount ++;
            }else{}
        }
    }
}


int LikeCan::openCanChannel(int channel_id){
    CAN_InitConfig config;
    Wakeup_Config wakeup_config;
    if (channel_id == 0){
        config = can_channel_cfg0;
        wakeup_config = can_wakeup_cfg0;
    }else{
        if (channel_id == 1){
            config = can_channel_cfg1;
            wakeup_config = can_wakeup_cfg1;
        }else{
            exitCanProcedure();
            ROS_ERROR_STREAM("[likecan] No such channel: " << channel_id << " ! ");
        }
    }
    // channel config
    if ( CAN_ChannelStart(dwDeviceHandle, channel_id, &config) != CAN_RESULT_OK ) {
        exitCanProcedure();
        ROS_ERROR_STREAM("[likecan] Start CAN " << channel_id << " error");
    }
    // wake up 
    if ( CAN_SetParam(dwDeviceHandle, channel_id, PARAM_WAKEUP_CFG, &wakeup_config) != CAN_RESULT_OK){
        ROS_WARN_STREAM("[likecan] CAN " << channel_id << " not support Wakeup");
    }
    return 1;
}

// Private methods
void LikeCan::exitCanProcedure(){
    if ( (can_para._useCanChannel & 1) == 1){
        ROS_INFO_STREAM("CAN_ChannelStop 0");
        CAN_ChannelStop(dwDeviceHandle,0);
    }
    if ( ( can_para._useCanChannel & 2) == 2){
        ROS_INFO_STREAM("CAN_ChannelStop 1");
        CAN_ChannelStop(dwDeviceHandle,1);      
    } 
    CAN_DeviceClose(dwDeviceHandle);
    ROS_INFO_STREAM("CAN_DeviceClose");
}
}