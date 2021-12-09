#include "ID_0x0C040B2A.h" 
ID_0x0C040B2A::ID_0x0C040B2A(){
  id_ = 0xC040B2A;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ID_0x0C040B2A::Reset(){
  conAccReq_=0;
  conSta_=0;
  controlScheme_=0;
  accPedOpenReq_=0;
  brkPedOpenReq_=0;
}
void ID_0x0C040B2A::Update(uint8_t *data){
  Set_p_conAccReq(conAccReq_);
  Set_p_conSta(conSta_);
  Set_p_controlScheme(controlScheme_);
  Set_p_accPedOpenReq(accPedOpenReq_);
  Set_p_brkPedOpenReq(brkPedOpenReq_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: conAccReq;
signalclass: uint16;
StartBit: 0;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: -15;
Minimum: -15;
Maximum: 15;
******************/
void ID_0x0C040B2A::SetconAccReq(double conAccReq){
  conAccReq_=conAccReq;
}
void ID_0x0C040B2A::Set_p_conAccReq(double conAccReq){
  conAccReq=BoundedValue(-15.000000,15.000000,conAccReq);
  //int x = (conAccReq - -15.000000) / 0.100000;
  int x = 0;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 0,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x1);
}
/******************
signalname: conSta;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ID_0x0C040B2A::SetconSta(double conSta){
  conSta_=conSta;
}
void ID_0x0C040B2A::Set_p_conSta(double conSta){
  conSta=BoundedValue(0.000000,15.000000,conSta);
  int x = (conSta - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: controlScheme;
signalclass: int8;
StartBit: 16;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void ID_0x0C040B2A::SetcontrolScheme(double controlScheme){
  controlScheme_=controlScheme;
}
void ID_0x0C040B2A::Set_p_controlScheme(double controlScheme){
  controlScheme=BoundedValue(0.000000,1.000000,controlScheme);
  int x = (controlScheme - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,4,4,x0);
}
/******************
signalname: accPedOpenReq;
signalclass: int8;
StartBit: 32;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void ID_0x0C040B2A::SetAccPedOpenReq(double accPedOpenReq){
  accPedOpenReq_ = accPedOpenReq;
}
void ID_0x0C040B2A::Set_p_accPedOpenReq(double accPedOpenReq){
  accPedOpenReq=BoundedValue(0.000000,100.000000,accPedOpenReq);
  int x = (accPedOpenReq - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 4,0,8,x0);
}
/******************
signalname: brkPedOpenReq;
signalclass: int8;
StartBit: 40;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void ID_0x0C040B2A::SetBrkPedOpenReq(double brkPedOpenReq){
  brkPedOpenReq_ = brkPedOpenReq;
}
void ID_0x0C040B2A::Set_p_brkPedOpenReq(double brkPedOpenReq){
  brkPedOpenReq=BoundedValue(0.000000,100.000000,brkPedOpenReq);
  int x = (brkPedOpenReq - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 5,0,8,x0);
}

