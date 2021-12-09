#include "ID_0x18F01D48.h"
ID_0x18F01D48::ID_0x18F01D48(){
  id_ = 0x18F01D48;
  dlc_ = 6;
  is_extended_ = 1;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  flwSteeringWheelAngel_=0;
  flwWheelSpd_=0;
  flwstdinfo_=0;
  stateinfo1_=0;
  stateinfo23_=0;
  stateinfo4_=0;
  stateinfo5_=0;
  stateinfo6_=0;
  stateinfo7_=0;
}
void ID_0x18F01D48::Reset(){
  flwSteeringWheelAngel_=0;
  flwWheelSpd_=0;
  flwstdinfo_=0;
  stateinfo1_=0;
  stateinfo23_=0;
  stateinfo4_=0;
  stateinfo5_=0;
  stateinfo6_=0;
  stateinfo7_=0;
}
void ID_0x18F01D48::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateflwSteeringWheelAngel();
  UpdateflwWheelSpd();
  Updateflwstdinfo();
  Updatestateinfo1();
  Updatestateinfo23();
  Updatestateinfo4();
  Updatestateinfo5();
  Updatestateinfo6();
  Updatestateinfo7();
}
/******************
signalname: flwSteeringWheelAngel;
signalclass: int16;
StartBit: 0;
SignalSize: 16;
ByteOrder: LittleEndian;
Factor: 0.1;
Offset: 0;
Minimum: -3276.8;
Maximum: 3276.7;
******************/
void ID_0x18F01D48::UpdateflwSteeringWheelAngel(){
  int32_t x0 = GetByte(data_ + 0,0,8);
  int32_t x1 = GetByte(data_ + 1,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.1000000000 + 0.0000000000;
if(x0<=32767&&x0>=0)
{
flwSteeringWheelAngel_ = ret;
}
else if(x0>32767)
{
flwSteeringWheelAngel_ = ret - 6553.6;
}
}
double ID_0x18F01D48::flwSteeringWheelAngel(){
  return flwSteeringWheelAngel_;
}
/******************
signalname: flwWheelSpd;
signalclass: uint8;
StartBit: 16;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 4;
Offset: 0;
Minimum: 0;
Maximum: 1020;
******************/
void ID_0x18F01D48::UpdateflwWheelSpd(){
  int16_t x0 = GetByte(data_ + 2,0,8);
  x0<<=0;
  double ret = x0 * 4.0000000000 + 0.0000000000;
  flwWheelSpd_ = ret;
}
double ID_0x18F01D48::flwWheelSpd(){
  return flwWheelSpd_;
}
/******************
signalname: flwstdinfo;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ID_0x18F01D48::Updateflwstdinfo(){
  int16_t x0 = GetByte(data_ + 5,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  flwstdinfo_ = ret;
}
double ID_0x18F01D48::flwstdinfo(){
  return flwstdinfo_;
}


/******************
signalname: stateinfo1;
signalclass: uint8;
StartBit: 25;
SignalSize: 1;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ID_0x18F01D48::Updatestateinfo1(){
  int16_t x0 = GetByte(data_ + 3,1,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
 stateinfo1_ = ret;

}
double ID_0x18F01D48::stateinfo1(){
  return stateinfo1_;
}
/******************
signalname: stateinfo23;
signalclass: uint8;
StartBit: 26;
SignalSize: 2;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ID_0x18F01D48::Updatestateinfo23(){
  int16_t x0 = GetByte(data_ + 3,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
stateinfo23_ = ret;
} 
double ID_0x18F01D48::stateinfo23(){
  return stateinfo23_;
}
/******************
signalname: stateinfo4;
signalclass: uint8;
StartBit: 28;
SignalSize: 1;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ID_0x18F01D48::Updatestateinfo4(){
  int16_t x0 = GetByte(data_ + 3,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
stateinfo4_ = ret;
}
double ID_0x18F01D48::stateinfo4(){
  return stateinfo4_;
}
/******************
signalname: stateinfo5;
signalclass: uint8;
StartBit: 29;
SignalSize: 1;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ID_0x18F01D48::Updatestateinfo5(){
  int16_t x0 = GetByte(data_ + 3,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
stateinfo5_ = ret;
}
double ID_0x18F01D48::stateinfo5(){
  return stateinfo5_;
}
/******************
signalname: stateinfo6;
signalclass: uint8;
StartBit: 31;
SignalSize: 1;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ID_0x18F01D48::Updatestateinfo6(){
  int16_t x0 = GetByte(data_ + 3,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;

stateinfo6_ = ret;

}
double ID_0x18F01D48::stateinfo6(){
  return stateinfo6_;
}
/******************
signalname: stateinfo7;
signalclass: uint8;
StartBit: 30;
SignalSize: 1;
ByteOrder: LittleEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ID_0x18F01D48::Updatestateinfo7(){
  int16_t x0 = GetByte(data_ + 3,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;

stateinfo7_ = ret;

}
double ID_0x18F01D48::stateinfo7(){
  return stateinfo7_;
}
