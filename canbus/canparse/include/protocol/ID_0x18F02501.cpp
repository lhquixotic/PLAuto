#include "ID_0x18F02501.h"
ID_0x18F02501::ID_0x18F02501(){
  id_ = 0x18F02501;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwAcc_=0;
  flwBrkPress_=0;
  flwPedBrk_=0;
  flwSpd_=0;
}
void ID_0x18F02501::Reset(){
  flwAcc_=0;
  flwBrkPress_=0;
  flwPedBrk_=0;
  flwSpd_=0;
}
void ID_0x18F02501::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwAcc();
  UpdateflwBrkPress();
  UpdateflwPedBrk();
  UpdateflwSpd();
}
/******************
signalname: flwAcc;
signalclass: int16;
StartBit: 8;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: -15;
Minimum: -15;
Maximum: 15;
******************/
void ID_0x18F02501::UpdateflwAcc(){
  int32_t x0 = GetByte(data_ + 1,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.1000000000 + -15.0000000000;
  flwAcc_ = ret;
}
double ID_0x18F02501::flwAcc(){
  return flwAcc_;
}
/******************
signalname: flwBrkPress;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 0.01;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ID_0x18F02501::UpdateflwBrkPress(){
  int16_t x0 = GetByte(data_ + 5,0,8);
  x0<<=0;
  double ret = x0 * 0.0100000000 + 0.0000000000;
  flwBrkPress_ = ret;
}
double ID_0x18F02501::flwBrkPress(){
  return flwBrkPress_;
}
/******************
signalname: flwPedBrk;
signalclass: uint8;
StartBit: 0;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void ID_0x18F02501::UpdateflwPedBrk(){
  int16_t x0 = GetByte(data_ + 0,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  flwPedBrk_ = ret;
}
double ID_0x18F02501::flwPedBrk(){
  return flwPedBrk_;
}
/******************
signalname: flwSpd;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 80;
******************/
void ID_0x18F02501::UpdateflwSpd(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  flwSpd_ = ret;
}
double ID_0x18F02501::flwSpd(){
  return flwSpd_;
}
