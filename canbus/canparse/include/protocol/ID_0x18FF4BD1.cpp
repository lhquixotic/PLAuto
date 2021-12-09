#include "ID_0x18FF4BD1.h"
ID_0x18FF4BD1::ID_0x18FF4BD1(){
  id_ = 0x18FF4BD1;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwStrAgl_=0;
  flwStrErrCls_=0;
  flwStrErrCod_=0;
}
void ID_0x18FF4BD1::Reset(){
  flwStrAgl_=0;
  flwStrErrCls_=0;
  flwStrErrCod_=0;
}
void ID_0x18FF4BD1::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwStrAgl();
  UpdateflwStrErrCls();
  UpdateflwStrErrCod();
}
/******************
signalname: flwStrAgl;
signalclass: int8;
StartBit: 0;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: -3276.7;
Minimum: -1260;
Maximum: 1260;
******************/
void ID_0x18FF4BD1::UpdateflwStrAgl(){
  int32_t x0 = GetByte(data_ + 0,0,8);
  int32_t x1 = GetByte(data_ + 1,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.1000000000 + -3276.7000000000;
  flwStrAgl_ = ret;
}
double ID_0x18FF4BD1::flwStrAgl(){
  return flwStrAgl_;
}
/******************
signalname: flwStrErrCls;
signalclass: uint8;
StartBit: 40;
SignalSize: 2;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ID_0x18FF4BD1::UpdateflwStrErrCls(){
  int16_t x0 = GetByte(data_ + 5,0,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;

flwStrErrCls_ = ret;

}
 double ID_0x18FF4BD1::flwStrErrCls(){
  return flwStrErrCls_;
}
/******************
signalname: flwStrErrCod;
signalclass: uint8;
StartBit: 48;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ID_0x18FF4BD1::UpdateflwStrErrCod(){
  int16_t x0 = GetByte(data_ + 6,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  flwStrErrCod_ = ret;
}
double ID_0x18FF4BD1::flwStrErrCod(){
  return flwStrErrCod_;
}
