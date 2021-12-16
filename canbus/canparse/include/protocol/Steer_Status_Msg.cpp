#include "Steer_Status_Msg.h"
Steer_Status_Msg::Steer_Status_Msg(){
  id_ = 0x215;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  act_fault_level_=0;
  act_work_mode_=0;
  checksum_=0;
  real_steer_angle_=0;
  real_steer_angle_gradiant_=0;
  rolling_counter_=0;
  steer_torque_value_=0;
}
void Steer_Status_Msg::Reset(){
  act_fault_level_=0;
  act_work_mode_=0;
  checksum_=0;
  real_steer_angle_=0;
  real_steer_angle_gradiant_=0;
  rolling_counter_=0;
  steer_torque_value_=0;
}
void Steer_Status_Msg::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  Updateact_fault_level();
  Updateact_work_mode();
  Updatechecksum();
  Updatereal_steer_angle();
  Updatereal_steer_angle_gradiant();
  Updaterolling_counter();
  Updatesteer_torque_value();
}
/******************
signalname: act_fault_level;
signalclass: uint8;
StartBit: 52;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void Steer_Status_Msg::Updateact_fault_level(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  act_fault_level_ = ret;
}
double Steer_Status_Msg::act_fault_level(){
  return act_fault_level_;
}
/******************
signalname: act_work_mode;
signalclass: uint8;
StartBit: 6;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Steer_Status_Msg::Updateact_work_mode(){
  int16_t x0 = GetByte(data_ + 0,6,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  act_work_mode_ = ret;
}
double Steer_Status_Msg::act_work_mode(){
  return act_work_mode_;
}
/******************
signalname: checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Steer_Status_Msg::Updatechecksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  checksum_ = ret;
}
double Steer_Status_Msg::checksum(){
  return checksum_;
}
/******************
signalname: real_steer_angle;
signalclass: int16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: -1024;
Minimum: -1000;
Maximum: 1000;
******************/
void Steer_Status_Msg::Updatereal_steer_angle(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.1000000000 + -1024.0000000000;
  real_steer_angle_ = ret;
}
double Steer_Status_Msg::real_steer_angle(){
  return real_steer_angle_;
}
/******************
signalname: real_steer_angle_gradiant;
signalclass: int16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 1;
Offset: -10000;
Minimum: -10000;
Maximum: 10000;
******************/
void Steer_Status_Msg::Updatereal_steer_angle_gradiant(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 1.0000000000 + -10000.0000000000;
  real_steer_angle_gradiant_ = ret;
}
double Steer_Status_Msg::real_steer_angle_gradiant(){
  return real_steer_angle_gradiant_;
}
/******************
signalname: rolling_counter;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void Steer_Status_Msg::Updaterolling_counter(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  rolling_counter_ = ret;
}
double Steer_Status_Msg::rolling_counter(){
  return rolling_counter_;
}
/******************
signalname: steer_torque_value;
signalclass: int8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: -12.8;
Minimum: -12.8;
Maximum: 12.7;
******************/
void Steer_Status_Msg::Updatesteer_torque_value(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  x0<<=8;
  x0>>=8;
  double ret = x0 * 0.1000000000 + -12.8000000000;
  steer_torque_value_ = ret;
}
double Steer_Status_Msg::steer_torque_value(){
  return steer_torque_value_;
}
