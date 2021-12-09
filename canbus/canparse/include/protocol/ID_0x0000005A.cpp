#include "ID_0x0000005A.h"
ID_0x0000005A::ID_0x0000005A(){
  id_ = 0x5A;
  dlc_ = 4;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwPitchRt_=0;
  flwYawRt_=0;
}
void ID_0x0000005A::Reset(){
  flwPitchRt_=0;
  flwYawRt_=0;
}
void ID_0x0000005A::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwPitchRt();
  UpdateflwYawRt();
}
/******************
signalname: flwPitchRt;
signalclass: int16;
StartBit: 8;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0076336;
Offset: 0;
Minimum: -250.1374;
Maximum: 250.1298;
******************/
void ID_0x0000005A::UpdateflwPitchRt(){
  int32_t x0 = GetByte(data_ + 1,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=8;
  x1<<=0;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0076335878 + 0.0000000000;
  flwPitchRt_ = ret;
}
double ID_0x0000005A::flwPitchRt(){
  return flwPitchRt_;
}
/******************
signalname: flwYawRt;
signalclass: int16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0076336;
Offset: 0;
Minimum: -250.1374;
Maximum: 250.1298;
******************/
void ID_0x0000005A::UpdateflwYawRt(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=8;
  x1<<=0;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0076335878 + 0.0000000000;
  flwYawRt_ = ret;
}
double ID_0x0000005A::flwYawRt(){
  return flwYawRt_;
}
