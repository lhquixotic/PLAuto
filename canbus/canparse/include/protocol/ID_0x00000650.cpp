#include "ID_0x00000650.h"
ID_0x00000650::ID_0x00000650(){
  id_ = 0x650;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  uwbDis_=0;
  uwbFW_=0;
  uwbSta_=0;
  uwbZT_=0;
}
void ID_0x00000650::Reset(){
  uwbDis_=0;
  uwbFW_=0;
  uwbSta_=0;
  uwbZT_=0;
}
void ID_0x00000650::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateuwbDis();
  UpdateuwbFW();
  UpdateuwbSta();
  UpdateuwbZT();
}
/******************
signalname: uwbDis;
signalclass: uint16;
StartBit: 16;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.01;
Offset: 0;
Minimum: 0;
Maximum: 655.35;
******************/
void ID_0x00000650::UpdateuwbDis(){
  int32_t x0 = GetByte(data_ + 2,0,8);
  int32_t x1 = GetByte(data_ + 3,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0100000000 + 0.0000000000;
  uwbDis_ = ret;
}
double ID_0x00000650::uwbDis(){
  return uwbDis_;
}
/******************
signalname: uwbFW;
signalclass: int16;
StartBit: 32;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: -32768;
Maximum: 32767;
******************/
void ID_0x00000650::UpdateuwbFW(){
  int32_t x0 = GetByte(data_ + 4,0,8);
  int32_t x1 = GetByte(data_ + 5,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  uwbFW_ = ret;
}
double ID_0x00000650::uwbFW(){
  return uwbFW_;
}
/******************
signalname: uwbSta;
signalclass: uint8;
StartBit: 0;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ID_0x00000650::UpdateuwbSta(){
  int16_t x0 = GetByte(data_ + 0,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  uwbSta_ = ret;
}
double ID_0x00000650::uwbSta(){
  return uwbSta_;
}
/******************
signalname: uwbZT;
signalclass: int16;
StartBit: 48;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: -32768;
Maximum: 32767;
******************/
void ID_0x00000650::UpdateuwbZT(){
  int32_t x0 = GetByte(data_ + 6,0,8);
  int32_t x1 = GetByte(data_ + 7,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  uwbZT_ = ret;
}
double ID_0x00000650::uwbZT(){
  return uwbZT_;
}
