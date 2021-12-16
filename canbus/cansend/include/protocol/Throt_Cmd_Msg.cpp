#include "Throt_Cmd_Msg.h" 
Throt_Cmd_Msg::Throt_Cmd_Msg(){
  id_ = 0x114;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void Throt_Cmd_Msg::Reset(){
  checksum_=0;
  control_active_=0;
  rolling_counter_=0;
  target_gear_=0;
  target_throttle_=0;
  target_vehicle_speed_=0;
  throt_control_mode_=0;
  vehicle_speed_max_=0;
}
void Throt_Cmd_Msg::Update(uint8_t *data){
  Set_p_control_active(control_active_);
  Set_p_rolling_counter(rolling_counter_);
  Set_p_target_gear(target_gear_);
  Set_p_target_throttle(target_throttle_);
  Set_p_target_vehicle_speed(target_vehicle_speed_);
  Set_p_throt_control_mode(throt_control_mode_);
  Set_p_vehicle_speed_max(vehicle_speed_max_);
  Set_p_checksum(checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
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
void Throt_Cmd_Msg::Setchecksum(double checksum){
  checksum_=checksum;
}
void Throt_Cmd_Msg::Set_p_checksum(double checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: control_active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Throt_Cmd_Msg::Setcontrol_active(double control_active){
  control_active_=control_active;
}
void Throt_Cmd_Msg::Set_p_control_active(double control_active){
  control_active=BoundedValue(0.000000,1.000000,control_active);
  int x = (control_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
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
void Throt_Cmd_Msg::Setrolling_counter(double rolling_counter){
  rolling_counter_=rolling_counter;
}
void Throt_Cmd_Msg::Set_p_rolling_counter(double rolling_counter){
  rolling_counter=BoundedValue(0.000000,15.000000,rolling_counter);
  int x = (rolling_counter - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: target_gear;
signalclass: uint8;
StartBit: 0;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void Throt_Cmd_Msg::Settarget_gear(double target_gear){
  target_gear_=target_gear;
}
void Throt_Cmd_Msg::Set_p_target_gear(double target_gear){
  target_gear=BoundedValue(0.000000,15.000000,target_gear);
  int x = (target_gear - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 0,0,4,x0);
}
/******************
signalname: target_throttle;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: -100;
Minimum: -100;
Maximum: 100;
******************/
void Throt_Cmd_Msg::Settarget_throttle(double target_throttle){
  target_throttle_=target_throttle;
}
void Throt_Cmd_Msg::Set_p_target_throttle(double target_throttle){
  target_throttle=BoundedValue(-100.000000,100.000000,target_throttle);
  int x = (target_throttle - -100.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x0);
}
/******************
signalname: target_vehicle_speed;
signalclass: int16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: -100;
Minimum: -100;
Maximum: 100;
******************/
void Throt_Cmd_Msg::Settarget_vehicle_speed(double target_vehicle_speed){
  target_vehicle_speed_=target_vehicle_speed;
}
void Throt_Cmd_Msg::Set_p_target_vehicle_speed(double target_vehicle_speed){
  target_vehicle_speed=BoundedValue(-100.000000,100.000000,target_vehicle_speed);
  int x = (target_vehicle_speed - -100.000000) / 0.010000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 3,0,8,x1);
}
/******************
signalname: throt_control_mode;
signalclass: uint8;
StartBit: 5;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Throt_Cmd_Msg::Setthrot_control_mode(double throt_control_mode){
  throt_control_mode_=throt_control_mode;
}
void Throt_Cmd_Msg::Set_p_throt_control_mode(double throt_control_mode){
  throt_control_mode=BoundedValue(0.000000,3.000000,throt_control_mode);
  int x = (throt_control_mode - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,5,2,x0);
}
/******************
signalname: vehicle_speed_max;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void Throt_Cmd_Msg::Setvehicle_speed_max(double vehicle_speed_max){
  vehicle_speed_max_=vehicle_speed_max;
}
void Throt_Cmd_Msg::Set_p_vehicle_speed_max(double vehicle_speed_max){
  vehicle_speed_max=BoundedValue(0.000000,100.000000,vehicle_speed_max);
  int x = (vehicle_speed_max - 0.000000) / 0.400000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 5,0,8,x0);
}
