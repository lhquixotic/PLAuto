#include "id_0x151.h"
id_0x151::id_0x151(){
  id_ = 0x151;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  FootControlSysInfo_=0;
}
void id_0x151::Reset(){
  FootControlSysInfo_=0;
}
void id_0x151::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateFootControlSysInfo();
}
/******************
signalname: FootControlSysInfo;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void id_0x151::UpdateFootControlSysInfo(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  FootControlSysInfo_ = ret;
}
double id_0x151::FootControlSysInfo(){
  return FootControlSysInfo_;
}
