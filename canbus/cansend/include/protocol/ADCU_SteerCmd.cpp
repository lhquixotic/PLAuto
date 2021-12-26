#include "ADCU_SteerCmd.h" 
ADCU_SteerCmd::ADCU_SteerCmd(){
  id_ = 0x113;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ADCU_SteerCmd::Reset(){
  ADCU_StrCmd_Checksum_=0;
  ADCU_StrCmd_RollCnt_=0;
  ADCU_Str_Active_=0;
  ADCU_Str_CtrlMode_=0;
  ADCU_Str_TgtAngle_=0;
  ADCU_Str_TgtAngleSpd_=0;
  ADCU_Str_TgtCurvature_=0;
}
void ADCU_SteerCmd::Update(uint8_t *data){
  Set_p_ADCU_StrCmd_RollCnt(ADCU_StrCmd_RollCnt_);
  Set_p_ADCU_Str_Active(ADCU_Str_Active_);
  Set_p_ADCU_Str_CtrlMode(ADCU_Str_CtrlMode_);
  Set_p_ADCU_Str_TgtAngle(ADCU_Str_TgtAngle_);
  Set_p_ADCU_Str_TgtAngleSpd(ADCU_Str_TgtAngleSpd_);
  Set_p_ADCU_Str_TgtCurvature(ADCU_Str_TgtCurvature_);
  Set_p_ADCU_StrCmd_Checksum(ADCU_StrCmd_Checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ADCU_StrCmd_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ADCU_SteerCmd::SetADCU_StrCmd_Checksum(double ADCU_StrCmd_Checksum){
  ADCU_StrCmd_Checksum_=ADCU_StrCmd_Checksum;
}
void ADCU_SteerCmd::Set_p_ADCU_StrCmd_Checksum(double ADCU_StrCmd_Checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: ADCU_StrCmd_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ADCU_SteerCmd::SetADCU_StrCmd_RollCnt(double ADCU_StrCmd_RollCnt){
  ADCU_StrCmd_RollCnt_=ADCU_StrCmd_RollCnt;
}
void ADCU_SteerCmd::Set_p_ADCU_StrCmd_RollCnt(double ADCU_StrCmd_RollCnt){
  ADCU_StrCmd_RollCnt=BoundedValue(0.000000,15.000000,ADCU_StrCmd_RollCnt);
  int x = (ADCU_StrCmd_RollCnt - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: ADCU_Str_Active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_SteerCmd::SetADCU_Str_Active(double ADCU_Str_Active){
  ADCU_Str_Active_=ADCU_Str_Active;
}
void ADCU_SteerCmd::Set_p_ADCU_Str_Active(double ADCU_Str_Active){
  ADCU_Str_Active=BoundedValue(0.000000,1.000000,ADCU_Str_Active);
  int x = (ADCU_Str_Active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: ADCU_Str_CtrlMode;
signalclass: uint8;
StartBit: 5;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_SteerCmd::SetADCU_Str_CtrlMode(double ADCU_Str_CtrlMode){
  ADCU_Str_CtrlMode_=ADCU_Str_CtrlMode;
}
void ADCU_SteerCmd::Set_p_ADCU_Str_CtrlMode(double ADCU_Str_CtrlMode){
  ADCU_Str_CtrlMode=BoundedValue(0.000000,3.000000,ADCU_Str_CtrlMode);
  int x = (ADCU_Str_CtrlMode - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,5,2,x0);
}
/******************
signalname: ADCU_Str_TgtAngle;
signalclass: uint16;
StartBit: 16;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.005;
Offset: -90;
Minimum: -90;
Maximum: 237.675;
******************/
void ADCU_SteerCmd::SetADCU_Str_TgtAngle(double ADCU_Str_TgtAngle){
  ADCU_Str_TgtAngle_=ADCU_Str_TgtAngle;
}
void ADCU_SteerCmd::Set_p_ADCU_Str_TgtAngle(double ADCU_Str_TgtAngle){
  ADCU_Str_TgtAngle=BoundedValue(-90.000000,237.675000,ADCU_Str_TgtAngle);
  int x = (ADCU_Str_TgtAngle - -90.000000) / 0.005000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x1);
}
/******************
signalname: ADCU_Str_TgtAngleSpd;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.2;
Offset: 0;
Minimum: 0;
Maximum: 51;
******************/
void ADCU_SteerCmd::SetADCU_Str_TgtAngleSpd(double ADCU_Str_TgtAngleSpd){
  ADCU_Str_TgtAngleSpd_=ADCU_Str_TgtAngleSpd;
}
void ADCU_SteerCmd::Set_p_ADCU_Str_TgtAngleSpd(double ADCU_Str_TgtAngleSpd){
  ADCU_Str_TgtAngleSpd=BoundedValue(0.000000,51.000000,ADCU_Str_TgtAngleSpd);
  int x = (ADCU_Str_TgtAngleSpd - 0.000000) / 0.200000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 5,0,8,x0);
}
/******************
signalname: ADCU_Str_TgtCurvature;
signalclass: uint16;
StartBit: 32;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0001;
Offset: -3;
Minimum: -3;
Maximum: 3.5535;
******************/
void ADCU_SteerCmd::SetADCU_Str_TgtCurvature(double ADCU_Str_TgtCurvature){
  ADCU_Str_TgtCurvature_=ADCU_Str_TgtCurvature;
}
void ADCU_SteerCmd::Set_p_ADCU_Str_TgtCurvature(double ADCU_Str_TgtCurvature){
  ADCU_Str_TgtCurvature=BoundedValue(-3.000000,3.553500,ADCU_Str_TgtCurvature);
  int x = (ADCU_Str_TgtCurvature - -3.000000) / 0.000100;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 4,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 3,0,8,x1);
}
