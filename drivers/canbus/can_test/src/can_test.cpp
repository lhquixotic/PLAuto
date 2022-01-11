//build command line: gcc -lCanCmd -lpthread -lrt -g -o testLikeCan testLikeCan.c

// sudo make install
// sudo make
// sudo ./testLikeCan
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <getopt.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include<ros/ros.h>

#include "ICANCmd.h"
using namespace std;
#define __countof(a)  (sizeof(a)/sizeof(a[0]))

#define  DEF_DEV_INDEX               0
#define  DEF_USE_CAN_NUM             3      // 0-自动选择 1-使用CAN0；2-使用CAN1；3-同时使用CAN0、CAN1
#define  DEF_SEND_TYPE		     0	    // CAN发送类型,0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
#define  DEF_SEND_FRAMES             64      // 每次发送帧数
#define  DEF_SEND_TIMES              1000  // 发送次数
#define  DEF_SEND_DELY               5      // 发送前延时,单位秒
// TODO:  put this to config file

DWORD dwDeviceHandle;
typedef struct {
   int Run;
   DWORD ch;
}rcv_thread_arg_t;

typedef struct {
   DWORD ch;
   DWORD sndType;   //0 - 正常发送;1 - 单 次 发送;2 - 自发自收;3 - 单 次 自发自收
   DWORD sndFrames; // 每次发送帧数
   DWORD sndTimes;  // 发送次数
}snd_thread_arg_t;

unsigned long CanSendcount[2] = { 0, 0 };

void* receive_func(void *param)  //接收线程的处理函数
{
   int reclen = 0;
   rcv_thread_arg_t *thread_arg = (rcv_thread_arg_t *)param;
   int ind = thread_arg->ch;
   unsigned long count = 0;
   unsigned long errcount = 0;
   CAN_DataFrame rec[100];
   int i;
   CAN_DataFrame snd;
   CAN_ErrorInformation err;
   printf("receive thread running....%d\n", ind);
   while ( thread_arg->Run ) {
      if ( (reclen = CAN_ChannelReceive(dwDeviceHandle, ind, rec, __countof(rec), 200)) > 0 ) {
         printf("CAN%d Receive: %08X", ind, rec[reclen - 1].uID);
         for ( i = 0; i < rec[reclen - 1].nDataLen; i++ ) {
            printf(" %02X", rec[reclen - 1].arryData[i]);
         }
         printf("\n");
         count += reclen;
         printf("CAN%d rcv count=%ld\n", ind, count);
      } else {
         if ( CAN_GetErrorInfo(dwDeviceHandle, ind, &err) == CAN_RESULT_OK ) {  // 必须调用CAN_GetErrorInfo函数
                                                                                // 处理错误信息
            errcount++;
         } else {
            // CAN卡没有收到CAN报文
         }
      }
   }
   printf("CAN%d rcv count=%ld err count:%ld\n", ind, count, errcount);
}

void* send_func(void *param)
{
   snd_thread_arg_t *thread_arg = (snd_thread_arg_t *)param;
   CAN_DataFrame *send = new CAN_DataFrame[thread_arg->sndFrames];
   int times = thread_arg->sndTimes;  //  26000-12h
   int ch = thread_arg->ch;

   for ( int j = 0; j < thread_arg->sndFrames; j++ ) {
      send[j].uID = ch;         // ID
      send[j].nSendType = thread_arg->sndType;  // 0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
      send[j].bRemoteFlag = 0;  // 0-数据帧；1-远程帧
      send[j].bExternFlag = 1;  // 0-标准帧；1-扩展帧
      send[j].nDataLen = 8;     // DLC
      for ( int i = 0; i < send[j].nDataLen; i++ ) {
         send[j].arryData[i] = i;
      }
   }
   while ( times ) {
      //printf("CAN%d Send %d\r\n", ch, times);
      unsigned long sndCnt = CAN_ChannelSend(dwDeviceHandle, ch, send, thread_arg->sndFrames);
      CanSendcount[ch] += sndCnt;
      if ( sndCnt )
         times--;
   }
   delete[] send;
   printf("CAN%d Send Count:%ld end \r\n", ch, CanSendcount[ch]);
}
// TODO: put this to header file
////////////////////////////////////////////////////////////////////////////////////////////////////////
// 自定义日志输出函数【不要在该函数中执行阻塞任务】
///////////////////////////////////////////////////////////////////////////////////////////////////////
void log_call_back(enum libcancmd_log_level level, const char *str)
{
	printf("%03d,%s", level,str);
}

