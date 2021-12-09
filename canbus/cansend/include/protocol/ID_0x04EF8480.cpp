#include "ID_0x04EF8480.h" 
ID_0x04EF8480::ID_0x04EF8480(){
  id_ = 0x4EF8480;
  dlc_ = 4;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ID_0x04EF8480::Reset(){
  comControlCmd_=0;
  conDegCmd_=0;
  conRtCmd_=0;
}
void ID_0x04EF8480::Update(uint8_t *data){
  Set_p_comControlCmd(comControlCmd_);
  Set_p_conDegCmd(conDegCmd_);
  Set_p_conRtCmd(conRtCmd_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: comControlCmd;
signalclass: uint8;
StartBit: 0;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void ID_0x04EF8480::SetcomControlCmd(double comControlCmd){
  comControlCmd_=comControlCmd;
}
void ID_0x04EF8480::Set_p_comControlCmd(double comControlCmd){
  comControlCmd=BoundedValue(0.000000,1.000000,comControlCmd);
  int x = (comControlCmd - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 0,0,8,x0);
}
/******************
signalname: conDegCmd;
signalclass: uint16;
StartBit: 16;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: -3276.7;
Minimum: -880;
Maximum: 880;
******************/
void ID_0x04EF8480::SetconDegCmd(double conDegCmd){
  conDegCmd_=conDegCmd;
}
void ID_0x04EF8480::Set_p_conDegCmd(double conDegCmd){
  conDegCmd=BoundedValue(-880.000000,880.000000,conDegCmd);
  int x = (conDegCmd - -3276.700000) / 0.100000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 3,0,8,x1);
}
/******************
signalname: conRtCmd;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 4;
Offset: 0;
Minimum: 0;
Maximum: 500;
******************/
void ID_0x04EF8480::SetconRtCmd(double conRtCmd){
  conRtCmd_=conRtCmd;
}
void ID_0x04EF8480::Set_p_conRtCmd(double conRtCmd){
  conRtCmd=BoundedValue(0.000000,500.000000,conRtCmd);
  int x = (conRtCmd - 0.000000) / 4.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x0);
}
