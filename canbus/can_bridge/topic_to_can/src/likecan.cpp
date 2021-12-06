#include "likecan.hpp"
#include <ros/ros.h>


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
}

void LikeCan::setCanParameters(Para para){
    can_para = para;
}

int LikeCan::openCanDevice(){
    if ( (dwDeviceHandle = CAN_DeviceOpen (ACUSB_132B,can_para._useCanDevIndex,0)) == 0){        
        exitCanProcedure();
        ROS_ERROR_STREAM("[can_bridge] Open device error! ");
    }
    ROS_INFO_STREAM("[can_bridge] Open device success! ");
    return 1;
}


void LikeCan::readCanDeviceInfo(){
    CAN_DeviceInformation DevInfo;
    if ( CAN_GetDeviceInfo(dwDeviceHandle, &DevInfo) != CAN_RESULT_OK ) {
      exitCanProcedure();
      ROS_ERROR_STREAM("[can_bridge] GetDeviceInfo error!");
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

    ROS_INFO_STREAM("Sent frames number:  " << CanSendcount); 
}

// void  * sendProc(void * param){
//     ROS_INFO_STREAM("FLAG1");
//     LikeCan * pCanMain = (LikeCan *) param;
    
//     // Send through CAN 0
//     snd_thread_arg_t * thread_arg = & (pCanMain->snd_thread_arg0);
//     CAN_DataFrame * send = new CAN_DataFrame[thread_arg->sndFrames];
//     int times = thread_arg ->sndTimes;
//     int channel_id = thread_arg ->channelId;

//     for ( int j = 0; j < thread_arg->sndFrames; j++ ) {
//         send[j].uID = channel_id;         // ID
//         send[j].nSendType = thread_arg->sndType;  // 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
//         send[j].bRemoteFlag = 0;  // 0-数据帧；1-远程帧
//         send[j].bExternFlag = 1;  // 0-标准帧；1-扩展帧
//         send[j].nDataLen = 8;     // DLC
//         for ( int i = 0; i < send[j].nDataLen; i++ ) {
//             send[j].arryData[i] = i;
//         }
//     }
//     ROS_INFO_STREAM("FLAG2");
//     while ( times ){
//         unsigned long sndCnt = CAN_ChannelSend(pCanMain->dwDeviceHandle,channel_id,send,thread_arg->sndFrames);
//         pCanMain->CanSendcount[channel_id] += sndCnt;
//         if ( sndCnt ){
//             times --;
//         }
//         delete[] send;
//         ROS_INFO_STREAM("[can_bridge] CAN " <<  channel_id << " Send Count: " 
//                                                     << pCanMain->CanSendcount[channel_id] << " end");
//     }
// }


// void LikeCan::createSndThread(){
//     int ret;
//     ret = pthread_create(&snd_thread_0,NULL,sendProc,this);
//     ROS_INFO_STREAM("FLAG0: test num = " << this);
//     ROS_INFO_STREAM("[can_bridge] Send thread Created. ");
// }

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
            ROS_ERROR_STREAM("[can_bridge] No such channel: " << channel_id << " ! ");
        }
    }
    // channel config
    if ( CAN_ChannelStart(dwDeviceHandle, channel_id, &config) != CAN_RESULT_OK ) {
        exitCanProcedure();
        ROS_ERROR_STREAM("[can_bridge] Start CAN " << channel_id << " error");
    }
    // wake up 
    if ( CAN_SetParam(dwDeviceHandle, channel_id, PARAM_WAKEUP_CFG, &wakeup_config) != CAN_RESULT_OK){
        ROS_WARN_STREAM("[can_bridge] CAN " << channel_id << " not support Wakeup");
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


