#include "ID_0x18F02502.h"
ID_0x18F02502::ID_0x18F02502(){
  id_ = 0x18F02502;
  dlc_ = 4;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwPdlAcc_=0;
  flwPedBrk_=0;
}
void ID_0x18F02502::Reset(){
  flwPdlAcc_=0;
  flwPedBrk_=0;
}
void ID_0x18F02502::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwPdlAcc();
  UpdateflwPedBrk();
}
/******************
signalname: flwPdlAcc;
signalclass: uint16;
StartBit: 16;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void ID_0x18F02502::UpdateflwPdlAcc(){
  int32_t x0 = GetByte(data_ + 2,0,8);
  int32_t x1 = GetByte(data_ + 3,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  flwPdlAcc_ = ret;
}
double ID_0x18F02502::flwPdlAcc(){
  return flwPdlAcc_;
}
/******************
signalname: flwPedBrk;
signalclass: uint16;
StartBit: 0;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void ID_0x18F02502::UpdateflwPedBrk(){
  int32_t x0 = GetByte(data_ + 0,0,8);
  int32_t x1 = GetByte(data_ + 1,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  flwPedBrk_ = ret;
}
double ID_0x18F02502::flwPedBrk(){
  return flwPedBrk_;
}
