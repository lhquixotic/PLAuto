#include "Brake_Status_Msg.h"
Brake_Status_Msg::Brake_Status_Msg(){
  id_ = 0x211;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  act_fault_level_=0;
  brk_condition_=0;
  brk_mode_=0;
  checksum_=0;
  real_brk_pressure_=0;
  rolling_counter_=0;
}
void Brake_Status_Msg::Reset(){
  act_fault_level_=0;
  brk_condition_=0;
  brk_mode_=0;
  checksum_=0;
  real_brk_pressure_=0;
  rolling_counter_=0;
}
void Brake_Status_Msg::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  Updateact_fault_level();
  Updatebrk_condition();
  Updatebrk_mode();
  Updatechecksum();
  Updatereal_brk_pressure();
  Updaterolling_counter();
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
void Brake_Status_Msg::Updateact_fault_level(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  act_fault_level_ = ret;
}
double Brake_Status_Msg::act_fault_level(){
  return act_fault_level_;
}
/******************
signalname: brk_condition;
signalclass: uint8;
StartBit: 2;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Brake_Status_Msg::Updatebrk_condition(){
  int16_t x0 = GetByte(data_ + 0,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  brk_condition_ = ret;
}
double Brake_Status_Msg::brk_condition(){
  return brk_condition_;
}
/******************
signalname: brk_mode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Brake_Status_Msg::Updatebrk_mode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  brk_mode_ = ret;
}
double Brake_Status_Msg::brk_mode(){
  return brk_mode_;
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
void Brake_Status_Msg::Updatechecksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  checksum_ = ret;
}
double Brake_Status_Msg::checksum(){
  return checksum_;
}
/******************
signalname: real_brk_pressure;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void Brake_Status_Msg::Updatereal_brk_pressure(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  real_brk_pressure_ = ret;
}
double Brake_Status_Msg::real_brk_pressure(){
  return real_brk_pressure_;
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
void Brake_Status_Msg::Updaterolling_counter(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  rolling_counter_ = ret;
}
double Brake_Status_Msg::rolling_counter(){
  return rolling_counter_;
}
