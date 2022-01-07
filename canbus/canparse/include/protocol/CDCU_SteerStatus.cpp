#include "CDCU_SteerStatus.h"
CDCU_SteerStatus::CDCU_SteerStatus(){
  id_ = 0x215;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_EPS_ErrLevel_=0;
  CDCU_EPS_StrTrq_=0;
  CDCU_EPS_StrWhlAngle_=0;
  CDCU_EPS_WhlSpd_=0;
  CDCU_EPS_WorkMode_=0;
  CDCU_StrSt_Checksum_=0;
  CDCU_StrSt_RollCnt_=0;
}
void CDCU_SteerStatus::Reset(){
  CDCU_EPS_ErrLevel_=0;
  CDCU_EPS_StrTrq_=0;
  CDCU_EPS_StrWhlAngle_=0;
  CDCU_EPS_WhlSpd_=0;
  CDCU_EPS_WorkMode_=0;
  CDCU_StrSt_Checksum_=0;
  CDCU_StrSt_RollCnt_=0;
}
void CDCU_SteerStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_EPS_ErrLevel();
  UpdateCDCU_EPS_StrTrq();
  UpdateCDCU_EPS_StrWhlAngle();
  UpdateCDCU_EPS_WhlSpd();
  UpdateCDCU_EPS_WorkMode();
  UpdateCDCU_StrSt_Checksum();
  UpdateCDCU_StrSt_RollCnt();
}
/******************
signalname: CDCU_EPS_ErrLevel;
signalclass: uint8;
StartBit: 52;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_SteerStatus::UpdateCDCU_EPS_ErrLevel(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EPS_ErrLevel_ = ret;
}
double CDCU_SteerStatus::CDCU_EPS_ErrLevel(){
  return CDCU_EPS_ErrLevel_;
}
/******************
signalname: CDCU_EPS_StrTrq;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: -12.8;
Minimum: -12.8;
Maximum: 12.7;
******************/
void CDCU_SteerStatus::UpdateCDCU_EPS_StrTrq(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  double ret = x0 * 0.1000000000 + -12.8000000000;
  CDCU_EPS_StrTrq_ = ret;
}
double CDCU_SteerStatus::CDCU_EPS_StrTrq(){
  return CDCU_EPS_StrTrq_;
}
/******************
signalname: CDCU_EPS_StrWhlAngle;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.005;
Offset: -90;
Minimum: -90;
Maximum: 237.675;
******************/
void CDCU_SteerStatus::UpdateCDCU_EPS_StrWhlAngle(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0050000000 + -90.0000000000;
  CDCU_EPS_StrWhlAngle_ = ret;
}
double CDCU_SteerStatus::CDCU_EPS_StrWhlAngle(){
  return CDCU_EPS_StrWhlAngle_;
}
/******************
signalname: CDCU_EPS_WhlSpd;
signalclass: uint16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: -180;
Minimum: -180;
Maximum: 475.35;
******************/
void CDCU_SteerStatus::UpdateCDCU_EPS_WhlSpd(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0100000000 + -180.0000000000;
  CDCU_EPS_WhlSpd_ = ret;
}
double CDCU_SteerStatus::CDCU_EPS_WhlSpd(){
  return CDCU_EPS_WhlSpd_;
}
/******************
signalname: CDCU_EPS_WorkMode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_SteerStatus::UpdateCDCU_EPS_WorkMode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EPS_WorkMode_ = ret;
}
double CDCU_SteerStatus::CDCU_EPS_WorkMode(){
  return CDCU_EPS_WorkMode_;
}
/******************
signalname: CDCU_StrSt_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_SteerStatus::UpdateCDCU_StrSt_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_StrSt_Checksum_ = ret;
}
double CDCU_SteerStatus::CDCU_StrSt_Checksum(){
  return CDCU_StrSt_Checksum_;
}
/******************
signalname: CDCU_StrSt_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_SteerStatus::UpdateCDCU_StrSt_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_StrSt_RollCnt_ = ret;
}
double CDCU_SteerStatus::CDCU_StrSt_RollCnt(){
  return CDCU_StrSt_RollCnt_;
}
