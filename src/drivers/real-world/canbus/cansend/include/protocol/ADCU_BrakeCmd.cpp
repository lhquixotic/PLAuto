#include "ADCU_BrakeCmd.h" 
ADCU_BrakeCmd::ADCU_BrakeCmd(){
  id_ = 0x111;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ADCU_BrakeCmd::Reset(){
  ADCU_BrkCmd_Checksum_=0;
  ADCU_BrkCmd_RollCnt_=0;
  ADCU_Brk_Active_=0;
  ADCU_Brk_CtrlMode_=0;
  ADCU_Brk_TgtAccSpd_=0;
  ADCU_Brk_TgtPedpos_=0;
  ADCU_Brk_TgtPress_=0;
}
void ADCU_BrakeCmd::Update(uint8_t *data){
  Set_p_ADCU_BrkCmd_RollCnt(ADCU_BrkCmd_RollCnt_);
  Set_p_ADCU_Brk_Active(ADCU_Brk_Active_);
  Set_p_ADCU_Brk_CtrlMode(ADCU_Brk_CtrlMode_);
  Set_p_ADCU_Brk_TgtAccSpd(ADCU_Brk_TgtAccSpd_);
  Set_p_ADCU_Brk_TgtPedpos(ADCU_Brk_TgtPedpos_);
  Set_p_ADCU_Brk_TgtPress(ADCU_Brk_TgtPress_);
   Set_p_ADCU_BrkCmd_Checksum(ADCU_BrkCmd_Checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ADCU_BrkCmd_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ADCU_BrakeCmd::SetADCU_BrkCmd_Checksum(double ADCU_BrkCmd_Checksum){
  ADCU_BrkCmd_Checksum_=ADCU_BrkCmd_Checksum;
}
void ADCU_BrakeCmd::Set_p_ADCU_BrkCmd_Checksum(double ADCU_BrkCmd_Checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: ADCU_BrkCmd_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ADCU_BrakeCmd::SetADCU_BrkCmd_RollCnt(double ADCU_BrkCmd_RollCnt){
  ADCU_BrkCmd_RollCnt_=ADCU_BrkCmd_RollCnt;
}
void ADCU_BrakeCmd::Set_p_ADCU_BrkCmd_RollCnt(double ADCU_BrkCmd_RollCnt){
  ADCU_BrkCmd_RollCnt=BoundedValue(0.000000,15.000000,ADCU_BrkCmd_RollCnt);
  int x = (ADCU_BrkCmd_RollCnt - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: ADCU_Brk_Active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BrakeCmd::SetADCU_Brk_Active(double ADCU_Brk_Active){
  ADCU_Brk_Active_=ADCU_Brk_Active;
}
void ADCU_BrakeCmd::Set_p_ADCU_Brk_Active(double ADCU_Brk_Active){
  ADCU_Brk_Active=BoundedValue(0.000000,1.000000,ADCU_Brk_Active);
  int x = (ADCU_Brk_Active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: ADCU_Brk_CtrlMode;
signalclass: uint8;
StartBit: 5;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_BrakeCmd::SetADCU_Brk_CtrlMode(double ADCU_Brk_CtrlMode){
  ADCU_Brk_CtrlMode_=ADCU_Brk_CtrlMode;
}
void ADCU_BrakeCmd::Set_p_ADCU_Brk_CtrlMode(double ADCU_Brk_CtrlMode){
  ADCU_Brk_CtrlMode=BoundedValue(0.000000,3.000000,ADCU_Brk_CtrlMode);
  int x = (ADCU_Brk_CtrlMode - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,5,2,x0);
}
/******************
signalname: ADCU_Brk_TgtAccSpd;
signalclass: uint16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: -20;
Minimum: -20;
Maximum: 635.35;
******************/
void ADCU_BrakeCmd::SetADCU_Brk_TgtAccSpd(double ADCU_Brk_TgtAccSpd){
  ADCU_Brk_TgtAccSpd_=ADCU_Brk_TgtAccSpd;
}
void ADCU_BrakeCmd::Set_p_ADCU_Brk_TgtAccSpd(double ADCU_Brk_TgtAccSpd){
  ADCU_Brk_TgtAccSpd=BoundedValue(-20.000000,635.350000,ADCU_Brk_TgtAccSpd);
  int x = (ADCU_Brk_TgtAccSpd - -20.000000) / 0.010000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 5,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 4,0,8,x1);
}
/******************
signalname: ADCU_Brk_TgtPedpos;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void ADCU_BrakeCmd::SetADCU_Brk_TgtPedpos(double ADCU_Brk_TgtPedpos){
  ADCU_Brk_TgtPedpos_=ADCU_Brk_TgtPedpos;
}
void ADCU_BrakeCmd::Set_p_ADCU_Brk_TgtPedpos(double ADCU_Brk_TgtPedpos){
  ADCU_Brk_TgtPedpos=BoundedValue(0.000000,102.000000,ADCU_Brk_TgtPedpos);
  int x = (ADCU_Brk_TgtPedpos - 0.000000) / 0.400000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x0);
}
/******************
signalname: ADCU_Brk_TgtPress;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: 0;
Minimum: 0;
Maximum: 655.35;
******************/
void ADCU_BrakeCmd::SetADCU_Brk_TgtPress(double ADCU_Brk_TgtPress){
  ADCU_Brk_TgtPress_=ADCU_Brk_TgtPress;
}
void ADCU_BrakeCmd::Set_p_ADCU_Brk_TgtPress(double ADCU_Brk_TgtPress){
  ADCU_Brk_TgtPress=BoundedValue(0.000000,655.350000,ADCU_Brk_TgtPress);
  int x = (ADCU_Brk_TgtPress - 0.000000) / 0.010000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 3,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,0,8,x1);
}
