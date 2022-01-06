#include "CDCU_ParkStatus.h"
CDCU_ParkStatus::CDCU_ParkStatus(){
  id_ = 0x213;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_Park_Checksum_=0;
  CDCU_Park_ErrLevel_=0;
  CDCU_Park_RollCnt_=0;
  CDCU_Park_St_=0;
  CDCU_Park_WorkMode_=0;
}
void CDCU_ParkStatus::Reset(){
  CDCU_Park_Checksum_=0;
  CDCU_Park_ErrLevel_=0;
  CDCU_Park_RollCnt_=0;
  CDCU_Park_St_=0;
  CDCU_Park_WorkMode_=0;
}
void CDCU_ParkStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_Park_Checksum();
  UpdateCDCU_Park_ErrLevel();
  UpdateCDCU_Park_RollCnt();
  UpdateCDCU_Park_St();
  UpdateCDCU_Park_WorkMode();
}
/******************
signalname: CDCU_Park_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_ParkStatus::UpdateCDCU_Park_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Park_Checksum_ = ret;
}
double CDCU_ParkStatus::CDCU_Park_Checksum(){
  return CDCU_Park_Checksum_;
}
/******************
signalname: CDCU_Park_ErrLevel;
signalclass: uint8;
StartBit: 52;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_ParkStatus::UpdateCDCU_Park_ErrLevel(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Park_ErrLevel_ = ret;
}
double CDCU_ParkStatus::CDCU_Park_ErrLevel(){
  return CDCU_Park_ErrLevel_;
}
/******************
signalname: CDCU_Park_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_ParkStatus::UpdateCDCU_Park_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Park_RollCnt_ = ret;
}
double CDCU_ParkStatus::CDCU_Park_RollCnt(){
  return CDCU_Park_RollCnt_;
}
/******************
signalname: CDCU_Park_St;
signalclass: uint8;
StartBit: 2;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_ParkStatus::UpdateCDCU_Park_St(){
  int16_t x0 = GetByte(data_ + 0,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Park_St_ = ret;
}
double CDCU_ParkStatus::CDCU_Park_St(){
  return CDCU_Park_St_;
}
/******************
signalname: CDCU_Park_WorkMode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_ParkStatus::UpdateCDCU_Park_WorkMode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Park_WorkMode_ = ret;
}
double CDCU_ParkStatus::CDCU_Park_WorkMode(){
  return CDCU_Park_WorkMode_;
}
