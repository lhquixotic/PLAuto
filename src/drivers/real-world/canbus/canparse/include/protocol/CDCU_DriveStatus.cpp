#include "CDCU_DriveStatus.h"
CDCU_DriveStatus::CDCU_DriveStatus(){
  id_ = 0x217;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_DrvSt_Checksum_=0;
  CDCU_DrvSt_RollCnt_=0;
  CDCU_MCU_ErrLevel_=0;
  CDCU_MCU_GearAct_=0;
  CDCU_MCU_MtrCurt_=0;
  CDCU_MCU_MtrSpd_=0;
  CDCU_MCU_RunDir_=0;
  CDCU_MCU_ThrotAct_=0;
  CDCU_MCU_WorkMode_=0;
}
void CDCU_DriveStatus::Reset(){
  CDCU_DrvSt_Checksum_=0;
  CDCU_DrvSt_RollCnt_=0;
  CDCU_MCU_ErrLevel_=0;
  CDCU_MCU_GearAct_=0;
  CDCU_MCU_MtrCurt_=0;
  CDCU_MCU_MtrSpd_=0;
  CDCU_MCU_RunDir_=0;
  CDCU_MCU_ThrotAct_=0;
  CDCU_MCU_WorkMode_=0;
}
void CDCU_DriveStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_DrvSt_Checksum();
  UpdateCDCU_DrvSt_RollCnt();
  UpdateCDCU_MCU_ErrLevel();
  UpdateCDCU_MCU_GearAct();
  UpdateCDCU_MCU_MtrCurt();
  UpdateCDCU_MCU_MtrSpd();
  UpdateCDCU_MCU_RunDir();
  UpdateCDCU_MCU_ThrotAct();
  UpdateCDCU_MCU_WorkMode();
}
/******************
signalname: CDCU_DrvSt_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_DriveStatus::UpdateCDCU_DrvSt_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_DrvSt_Checksum_ = ret;
}
double CDCU_DriveStatus::CDCU_DrvSt_Checksum(){
  return CDCU_DrvSt_Checksum_;
}
/******************
signalname: CDCU_DrvSt_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_DriveStatus::UpdateCDCU_DrvSt_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_DrvSt_RollCnt_ = ret;
}
double CDCU_DriveStatus::CDCU_DrvSt_RollCnt(){
  return CDCU_DrvSt_RollCnt_;
}
/******************
signalname: CDCU_MCU_ErrLevel;
signalclass: uint8;
StartBit: 52;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_ErrLevel(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_MCU_ErrLevel_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_ErrLevel(){
  return CDCU_MCU_ErrLevel_;
}
/******************
signalname: CDCU_MCU_GearAct;
signalclass: uint8;
StartBit: 2;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_GearAct(){
  int16_t x0 = GetByte(data_ + 0,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_MCU_GearAct_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_GearAct(){
  return CDCU_MCU_GearAct_;
}
/******************
signalname: CDCU_MCU_MtrCurt;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 6553.5;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_MtrCurt(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  CDCU_MCU_MtrCurt_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_MtrCurt(){
  return CDCU_MCU_MtrCurt_;
}
/******************
signalname: CDCU_MCU_MtrSpd;
signalclass: uint16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 65535;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_MtrSpd(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_MCU_MtrSpd_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_MtrSpd(){
  return CDCU_MCU_MtrSpd_;
}
/******************
signalname: CDCU_MCU_RunDir;
signalclass: uint8;
StartBit: 0;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_RunDir(){
  int16_t x0 = GetByte(data_ + 0,0,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_MCU_RunDir_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_RunDir(){
  return CDCU_MCU_RunDir_;
}
/******************
signalname: CDCU_MCU_ThrotAct;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_ThrotAct(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  double ret = x0 * 0.4000000000 + 0.0000000000;
  CDCU_MCU_ThrotAct_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_ThrotAct(){
  return CDCU_MCU_ThrotAct_;
}
/******************
signalname: CDCU_MCU_WorkMode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_DriveStatus::UpdateCDCU_MCU_WorkMode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_MCU_WorkMode_ = ret;
}
double CDCU_DriveStatus::CDCU_MCU_WorkMode(){
  return CDCU_MCU_WorkMode_;
}
