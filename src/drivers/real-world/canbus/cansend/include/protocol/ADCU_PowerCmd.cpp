#include "ADCU_PowerCmd.h" 
ADCU_PowerCmd::ADCU_PowerCmd(){
  id_ = 0x117;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ADCU_PowerCmd::Reset(){
  ADCU_AD12VMCPwrdownCnfm_Cmd_=0;
  ADCU_AD12VMCPwrup_Cmd_=0;
  ADCU_AD12VRCPwrdownCnfm_Cmd_=0;
  ADCU_AD12VRCPwrup_Cmd_=0;
  ADCU_AD12VSC1Pwrup_Cmd_=0;
  ADCU_AD12VSC2Pwrup_Cmd_=0;
  ADCU_AD12VSC3Pwrup_Cmd_=0;
  ADCU_AD12VSC4Pwrup_Cmd_=0;
  ADCU_AD12VSC5Pwrup_Cmd_=0;
  ADCU_AD12VSC6Pwrup_Cmd_=0;
  ADCU_AD24VMCPwrdownCnfm_Cmd_=0;
  ADCU_AD24VMCPwrup_Cmd_=0;
  ADCU_ADChasPwrup_Cmd_=0;
  ADCU_ADPA12VPwrdownCnfm_Cmd_=0;
  ADCU_ADPA12VPwrup_Cmd_=0;
  ADCU_ADPA24VPwrdownCnfm_Cmd_=0;
  ADCU_ADPA24VPwrup_Cmd_=0;
  ADCU_ADVehPwrup_Cmd_=0;
  ADCU_PwrCmd_Checksum_=0;
  ADCU_PwrCmd_RollCnt_=0;
}
void ADCU_PowerCmd::Update(uint8_t *data){
  Set_p_ADCU_AD12VMCPwrdownCnfm_Cmd(ADCU_AD12VMCPwrdownCnfm_Cmd_);
  Set_p_ADCU_AD12VMCPwrup_Cmd(ADCU_AD12VMCPwrup_Cmd_);
  Set_p_ADCU_AD12VRCPwrdownCnfm_Cmd(ADCU_AD12VRCPwrdownCnfm_Cmd_);
  Set_p_ADCU_AD12VRCPwrup_Cmd(ADCU_AD12VRCPwrup_Cmd_);
  Set_p_ADCU_AD12VSC1Pwrup_Cmd(ADCU_AD12VSC1Pwrup_Cmd_);
  Set_p_ADCU_AD12VSC2Pwrup_Cmd(ADCU_AD12VSC2Pwrup_Cmd_);
  Set_p_ADCU_AD12VSC3Pwrup_Cmd(ADCU_AD12VSC3Pwrup_Cmd_);
  Set_p_ADCU_AD12VSC4Pwrup_Cmd(ADCU_AD12VSC4Pwrup_Cmd_);
  Set_p_ADCU_AD12VSC5Pwrup_Cmd(ADCU_AD12VSC5Pwrup_Cmd_);
  Set_p_ADCU_AD12VSC6Pwrup_Cmd(ADCU_AD12VSC6Pwrup_Cmd_);
  Set_p_ADCU_AD24VMCPwrdownCnfm_Cmd(ADCU_AD24VMCPwrdownCnfm_Cmd_);
  Set_p_ADCU_AD24VMCPwrup_Cmd(ADCU_AD24VMCPwrup_Cmd_);
  Set_p_ADCU_ADChasPwrup_Cmd(ADCU_ADChasPwrup_Cmd_);
  Set_p_ADCU_ADPA12VPwrdownCnfm_Cmd(ADCU_ADPA12VPwrdownCnfm_Cmd_);
  Set_p_ADCU_ADPA12VPwrup_Cmd(ADCU_ADPA12VPwrup_Cmd_);
  Set_p_ADCU_ADPA24VPwrdownCnfm_Cmd(ADCU_ADPA24VPwrdownCnfm_Cmd_);
  Set_p_ADCU_ADPA24VPwrup_Cmd(ADCU_ADPA24VPwrup_Cmd_);
  Set_p_ADCU_ADVehPwrup_Cmd(ADCU_ADVehPwrup_Cmd_);
  Set_p_ADCU_PwrCmd_RollCnt(ADCU_PwrCmd_RollCnt_); 
  Set_p_ADCU_PwrCmd_Checksum(ADCU_PwrCmd_Checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ADCU_AD12VMCPwrdownCnfm_Cmd;
signalclass: uint8;
StartBit: 39;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_PowerCmd::SetADCU_AD12VMCPwrdownCnfm_Cmd(double ADCU_AD12VMCPwrdownCnfm_Cmd){
  ADCU_AD12VMCPwrdownCnfm_Cmd_=ADCU_AD12VMCPwrdownCnfm_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VMCPwrdownCnfm_Cmd(double ADCU_AD12VMCPwrdownCnfm_Cmd){
  ADCU_AD12VMCPwrdownCnfm_Cmd=BoundedValue(0.000000,1.000000,ADCU_AD12VMCPwrdownCnfm_Cmd);
  int x = (ADCU_AD12VMCPwrdownCnfm_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 4,7,1,x0);
}
/******************
signalname: ADCU_AD12VMCPwrup_Cmd;
signalclass: uint8;
StartBit: 2;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VMCPwrup_Cmd(double ADCU_AD12VMCPwrup_Cmd){
  ADCU_AD12VMCPwrup_Cmd_=ADCU_AD12VMCPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VMCPwrup_Cmd(double ADCU_AD12VMCPwrup_Cmd){
  ADCU_AD12VMCPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VMCPwrup_Cmd);
  int x = (ADCU_AD12VMCPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,2,2,x0);
}
/******************
signalname: ADCU_AD12VRCPwrdownCnfm_Cmd;
signalclass: uint8;
StartBit: 38;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_PowerCmd::SetADCU_AD12VRCPwrdownCnfm_Cmd(double ADCU_AD12VRCPwrdownCnfm_Cmd){
  ADCU_AD12VRCPwrdownCnfm_Cmd_=ADCU_AD12VRCPwrdownCnfm_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VRCPwrdownCnfm_Cmd(double ADCU_AD12VRCPwrdownCnfm_Cmd){
  ADCU_AD12VRCPwrdownCnfm_Cmd=BoundedValue(0.000000,1.000000,ADCU_AD12VRCPwrdownCnfm_Cmd);
  int x = (ADCU_AD12VRCPwrdownCnfm_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 4,6,1,x0);
}
/******************
signalname: ADCU_AD12VRCPwrup_Cmd;
signalclass: uint8;
StartBit: 0;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VRCPwrup_Cmd(double ADCU_AD12VRCPwrup_Cmd){
  ADCU_AD12VRCPwrup_Cmd_=ADCU_AD12VRCPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VRCPwrup_Cmd(double ADCU_AD12VRCPwrup_Cmd){
  ADCU_AD12VRCPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VRCPwrup_Cmd);
  int x = (ADCU_AD12VRCPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,0,2,x0);
}
/******************
signalname: ADCU_AD12VSC1Pwrup_Cmd;
signalclass: uint8;
StartBit: 8;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VSC1Pwrup_Cmd(double ADCU_AD12VSC1Pwrup_Cmd){
  ADCU_AD12VSC1Pwrup_Cmd_=ADCU_AD12VSC1Pwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VSC1Pwrup_Cmd(double ADCU_AD12VSC1Pwrup_Cmd){
  ADCU_AD12VSC1Pwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VSC1Pwrup_Cmd);
  int x = (ADCU_AD12VSC1Pwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 1,0,2,x0);
}
/******************
signalname: ADCU_AD12VSC2Pwrup_Cmd;
signalclass: uint8;
StartBit: 22;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VSC2Pwrup_Cmd(double ADCU_AD12VSC2Pwrup_Cmd){
  ADCU_AD12VSC2Pwrup_Cmd_=ADCU_AD12VSC2Pwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VSC2Pwrup_Cmd(double ADCU_AD12VSC2Pwrup_Cmd){
  ADCU_AD12VSC2Pwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VSC2Pwrup_Cmd);
  int x = (ADCU_AD12VSC2Pwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 2,6,2,x0);
}
/******************
signalname: ADCU_AD12VSC3Pwrup_Cmd;
signalclass: uint8;
StartBit: 20;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VSC3Pwrup_Cmd(double ADCU_AD12VSC3Pwrup_Cmd){
  ADCU_AD12VSC3Pwrup_Cmd_=ADCU_AD12VSC3Pwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VSC3Pwrup_Cmd(double ADCU_AD12VSC3Pwrup_Cmd){
  ADCU_AD12VSC3Pwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VSC3Pwrup_Cmd);
  int x = (ADCU_AD12VSC3Pwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 2,4,2,x0);
}
/******************
signalname: ADCU_AD12VSC4Pwrup_Cmd;
signalclass: uint8;
StartBit: 18;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VSC4Pwrup_Cmd(double ADCU_AD12VSC4Pwrup_Cmd){
  ADCU_AD12VSC4Pwrup_Cmd_=ADCU_AD12VSC4Pwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VSC4Pwrup_Cmd(double ADCU_AD12VSC4Pwrup_Cmd){
  ADCU_AD12VSC4Pwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VSC4Pwrup_Cmd);
  int x = (ADCU_AD12VSC4Pwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 2,2,2,x0);
}
/******************
signalname: ADCU_AD12VSC5Pwrup_Cmd;
signalclass: uint8;
StartBit: 16;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VSC5Pwrup_Cmd(double ADCU_AD12VSC5Pwrup_Cmd){
  ADCU_AD12VSC5Pwrup_Cmd_=ADCU_AD12VSC5Pwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VSC5Pwrup_Cmd(double ADCU_AD12VSC5Pwrup_Cmd){
  ADCU_AD12VSC5Pwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VSC5Pwrup_Cmd);
  int x = (ADCU_AD12VSC5Pwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 2,0,2,x0);
}
/******************
signalname: ADCU_AD12VSC6Pwrup_Cmd;
signalclass: uint8;
StartBit: 30;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD12VSC6Pwrup_Cmd(double ADCU_AD12VSC6Pwrup_Cmd){
  ADCU_AD12VSC6Pwrup_Cmd_=ADCU_AD12VSC6Pwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD12VSC6Pwrup_Cmd(double ADCU_AD12VSC6Pwrup_Cmd){
  ADCU_AD12VSC6Pwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD12VSC6Pwrup_Cmd);
  int x = (ADCU_AD12VSC6Pwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 3,6,2,x0);
}
/******************
signalname: ADCU_AD24VMCPwrdownCnfm_Cmd;
signalclass: uint8;
StartBit: 37;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_PowerCmd::SetADCU_AD24VMCPwrdownCnfm_Cmd(double ADCU_AD24VMCPwrdownCnfm_Cmd){
  ADCU_AD24VMCPwrdownCnfm_Cmd_=ADCU_AD24VMCPwrdownCnfm_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD24VMCPwrdownCnfm_Cmd(double ADCU_AD24VMCPwrdownCnfm_Cmd){
  ADCU_AD24VMCPwrdownCnfm_Cmd=BoundedValue(0.000000,1.000000,ADCU_AD24VMCPwrdownCnfm_Cmd);
  int x = (ADCU_AD24VMCPwrdownCnfm_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 4,5,1,x0);
}
/******************
signalname: ADCU_AD24VMCPwrup_Cmd;
signalclass: uint8;
StartBit: 14;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_AD24VMCPwrup_Cmd(double ADCU_AD24VMCPwrup_Cmd){
  ADCU_AD24VMCPwrup_Cmd_=ADCU_AD24VMCPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_AD24VMCPwrup_Cmd(double ADCU_AD24VMCPwrup_Cmd){
  ADCU_AD24VMCPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_AD24VMCPwrup_Cmd);
  int x = (ADCU_AD24VMCPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 1,6,2,x0);
}
/******************
signalname: ADCU_ADChasPwrup_Cmd;
signalclass: uint8;
StartBit: 4;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_ADChasPwrup_Cmd(double ADCU_ADChasPwrup_Cmd){
  ADCU_ADChasPwrup_Cmd_=ADCU_ADChasPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_ADChasPwrup_Cmd(double ADCU_ADChasPwrup_Cmd){
  ADCU_ADChasPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_ADChasPwrup_Cmd);
  int x = (ADCU_ADChasPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,4,2,x0);
}
/******************
signalname: ADCU_ADPA12VPwrdownCnfm_Cmd;
signalclass: uint8;
StartBit: 36;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_PowerCmd::SetADCU_ADPA12VPwrdownCnfm_Cmd(double ADCU_ADPA12VPwrdownCnfm_Cmd){
  ADCU_ADPA12VPwrdownCnfm_Cmd_=ADCU_ADPA12VPwrdownCnfm_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_ADPA12VPwrdownCnfm_Cmd(double ADCU_ADPA12VPwrdownCnfm_Cmd){
  ADCU_ADPA12VPwrdownCnfm_Cmd=BoundedValue(0.000000,1.000000,ADCU_ADPA12VPwrdownCnfm_Cmd);
  int x = (ADCU_ADPA12VPwrdownCnfm_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 4,4,1,x0);
}
/******************
signalname: ADCU_ADPA12VPwrup_Cmd;
signalclass: uint8;
StartBit: 12;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_ADPA12VPwrup_Cmd(double ADCU_ADPA12VPwrup_Cmd){
  ADCU_ADPA12VPwrup_Cmd_=ADCU_ADPA12VPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_ADPA12VPwrup_Cmd(double ADCU_ADPA12VPwrup_Cmd){
  ADCU_ADPA12VPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_ADPA12VPwrup_Cmd);
  int x = (ADCU_ADPA12VPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 1,4,2,x0);
}
/******************
signalname: ADCU_ADPA24VPwrdownCnfm_Cmd;
signalclass: uint8;
StartBit: 35;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_PowerCmd::SetADCU_ADPA24VPwrdownCnfm_Cmd(double ADCU_ADPA24VPwrdownCnfm_Cmd){
  ADCU_ADPA24VPwrdownCnfm_Cmd_=ADCU_ADPA24VPwrdownCnfm_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_ADPA24VPwrdownCnfm_Cmd(double ADCU_ADPA24VPwrdownCnfm_Cmd){
  ADCU_ADPA24VPwrdownCnfm_Cmd=BoundedValue(0.000000,1.000000,ADCU_ADPA24VPwrdownCnfm_Cmd);
  int x = (ADCU_ADPA24VPwrdownCnfm_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 4,3,1,x0);
}
/******************
signalname: ADCU_ADPA24VPwrup_Cmd;
signalclass: uint8;
StartBit: 10;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_ADPA24VPwrup_Cmd(double ADCU_ADPA24VPwrup_Cmd){
  ADCU_ADPA24VPwrup_Cmd_=ADCU_ADPA24VPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_ADPA24VPwrup_Cmd(double ADCU_ADPA24VPwrup_Cmd){
  ADCU_ADPA24VPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_ADPA24VPwrup_Cmd);
  int x = (ADCU_ADPA24VPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 1,2,2,x0);
}
/******************
signalname: ADCU_ADVehPwrup_Cmd;
signalclass: uint8;
StartBit: 6;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_PowerCmd::SetADCU_ADVehPwrup_Cmd(double ADCU_ADVehPwrup_Cmd){
  ADCU_ADVehPwrup_Cmd_=ADCU_ADVehPwrup_Cmd;
}
void ADCU_PowerCmd::Set_p_ADCU_ADVehPwrup_Cmd(double ADCU_ADVehPwrup_Cmd){
  ADCU_ADVehPwrup_Cmd=BoundedValue(0.000000,3.000000,ADCU_ADVehPwrup_Cmd);
  int x = (ADCU_ADVehPwrup_Cmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,6,2,x0);
}
/******************
signalname: ADCU_PwrCmd_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ADCU_PowerCmd::SetADCU_PwrCmd_Checksum(double ADCU_PwrCmd_Checksum){
  ADCU_PwrCmd_Checksum_=ADCU_PwrCmd_Checksum;
}
void ADCU_PowerCmd::Set_p_ADCU_PwrCmd_Checksum(double ADCU_PwrCmd_Checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: ADCU_PwrCmd_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ADCU_PowerCmd::SetADCU_PwrCmd_RollCnt(double ADCU_PwrCmd_RollCnt){
  ADCU_PwrCmd_RollCnt_=ADCU_PwrCmd_RollCnt;
}
void ADCU_PowerCmd::Set_p_ADCU_PwrCmd_RollCnt(double ADCU_PwrCmd_RollCnt){
  ADCU_PwrCmd_RollCnt=BoundedValue(0.000000,15.000000,ADCU_PwrCmd_RollCnt);
  int x = (ADCU_PwrCmd_RollCnt - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
