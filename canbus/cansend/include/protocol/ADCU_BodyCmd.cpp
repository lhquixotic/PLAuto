#include "ADCU_BodyCmd.h" 
ADCU_BodyCmd::ADCU_BodyCmd(){
  id_ = 0x115;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ADCU_BodyCmd::Reset(){
  ADCU_BackLamp_Cmd_=0;
  ADCU_BrkLamp_Cmd_=0;
  ADCU_Buzzer_Cmd_=0;
  ADCU_DblFlashLamp_Cmd_=0;
  ADCU_FogLamp_Cmd_=0;
  ADCU_HeadLamp_Cmd_=0;
  ADCU_Horn_Cmd_=0;
  ADCU_LampCmd_Active_=0;
  ADCU_LampCmd_Checksum_=0;
  ADCU_LampCmd_RollCnt_=0;
  ADCU_RunLamp_Cmd_=0;
  ADCU_TurnLLamp_Cmd_=0;
  ADCU_TurnRLamp_Cmd_=0;
  ADCU_WidthLamp_Cmd_=0;
}
void ADCU_BodyCmd::Update(uint8_t *data){
  Set_p_ADCU_BackLamp_Cmd(ADCU_BackLamp_Cmd_);
  Set_p_ADCU_BrkLamp_Cmd(ADCU_BrkLamp_Cmd_);
  Set_p_ADCU_Buzzer_Cmd(ADCU_Buzzer_Cmd_);
  Set_p_ADCU_DblFlashLamp_Cmd(ADCU_DblFlashLamp_Cmd_);
  Set_p_ADCU_FogLamp_Cmd(ADCU_FogLamp_Cmd_);
  Set_p_ADCU_HeadLamp_Cmd(ADCU_HeadLamp_Cmd_);
  Set_p_ADCU_Horn_Cmd(ADCU_Horn_Cmd_);
  Set_p_ADCU_LampCmd_Active(ADCU_LampCmd_Active_);
  Set_p_ADCU_LampCmd_RollCnt(ADCU_LampCmd_RollCnt_);
  Set_p_ADCU_RunLamp_Cmd(ADCU_RunLamp_Cmd_);
  Set_p_ADCU_TurnLLamp_Cmd(ADCU_TurnLLamp_Cmd_);
  Set_p_ADCU_TurnRLamp_Cmd(ADCU_TurnRLamp_Cmd_);
  Set_p_ADCU_WidthLamp_Cmd(ADCU_WidthLamp_Cmd_);
   Set_p_ADCU_LampCmd_Checksum(ADCU_LampCmd_Checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ADCU_BackLamp_Cmd;
signalclass: uint8;
StartBit: 11;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_BackLamp_Cmd(double ADCU_BackLamp_Cmd){
  ADCU_BackLamp_Cmd_=ADCU_BackLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_BackLamp_Cmd(double ADCU_BackLamp_Cmd){
  ADCU_BackLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_BackLamp_Cmd);
  int x = (ADCU_BackLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,3,1,x0);
}
/******************
signalname: ADCU_BrkLamp_Cmd;
signalclass: uint8;
StartBit: 23;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_BrkLamp_Cmd(double ADCU_BrkLamp_Cmd){
  ADCU_BrkLamp_Cmd_=ADCU_BrkLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_BrkLamp_Cmd(double ADCU_BrkLamp_Cmd){
  ADCU_BrkLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_BrkLamp_Cmd);
  int x = (ADCU_BrkLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 2,7,1,x0);
}
/******************
signalname: ADCU_Buzzer_Cmd;
signalclass: uint8;
StartBit: 10;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_Buzzer_Cmd(double ADCU_Buzzer_Cmd){
  ADCU_Buzzer_Cmd_=ADCU_Buzzer_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_Buzzer_Cmd(double ADCU_Buzzer_Cmd){
  ADCU_Buzzer_Cmd=BoundedValue(0.000000,1.000000,ADCU_Buzzer_Cmd);
  int x = (ADCU_Buzzer_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,2,1,x0);
}
/******************
signalname: ADCU_DblFlashLamp_Cmd;
signalclass: uint8;
StartBit: 14;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_DblFlashLamp_Cmd(double ADCU_DblFlashLamp_Cmd){
  ADCU_DblFlashLamp_Cmd_=ADCU_DblFlashLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_DblFlashLamp_Cmd(double ADCU_DblFlashLamp_Cmd){
  ADCU_DblFlashLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_DblFlashLamp_Cmd);
  int x = (ADCU_DblFlashLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,6,1,x0);
}
/******************
signalname: ADCU_FogLamp_Cmd;
signalclass: uint8;
StartBit: 22;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_FogLamp_Cmd(double ADCU_FogLamp_Cmd){
  ADCU_FogLamp_Cmd_=ADCU_FogLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_FogLamp_Cmd(double ADCU_FogLamp_Cmd){
  ADCU_FogLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_FogLamp_Cmd);
  int x = (ADCU_FogLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 2,6,1,x0);
}
/******************
signalname: ADCU_HeadLamp_Cmd;
signalclass: uint8;
StartBit: 15;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_HeadLamp_Cmd(double ADCU_HeadLamp_Cmd){
  ADCU_HeadLamp_Cmd_=ADCU_HeadLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_HeadLamp_Cmd(double ADCU_HeadLamp_Cmd){
  ADCU_HeadLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_HeadLamp_Cmd);
  int x = (ADCU_HeadLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,7,1,x0);
}
/******************
signalname: ADCU_Horn_Cmd;
signalclass: uint8;
StartBit: 9;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_Horn_Cmd(double ADCU_Horn_Cmd){
  ADCU_Horn_Cmd_=ADCU_Horn_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_Horn_Cmd(double ADCU_Horn_Cmd){
  ADCU_Horn_Cmd=BoundedValue(0.000000,1.000000,ADCU_Horn_Cmd);
  int x = (ADCU_Horn_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,1,1,x0);
}
/******************
signalname: ADCU_LampCmd_Active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_LampCmd_Active(double ADCU_LampCmd_Active){
  ADCU_LampCmd_Active_=ADCU_LampCmd_Active;
}
void ADCU_BodyCmd::Set_p_ADCU_LampCmd_Active(double ADCU_LampCmd_Active){
  ADCU_LampCmd_Active=BoundedValue(0.000000,1.000000,ADCU_LampCmd_Active);
  int x = (ADCU_LampCmd_Active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: ADCU_LampCmd_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ADCU_BodyCmd::SetADCU_LampCmd_Checksum(double ADCU_LampCmd_Checksum){
  ADCU_LampCmd_Checksum_=ADCU_LampCmd_Checksum;
}
void ADCU_BodyCmd::Set_p_ADCU_LampCmd_Checksum(double ADCU_LampCmd_Checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: ADCU_LampCmd_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ADCU_BodyCmd::SetADCU_LampCmd_RollCnt(double ADCU_LampCmd_RollCnt){
  ADCU_LampCmd_RollCnt_=ADCU_LampCmd_RollCnt;
}
void ADCU_BodyCmd::Set_p_ADCU_LampCmd_RollCnt(double ADCU_LampCmd_RollCnt){
  ADCU_LampCmd_RollCnt=BoundedValue(0.000000,15.000000,ADCU_LampCmd_RollCnt);
  int x = (ADCU_LampCmd_RollCnt - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: ADCU_RunLamp_Cmd;
signalclass: uint8;
StartBit: 8;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_RunLamp_Cmd(double ADCU_RunLamp_Cmd){
  ADCU_RunLamp_Cmd_=ADCU_RunLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_RunLamp_Cmd(double ADCU_RunLamp_Cmd){
  ADCU_RunLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_RunLamp_Cmd);
  int x = (ADCU_RunLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,0,1,x0);
}
/******************
signalname: ADCU_TurnLLamp_Cmd;
signalclass: uint8;
StartBit: 13;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_TurnLLamp_Cmd(double ADCU_TurnLLamp_Cmd){
  ADCU_TurnLLamp_Cmd_=ADCU_TurnLLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_TurnLLamp_Cmd(double ADCU_TurnLLamp_Cmd){
  ADCU_TurnLLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_TurnLLamp_Cmd);
  int x = (ADCU_TurnLLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,5,1,x0);
}
/******************
signalname: ADCU_TurnRLamp_Cmd;
signalclass: uint8;
StartBit: 12;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_TurnRLamp_Cmd(double ADCU_TurnRLamp_Cmd){
  ADCU_TurnRLamp_Cmd_=ADCU_TurnRLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_TurnRLamp_Cmd(double ADCU_TurnRLamp_Cmd){
  ADCU_TurnRLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_TurnRLamp_Cmd);
  int x = (ADCU_TurnRLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,4,1,x0);
}
/******************
signalname: ADCU_WidthLamp_Cmd;
signalclass: uint8;
StartBit: 21;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_BodyCmd::SetADCU_WidthLamp_Cmd(double ADCU_WidthLamp_Cmd){
  ADCU_WidthLamp_Cmd_=ADCU_WidthLamp_Cmd;
}
void ADCU_BodyCmd::Set_p_ADCU_WidthLamp_Cmd(double ADCU_WidthLamp_Cmd){
  ADCU_WidthLamp_Cmd=BoundedValue(0.000000,1.000000,ADCU_WidthLamp_Cmd);
  int x = (ADCU_WidthLamp_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 2,5,1,x0);
}
