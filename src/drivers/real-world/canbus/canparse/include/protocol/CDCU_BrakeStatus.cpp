#include "CDCU_BrakeStatus.h"
CDCU_BrakeStatus::CDCU_BrakeStatus(){
  id_ = 0x211;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_BrkSt_Checksum_=0;
  CDCU_BrkSt_RollCnt_=0;
  CDCU_EHB_BrkMode_=0;
  CDCU_EHB_BrkPedpos_=0;
  CDCU_EHB_BrkPresur_=0;
  CDCU_EHB_ErrLevel_=0;
  CDCU_EHB_WorkMode_=0;
}
void CDCU_BrakeStatus::Reset(){
  CDCU_BrkSt_Checksum_=0;
  CDCU_BrkSt_RollCnt_=0;
  CDCU_EHB_BrkMode_=0;
  CDCU_EHB_BrkPedpos_=0;
  CDCU_EHB_BrkPresur_=0;
  CDCU_EHB_ErrLevel_=0;
  CDCU_EHB_WorkMode_=0;
}
void CDCU_BrakeStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_BrkSt_Checksum();
  UpdateCDCU_BrkSt_RollCnt();
  UpdateCDCU_EHB_BrkMode();
  UpdateCDCU_EHB_BrkPedpos();
  UpdateCDCU_EHB_BrkPresur();
  UpdateCDCU_EHB_ErrLevel();
  UpdateCDCU_EHB_WorkMode();
}
/******************
signalname: CDCU_BrkSt_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_BrakeStatus::UpdateCDCU_BrkSt_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BrkSt_Checksum_ = ret;
}
double CDCU_BrakeStatus::CDCU_BrkSt_Checksum(){
  return CDCU_BrkSt_Checksum_;
}
/******************
signalname: CDCU_BrkSt_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_BrakeStatus::UpdateCDCU_BrkSt_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BrkSt_RollCnt_ = ret;
}
double CDCU_BrakeStatus::CDCU_BrkSt_RollCnt(){
  return CDCU_BrkSt_RollCnt_;
}
/******************
signalname: CDCU_EHB_BrkMode;
signalclass: uint8;
StartBit: 2;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_BrakeStatus::UpdateCDCU_EHB_BrkMode(){
  int16_t x0 = GetByte(data_ + 0,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EHB_BrkMode_ = ret;
}
double CDCU_BrakeStatus::CDCU_EHB_BrkMode(){
  return CDCU_EHB_BrkMode_;
}
/******************
signalname: CDCU_EHB_BrkPedpos;
signalclass: uint8;
StartBit: 16;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void CDCU_BrakeStatus::UpdateCDCU_EHB_BrkPedpos(){
  int16_t x0 = GetByte(data_ + 2,0,8);
  x0<<=0;
  double ret = x0 * 0.4000000000 + 0.0000000000;
  CDCU_EHB_BrkPedpos_ = ret;
}
double CDCU_BrakeStatus::CDCU_EHB_BrkPedpos(){
  return CDCU_EHB_BrkPedpos_;
}
/******************
signalname: CDCU_EHB_BrkPresur;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_BrakeStatus::UpdateCDCU_EHB_BrkPresur(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EHB_BrkPresur_ = ret;
}
double CDCU_BrakeStatus::CDCU_EHB_BrkPresur(){
  return CDCU_EHB_BrkPresur_;
}
/******************
signalname: CDCU_EHB_ErrLevel;
signalclass: uint8;
StartBit: 52;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_BrakeStatus::UpdateCDCU_EHB_ErrLevel(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EHB_ErrLevel_ = ret;
}
double CDCU_BrakeStatus::CDCU_EHB_ErrLevel(){
  return CDCU_EHB_ErrLevel_;
}
/******************
signalname: CDCU_EHB_WorkMode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_BrakeStatus::UpdateCDCU_EHB_WorkMode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EHB_WorkMode_ = ret;
}
double CDCU_BrakeStatus::CDCU_EHB_WorkMode(){
  return CDCU_EHB_WorkMode_;
}
