#include "CDCU_VehDyncState.h"
CDCU_VehDyncState::CDCU_VehDyncState(){
  id_ = 0x250;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_VehDync_Checksum_=0;
  CDCU_VehDync_RollCnt_=0;
  CDCU_Veh_Curvture_=0;
  CDCU_Veh_LongtdnalAccSpd_=0;
  CDCU_Veh_LongtdnalSpd_=0;
  CDCU_Veh_RunDir_=0;
}
void CDCU_VehDyncState::Reset(){
  CDCU_VehDync_Checksum_=0;
  CDCU_VehDync_RollCnt_=0;
  CDCU_Veh_Curvture_=0;
  CDCU_Veh_LongtdnalAccSpd_=0;
  CDCU_Veh_LongtdnalSpd_=0;
  CDCU_Veh_RunDir_=0;
}
void CDCU_VehDyncState::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_VehDync_Checksum();
  UpdateCDCU_VehDync_RollCnt();
  UpdateCDCU_Veh_Curvture();
  UpdateCDCU_Veh_LongtdnalAccSpd();
  UpdateCDCU_Veh_LongtdnalSpd();
  UpdateCDCU_Veh_RunDir();
}
/******************
signalname: CDCU_VehDync_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_VehDyncState::UpdateCDCU_VehDync_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehDync_Checksum_ = ret;
}
double CDCU_VehDyncState::CDCU_VehDync_Checksum(){
  return CDCU_VehDync_Checksum_;
}
/******************
signalname: CDCU_VehDync_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_VehDyncState::UpdateCDCU_VehDync_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehDync_RollCnt_ = ret;
}
double CDCU_VehDyncState::CDCU_VehDync_RollCnt(){
  return CDCU_VehDync_RollCnt_;
}
/******************
signalname: CDCU_Veh_Curvture;
signalclass: uint16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0001;
Offset: -3;
Minimum: -3;
Maximum: 3.5535;
******************/
void CDCU_VehDyncState::UpdateCDCU_Veh_Curvture(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0001000000 + -3.0000000000;
  CDCU_Veh_Curvture_ = ret;
}
double CDCU_VehDyncState::CDCU_Veh_Curvture(){
  return CDCU_Veh_Curvture_;
}
/******************
signalname: CDCU_Veh_LongtdnalAccSpd;
signalclass: uint16;
StartBit: 8;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: -40;
Minimum: -40;
Maximum: 615.35;
******************/
void CDCU_VehDyncState::UpdateCDCU_Veh_LongtdnalAccSpd(){
  int32_t x0 = GetByte(data_ + 1,0,8);
  int32_t x1 = GetByte(data_ + 0,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0100000000 + -40.0000000000;
  CDCU_Veh_LongtdnalAccSpd_ = ret;
}
double CDCU_VehDyncState::CDCU_Veh_LongtdnalAccSpd(){
  return CDCU_Veh_LongtdnalAccSpd_;
}
/******************
signalname: CDCU_Veh_LongtdnalSpd;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0039063;
Offset: 0;
Minimum: 0;
Maximum: 255.9961;
******************/
void CDCU_VehDyncState::UpdateCDCU_Veh_LongtdnalSpd(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0039062500 + 0.0000000000;
  CDCU_Veh_LongtdnalSpd_ = ret;
}
double CDCU_VehDyncState::CDCU_Veh_LongtdnalSpd(){
  return CDCU_Veh_LongtdnalSpd_;
}
/******************
signalname: CDCU_Veh_RunDir;
signalclass: uint8;
StartBit: 54;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehDyncState::UpdateCDCU_Veh_RunDir(){
  int16_t x0 = GetByte(data_ + 6,6,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Veh_RunDir_ = ret;
}
double CDCU_VehDyncState::CDCU_Veh_RunDir(){
  return CDCU_Veh_RunDir_;
}
