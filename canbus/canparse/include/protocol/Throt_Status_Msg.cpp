#include "Throt_Status_Msg.h"
Throt_Status_Msg::Throt_Status_Msg(){
  id_ = 0x217;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  act_fault_level_=0;
  checksum_=0;
  mc_real_throttle_=0;
  mc_run_direction_=0;
  motor_current_=0;
  motor_speed_=0;
  real_gear_=0;
  rolling_counter_=0;
  throt_mode_=0;
}
void Throt_Status_Msg::Reset(){
  act_fault_level_=0;
  checksum_=0;
  mc_real_throttle_=0;
  mc_run_direction_=0;
  motor_current_=0;
  motor_speed_=0;
  real_gear_=0;
  rolling_counter_=0;
  throt_mode_=0;
}
void Throt_Status_Msg::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  Updateact_fault_level();
  Updatechecksum();
  Updatemc_real_throttle();
  Updatemc_run_direction();
  Updatemotor_current();
  Updatemotor_speed();
  Updatereal_gear();
  Updaterolling_counter();
  Updatethrot_mode();
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
void Throt_Status_Msg::Updateact_fault_level(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  act_fault_level_ = ret;
}
double Throt_Status_Msg::act_fault_level(){
  return act_fault_level_;
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
void Throt_Status_Msg::Updatechecksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  checksum_ = ret;
}
double Throt_Status_Msg::checksum(){
  return checksum_;
}
/******************
signalname: mc_real_throttle;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Throt_Status_Msg::Updatemc_real_throttle(){
  int16_t x0 = GetByte(data_ + 1,0,8);
  x0<<=0;
  double ret = x0 * 0.4000000000 + 0.0000000000;
  mc_real_throttle_ = ret;
}
double Throt_Status_Msg::mc_real_throttle(){
  return mc_real_throttle_;
}
/******************
signalname: mc_run_direction;
signalclass: uint8;
StartBit: 0;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Throt_Status_Msg::Updatemc_run_direction(){
  int16_t x0 = GetByte(data_ + 0,0,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  mc_run_direction_ = ret;
}
double Throt_Status_Msg::mc_run_direction(){
  return mc_run_direction_;
}
/******************
signalname: motor_current;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 300;
******************/
void Throt_Status_Msg::Updatemotor_current(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  motor_current_ = ret;
}
double Throt_Status_Msg::motor_current(){
  return motor_current_;
}
/******************
signalname: motor_speed;
signalclass: uint16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 65535;
******************/
void Throt_Status_Msg::Updatemotor_speed(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  motor_speed_ = ret;
}
double Throt_Status_Msg::motor_speed(){
  return motor_speed_;
}
/******************
signalname: real_gear;
signalclass: uint8;
StartBit: 2;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Throt_Status_Msg::Updatereal_gear(){
  int16_t x0 = GetByte(data_ + 0,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  real_gear_ = ret;
}
double Throt_Status_Msg::real_gear(){
  return real_gear_;
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
void Throt_Status_Msg::Updaterolling_counter(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  rolling_counter_ = ret;
}
double Throt_Status_Msg::rolling_counter(){
  return rolling_counter_;
}
/******************
signalname: throt_mode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Throt_Status_Msg::Updatethrot_mode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  throt_mode_ = ret;
}
double Throt_Status_Msg::throt_mode(){
  return throt_mode_;
}