int main(int argc, char **argv)
{
   ////////////////////////////////////////////////////////////////////////////////////////////////////////
   // 输入参数处理
   ///////////////////////////////////////////////////////////////////////////////////////////////////////
   char c;
   int helpflg = 0, errflg = 0;
   int __useCanDevIndex = DEF_DEV_INDEX; // CAN设备索引,从0开始
   int __useCanChannel = DEF_USE_CAN_NUM; // 1-使用CAN0；2-使用CAN1；3-使用CAN0、CAN1
   int __useCanSendType = DEF_SEND_TYPE; // CAN发送类型,0-正常发送;1-单次发送;2-自发自收;3-单次自发自收
   int __useCanSendFrames = DEF_SEND_FRAMES; // 每次发送帧数
   int __useCanSendTimes = DEF_SEND_TIMES; // 发送次数
   int __useCanSendDely  = DEF_SEND_DELY;  // 发送前延时

   ////////////////////////////////////////////////////////////////////////////////////////////////////////
   // 自定义库日志输出
   ///////////////////////////////////////////////////////////////////////////////////////////////////////
   CAN_SetLogCb(log_call_back);   // 设置日志输出回调函数
   CAN_SetDebug(_LOG_LEVEL_ERROR); // 设置日志级别
   ////////////////////////////////////////////////////////////////////////////////////////////////////////
   // CAN卡操作
   ///////////////////////////////////////////////////////////////////////////////////////////////////////
   time_t tm1, tm2;
   CAN_InitConfig config;
   Wakeup_Config  wakeup_config;
   int i = 0;
   rcv_thread_arg_t rcv_thread_arg0;
   rcv_thread_arg_t rcv_thread_arg1;
   snd_thread_arg_t snd_thread_arg0;
   snd_thread_arg_t snd_thread_arg1;
   pthread_t rcv_threadid0;
   pthread_t rcv_threadid1;
   pthread_t snd_threadid0;
   pthread_t snd_threadid1;
   int ret;
   // 打开设备
   if ( (dwDeviceHandle = CAN_DeviceOpen(ACUSB_132B, __useCanDevIndex, 0)) == 0 ) {
      printf("open deivce error\n");
      goto ext;
   }
   // 读取设备信息
   CAN_DeviceInformation DevInfo;
   if ( CAN_GetDeviceInfo(dwDeviceHandle, &DevInfo) != CAN_RESULT_OK ) {
      printf("GetDeviceInfo error\n");
      goto ext;
   }
   printf("--%s--\n", DevInfo.szDescription);
   printf("\tSN:%s\n", DevInfo.szSerialNumber);
   printf("\tCAN 通道数:%d\n", DevInfo.bChannelNumber);
   printf("\t硬件  版本:%x\n", DevInfo.uHardWareVersion);
   printf("\t固件  版本:%x\n\n", DevInfo.uFirmWareVersion);
   printf("\t驱动  版本:%x\n", DevInfo.uDriverVersion);
   printf("\t接口库版本:%x\n", DevInfo.uInterfaceVersion);
#if DEF_USE_CAN_NUM==0 
   if(DevInfo.bChannelNumber == 1) {
       __useCanChannel = 1;
   } else {
       __useCanChannel = 3;
   }
#endif
   // 启动CAN通道
   config.dwAccCode = 0;
   config.dwAccMask = 0xffffffff;
   config.nFilter  = 0;       // 滤波方式(0表示未设置滤波功能,1表示双滤波,2表示单滤波)
   config.bMode    = 0;             // 工作模式(0表示正常模式,1表示只听模式)
   config.nBtrType = 1;      // 位定时参数模式(1表示SJA1000,0表示LPC21XX)
   config.dwBtr[0] = 0x00;   // BTR0   0014 -1M 0016-800K 001C-500K 011C-250K 031C-12K 041C-100K 091C-50K 181C-20K 311C-10K BFFF-5K
   config.dwBtr[1] = 0x1c;   // BTR1
   config.dwBtr[2] = 0;
   config.dwBtr[3] = 0;
   if ( (__useCanChannel & 1) == 1 ) {
      if ( CAN_ChannelStart(dwDeviceHandle, 0, &config) != CAN_RESULT_OK ) {
         printf("Start CAN 0 error\n");
         goto ext;
      }
      // 标准帧唤醒(定制型号支持的可选操作)
      wakeup_config.dwAccCode = (0x123 << 21);  // 帧ID为0x123的标准帧 唤醒
      wakeup_config.dwAccMask = 0x001FFFFF;     // 固定
      wakeup_config.nFilter   = 2;              // 滤波方式(0表示未设置滤波功能-收到任意CAN数据都能唤醒,1表示双滤波,2表示单滤波,3-关闭唤醒功能)
      if ( CAN_SetParam(dwDeviceHandle, 0, PARAM_WAKEUP_CFG, &wakeup_config) != CAN_RESULT_OK ) {
         printf("CAN 0 not support Wakeup\n");
      }
   }

   if ( (__useCanChannel & 2) == 2 ) {
      if ( CAN_ChannelStart(dwDeviceHandle, 1, &config) != CAN_RESULT_OK ) {
         printf("Start CAN 1 error\n");
         goto ext;
      }
      // 扩展帧唤醒(定制型号支持的可选操作)
      wakeup_config.dwAccCode = (0x1234 << 3);  //  帧ID为0x1234的扩展帧 唤醒
      wakeup_config.dwAccMask = 00000007;       // 固定
      wakeup_config.nFilter   = 2;              // 滤波方式(0表示未设置滤波功能-收到任意CAN数据都能唤醒,1表示双滤波,2表示单滤波，3-关闭唤醒功能)
      if ( CAN_SetParam(dwDeviceHandle, 1, PARAM_WAKEUP_CFG, &wakeup_config) != CAN_RESULT_OK ) {
         printf("CAN 1 not support Wakeup\n");
      }
   }

// TODO: put this in init 

   // 创建接收线程
   if ( (__useCanChannel & 1) == 1 ) {
      rcv_thread_arg0.Run = TRUE;
      rcv_thread_arg0.ch = 0;
      ret = pthread_create(&rcv_threadid0, NULL, receive_func, &rcv_thread_arg0);
   }

   if ( (__useCanChannel & 2) == 2 ) {
      rcv_thread_arg1.Run = TRUE;
      rcv_thread_arg1.ch = 1;
      ret = pthread_create(&rcv_threadid1, NULL, receive_func, &rcv_thread_arg1);
   }
   
   // 延时创建发送线程
   printf("\nstart send dley:%d s\n", __useCanSendDely);
   for ( i = __useCanSendDely; i >= 0; i-- ) {
      sleep(1);
      printf(" %d\n", i);
   }
   printf("\n");
   // 创建发送线程
   if ( (__useCanChannel & 1) == 1 ) {
      snd_thread_arg0.ch = 0;
      snd_thread_arg0.sndType = __useCanSendType;
      snd_thread_arg0.sndFrames = __useCanSendFrames;
      snd_thread_arg0.sndTimes = __useCanSendTimes;
      ret = pthread_create(&snd_threadid0, NULL, send_func, &snd_thread_arg0);
   }

   if ( (__useCanChannel & 2) == 2 ) {
      snd_thread_arg1.ch = 1;
      snd_thread_arg1.sndType = __useCanSendType;
      snd_thread_arg1.sndFrames = __useCanSendFrames;
      snd_thread_arg1.sndTimes = __useCanSendTimes;
      ret = pthread_create(&snd_threadid1, NULL, send_func, &snd_thread_arg1);
   }

   printf("create thread\n");
   // 等待发送线程结束
   time(&tm1);
   if ( (__useCanChannel & 1) == 1 ) {
      pthread_join(snd_threadid0, NULL);
   }

   if ( (__useCanChannel & 2) == 2 ) {
      pthread_join(snd_threadid1, NULL);
   }
   time(&tm2);
   // 等待接收线程读取完所有帧
   printf("recive wait for completion dley:%d s\n", __useCanSendDely);
   for ( i = __useCanSendDely; i >= 0; i-- ) {
      sleep(1);
      printf(" %d\n", i);
   }
   printf("\n");
   // 退出接收线程
   rcv_thread_arg0.Run = FALSE;
   if ( (__useCanChannel & 1) == 1 ) {
      pthread_join(rcv_threadid0, NULL);
   }
   rcv_thread_arg1.Run = FALSE;
   if ( (__useCanChannel & 2) == 2 ) {
      pthread_join(rcv_threadid1, NULL);
   }
   printf("CAN0 Sendcount:%ld CAN1 Sendcount:%ld With time: %ld minute,%ld second\r\n", CanSendcount[0], CanSendcount[1], (tm2 - tm1) / 60, (tm2 - tm1) % 60);
ext:
   if ( (__useCanChannel & 1) == 1 ) {
      printf("CAN_ChannelStop 0\r\n");
      CAN_ChannelStop(dwDeviceHandle, 0);
   }

   if ( (__useCanChannel & 2) == 2 ) {
      printf("CAN_ChannelStop 1\r\n");
      CAN_ChannelStop(dwDeviceHandle, 1);
   }

   CAN_DeviceClose(dwDeviceHandle);
   printf("CAN_DeviceClose\r\n");
   printf("Press Enter key to exit the program\r\n");
   scanf("%c", &c);
}

//TODO: put this in run file