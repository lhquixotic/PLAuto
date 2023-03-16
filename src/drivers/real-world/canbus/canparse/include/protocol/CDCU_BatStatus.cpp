#include "CDCU_BatStatus.h"
CDCU_BatStatus::CDCU_BatStatus(){
  id_ = 0x222;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_BMS_BatCurt_=0;
  CDCU_BMS_BatSOC_=0;
  CDCU_BMS_BatSOH_=0;
  CDCU_BMS_BatTemp_=0;
  CDCU_BMS_BatVolt_=0;
  CDCU_BMS_ChgSt_=0;
  CDCU_BMS_DisChgSt_=0;
  CDCU_BMS_FeedBackSt_=0;
  CDCU_BatInfo_Checksum_=0;
  CDCU_BatInfo_RollCnt_=0;
  CDCU_LvBat_Volt_=0;
}
void CDCU_BatStatus::Reset(){
  CDCU_BMS_BatCurt_=0;
  CDCU_BMS_BatSOC_=0;
  CDCU_BMS_BatSOH_=0;
  CDCU_BMS_BatTemp_=0;
  CDCU_BMS_BatVolt_=0;
  CDCU_BMS_ChgSt_=0;
  CDCU_BMS_DisChgSt_=0;
  CDCU_BMS_FeedBackSt_=0;
  CDCU_BatInfo_Checksum_=0;
  CDCU_BatInfo_RollCnt_=0;
  CDCU_LvBat_Volt_=0;
}
void CDCU_BatStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_BMS_BatCurt();
  UpdateCDCU_BMS_BatSOC();
  UpdateCDCU_BMS_BatSOH();
  UpdateCDCU_BMS_BatTemp();
  UpdateCDCU_BMS_BatVolt();
  UpdateCDCU_BMS_ChgSt();
  UpdateCDCU_BMS_DisChgSt();
  UpdateCDCU_BMS_FeedBackSt();
  UpdateCDCU_BatInfo_Checksum();
  UpdateCDCU_BatInfo_RollCnt();
  UpdateCDCU_LvBat_Volt();
}
/******************
signalname: CDCU_BMS_BatCurt;
signalclass: uint8;
StartBit: 32;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_BatCurt(){
  int16_t x0 = GetByte(data_ + 4,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BMS_BatCurt_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_BatCurt(){
  return CDCU_BMS_BatCurt_;
}
/******************
signalname: CDCU_BMS_BatSOC;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_BatSOC(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  double ret = x0 * 0.4000000000 + 0.0000000000;
  CDCU_BMS_BatSOC_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_BatSOC(){
  return CDCU_BMS_BatSOC_;
}
/******************
signalname: CDCU_BMS_BatSOH;
signalclass: uint8;
StartBit: 16;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_BatSOH(){
  int16_t x0 = GetByte(data_ + 2,0,8);
  x0<<=0;
  double ret = x0 * 0.4000000000 + 0.0000000000;
  CDCU_BMS_BatSOH_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_BatSOH(){
  return CDCU_BMS_BatSOH_;
}
/******************
signalname: CDCU_BMS_BatTemp;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: -50;
Minimum: -50;
Maximum: 205;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_BatTemp(){
  int16_t x0 = GetByte(data_ + 5,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + -50.0000000000;
  CDCU_BMS_BatTemp_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_BatTemp(){
  return CDCU_BMS_BatTemp_;
}
/******************
signalname: CDCU_BMS_BatVolt;
signalclass: uint8;
StartBit: 24;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_BatVolt(){
  int16_t x0 = GetByte(data_ + 3,0,8);
  x0<<=0;
  double ret = x0 * 0.4000000000 + 0.0000000000;
  CDCU_BMS_BatVolt_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_BatVolt(){
  return CDCU_BMS_BatVolt_;
}
/******************
signalname: CDCU_BMS_ChgSt;
signalclass: uint8;
StartBit: 55;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_ChgSt(){
  int16_t x0 = GetByte(data_ + 6,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BMS_ChgSt_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_ChgSt(){
  return CDCU_BMS_ChgSt_;
}
/******************
signalname: CDCU_BMS_DisChgSt;
signalclass: uint8;
StartBit: 54;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_DisChgSt(){
  int16_t x0 = GetByte(data_ + 6,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BMS_DisChgSt_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_DisChgSt(){
  return CDCU_BMS_DisChgSt_;
}
/******************
signalname: CDCU_BMS_FeedBackSt;
signalclass: uint8;
StartBit: 53;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BatStatus::UpdateCDCU_BMS_FeedBackSt(){
  int16_t x0 = GetByte(data_ + 6,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BMS_FeedBackSt_ = ret;
}
double CDCU_BatStatus::CDCU_BMS_FeedBackSt(){
  return CDCU_BMS_FeedBackSt_;
}
/******************
signalname: CDCU_BatInfo_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_BatStatus::UpdateCDCU_BatInfo_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BatInfo_Checksum_ = ret;
}
double CDCU_BatStatus::CDCU_BatInfo_Checksum(){
  return CDCU_BatInfo_Checksum_;
}
/******************
signalname: CDCU_BatInfo_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_BatStatus::UpdateCDCU_BatInfo_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BatInfo_RollCnt_ = ret;
}
double CDCU_BatStatus::CDCU_BatInfo_RollCnt(){
  return CDCU_BatInfo_RollCnt_;
}
/******************
signalname: CDCU_LvBat_Volt;
signalclass: uint8;
StartBit: 0;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 25.5;
******************/
void CDCU_BatStatus::UpdateCDCU_LvBat_Volt(){
  int16_t x0 = GetByte(data_ + 0,0,8);
  x0<<=0;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  CDCU_LvBat_Volt_ = ret;
}
double CDCU_BatStatus::CDCU_LvBat_Volt(){
  return CDCU_LvBat_Volt_;
}
