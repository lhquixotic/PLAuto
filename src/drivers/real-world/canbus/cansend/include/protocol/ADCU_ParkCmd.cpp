#include "ADCU_ParkCmd.h" 
ADCU_ParkCmd::ADCU_ParkCmd(){
  id_ = 0x112;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ADCU_ParkCmd::Reset(){
  ADCU_PrkCmd_Checksum_=0;
  ADCU_PrkCmd_RollCnt_=0;
  ADCU_Prk_Active_=0;
  ADCU_Prk_Enable_=0;
}
void ADCU_ParkCmd::Update(uint8_t *data){
  Set_p_ADCU_PrkCmd_RollCnt(ADCU_PrkCmd_RollCnt_);
  Set_p_ADCU_Prk_Active(ADCU_Prk_Active_);
  Set_p_ADCU_Prk_Enable(ADCU_Prk_Enable_); 
  Set_p_ADCU_PrkCmd_Checksum(ADCU_PrkCmd_Checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ADCU_PrkCmd_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ADCU_ParkCmd::SetADCU_PrkCmd_Checksum(double ADCU_PrkCmd_Checksum){
  ADCU_PrkCmd_Checksum_=ADCU_PrkCmd_Checksum;
}
void ADCU_ParkCmd::Set_p_ADCU_PrkCmd_Checksum(double ADCU_PrkCmd_Checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: ADCU_PrkCmd_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ADCU_ParkCmd::SetADCU_PrkCmd_RollCnt(double ADCU_PrkCmd_RollCnt){
  ADCU_PrkCmd_RollCnt_=ADCU_PrkCmd_RollCnt;
}
void ADCU_ParkCmd::Set_p_ADCU_PrkCmd_RollCnt(double ADCU_PrkCmd_RollCnt){
  ADCU_PrkCmd_RollCnt=BoundedValue(0.000000,15.000000,ADCU_PrkCmd_RollCnt);
  int x = (ADCU_PrkCmd_RollCnt - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: ADCU_Prk_Active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_ParkCmd::SetADCU_Prk_Active(double ADCU_Prk_Active){
  ADCU_Prk_Active_=ADCU_Prk_Active;
}
void ADCU_ParkCmd::Set_p_ADCU_Prk_Active(double ADCU_Prk_Active){
  ADCU_Prk_Active=BoundedValue(0.000000,1.000000,ADCU_Prk_Active);
  int x = (ADCU_Prk_Active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: ADCU_Prk_Enable;
signalclass: uint8;
StartBit: 6;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_ParkCmd::SetADCU_Prk_Enable(double ADCU_Prk_Enable){
  ADCU_Prk_Enable_=ADCU_Prk_Enable;
}
void ADCU_ParkCmd::Set_p_ADCU_Prk_Enable(double ADCU_Prk_Enable){
  ADCU_Prk_Enable=BoundedValue(0.000000,1.000000,ADCU_Prk_Enable);
  int x = (ADCU_Prk_Enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,6,1,x0);
}
