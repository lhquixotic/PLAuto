#include "ID_0x00000059.h"
ID_0x00000059::ID_0x00000059(){
  id_ = 0x59;
  dlc_ = 8;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwLonAcc_=0;
  flwRollRt_=0;
  flwTranAcc_=0;
  flwVerAcc_=0;
}
void ID_0x00000059::Reset(){
  flwLonAcc_=0;
  flwRollRt_=0;
  flwTranAcc_=0;
  flwVerAcc_=0;
}
void ID_0x00000059::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwLonAcc();
  UpdateflwRollRt();
  UpdateflwTranAcc();
  UpdateflwVerAcc();
}
/******************
signalname: flwLonAcc;
signalclass: int16;
StartBit: 8;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.000598;
Offset: 0;
Minimum: -19.5953;
Maximum: 19.5947;
******************/
void ID_0x00000059::UpdateflwLonAcc(){
  int32_t x0 = GetByte(data_ + 1,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=8;
  x1<<=0;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0005980000 + 0.0000000000;
  flwLonAcc_ = ret;
}
double ID_0x00000059::flwLonAcc(){
  return flwLonAcc_;
}
/******************
signalname: flwRollRt;
signalclass: int16;
StartBit: 56;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0076336;
Offset: 0;
Minimum: -250.1374;
Maximum: 250.1298;
******************/
void ID_0x00000059::UpdateflwRollRt(){
  int32_t x0 = GetByte(data_ + 7,0,8);
  int32_t x1 = GetByte(data_ + 8,0,8);
  x0<<=8;
  x1<<=0;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0076335878 + 0.0000000000;
  flwRollRt_ = ret;
}
double ID_0x00000059::flwRollRt(){
  return flwRollRt_;
}
/******************
signalname: flwTranAcc;
signalclass: int16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.000598;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void ID_0x00000059::UpdateflwTranAcc(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=8;
  x1<<=0;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0005980000 + 0.0000000000;
  flwTranAcc_ = ret;
}
double ID_0x00000059::flwTranAcc(){
  return flwTranAcc_;
}
/******************
signalname: flwVerAcc;
signalclass: int16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.000598;
Offset: 0;
Minimum: -19.5953;
Maximum: 19.5947;
******************/
void ID_0x00000059::UpdateflwVerAcc(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 6,0,8);
  x0<<=8;
  x1<<=0;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0005980000 + 0.0000000000;
  flwVerAcc_ = ret;
}
double ID_0x00000059::flwVerAcc(){
  return flwVerAcc_;
}
