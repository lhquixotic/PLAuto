#include "ICANCmd.h"
#include <can_msgs/Frame.h>
#include <can_msgs/CanInfo.h>
#include <can_msgs/Frames.h>

struct Para{
  int _useCanDevIndex;
  int _useCanChannel;
  int _useCanSendType;
  int _useCanSendFrames;
  int _useCanSendTimes;
  int _useCanSendDely;
};

typedef struct{
    int Run;
    DWORD channelId;
}rcv_arg_t;

typedef struct {
DWORD channelId;
DWORD sndType;   //0 - 正常发送;1 - 单 次 发送;2 - 自发自收;3 - 单 次 自发自收
DWORD sndFrames; // 每次发送帧数
DWORD sndTimes;  // 发送次数
}snd_arg_t;

namespace ns_likecan{
class LikeCan
{
private:
    Para can_para;
     
    // define basic variables
    
    unsigned long CanSendcount = 0;
    unsigned long CanRecvcount = 0;
    unsigned long CanRecvErrcount = 0;
    
    // Channel configuration
    CAN_InitConfig can_channel_cfg0;
    Wakeup_Config can_wakeup_cfg0;
    CAN_InitConfig can_channel_cfg1;
    Wakeup_Config can_wakeup_cfg1;
    
    snd_arg_t snd_arg0;
    rcv_arg_t rcv_arg0;

    // define basic methds
    void exitCanProcedure();

public:
    DWORD dwDeviceHandle;
    std::vector<can_msgs::Frame> test_frames;
    std::vector<can_msgs::Frame> rcv_frames;
    int openCanDevice();
    int openCanChannel(int channel_id);
    void readCanDeviceInfo();
    void sendProc(std::vector<can_msgs::Frame>  &frames);
    void recvProc();
    void setCanParameters(Para para);
    LikeCan ();

};
}