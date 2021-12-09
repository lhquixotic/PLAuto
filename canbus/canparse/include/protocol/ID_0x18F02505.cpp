#include "ID_0x18F02505.h"
ID_0x18F02505::ID_0x18F02505(){
  id_ = 0x18F02505;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwPdlAccfreq_=0;
  flwPdlAccobj_=0;
  flwPedBrkfreq_=0;
  flwPedBrkobj_=0;
}
void ID_0x18F02505::Reset(){
  flwPdlAccfreq_=0;
  flwPdlAccobj_=0;
  flwPedBrkfreq_=0;
  flwPedBrkobj_=0;
}
void ID_0x18F02505::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwPdlAccfreq();
  UpdateflwPdlAccobj();
  UpdateflwPedBrkfreq();
  UpdateflwPedBrkobj();
}
/******************
signalname: flwPdlAccfreq;
signalclass: uint16;
StartBit: 48;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 20;
Offset: 0;
Minimum: 0;
Maximum: 5000;
******************/
void ID_0x18F02505::UpdateflwPdlAccfreq(){
  int32_t x0 = GetByte(data_ + 6,0,8);
  int32_t x1 = GetByte(data_ + 7,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 20.0000000000 + 0.0000000000;
  flwPdlAccfreq_ = ret;
}
double ID_0x18F02505::flwPdlAccfreq(){
  return flwPdlAccfreq_;
}
/******************
signalname: flwPdlAccobj;
signalclass: uint16;
StartBit: 16;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 200;
******************/
void ID_0x18F02505::UpdateflwPdlAccobj(){
  int32_t x0 = GetByte(data_ + 2,0,8);
  int32_t x1 = GetByte(data_ + 3,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  flwPdlAccobj_ = ret;
}
double ID_0x18F02505::flwPdlAccobj(){
  return flwPdlAccobj_;
}
/******************
signalname: flwPedBrkfreq;
signalclass: uint16;
StartBit: 32;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 20;
Offset: 0;
Minimum: 0;
Maximum: 5000;
******************/
void ID_0x18F02505::UpdateflwPedBrkfreq(){
  int32_t x0 = GetByte(data_ + 4,0,8);
  int32_t x1 = GetByte(data_ + 5,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 20.0000000000 + 0.0000000000;
  flwPedBrkfreq_ = ret;
}
double ID_0x18F02505::flwPedBrkfreq(){
  return flwPedBrkfreq_;
}
/******************
signalname: flwPedBrkobj;
signalclass: uint16;
StartBit: 0;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 200;
******************/
void ID_0x18F02505::UpdateflwPedBrkobj(){
  int32_t x0 = GetByte(data_ + 0,0,8);
  int32_t x1 = GetByte(data_ + 1,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  flwPedBrkobj_ = ret;
}
double ID_0x18F02505::flwPedBrkobj(){
  return flwPedBrkobj_;
}
