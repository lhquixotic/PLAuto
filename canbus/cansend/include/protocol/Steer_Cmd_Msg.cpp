#include "Steer_Cmd_Msg.h" 
Steer_Cmd_Msg::Steer_Cmd_Msg(){
  id_ = 0x113;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void Steer_Cmd_Msg::Reset(){
  checksum_=0;
  control_active_=0;
  rolling_counter_=0;
  steer_control_mode_=0;
  target_steer_angle_value_=0;
  target_steer_curvature_=0;
}
void Steer_Cmd_Msg::Update(uint8_t *data){
  
  Set_p_control_active(control_active_);
  Set_p_rolling_counter(rolling_counter_);
  Set_p_steer_control_mode(steer_control_mode_);
  Set_p_target_steer_angle_value(target_steer_angle_value_);
  Set_p_target_steer_curvature(target_steer_curvature_);
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
void Steer_Cmd_Msg::Setchecksum(double checksum){
  checksum_=checksum;
}
void Steer_Cmd_Msg::Set_p_checksum(double checksum){
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
void Steer_Cmd_Msg::Setcontrol_active(double control_active){
  control_active_=control_active;
}
void Steer_Cmd_Msg::Set_p_control_active(double control_active){
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
void Steer_Cmd_Msg::Setrolling_counter(double rolling_counter){
  rolling_counter_=rolling_counter;
}
void Steer_Cmd_Msg::Set_p_rolling_counter(double rolling_counter){
  rolling_counter=BoundedValue(0.000000,15.000000,rolling_counter);
  int x = (rolling_counter - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: steer_control_mode;
signalclass: uint8;
StartBit: 5;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Steer_Cmd_Msg::Setsteer_control_mode(double steer_control_mode){
  steer_control_mode_=steer_control_mode;
}
void Steer_Cmd_Msg::Set_p_steer_control_mode(double steer_control_mode){
  steer_control_mode=BoundedValue(0.000000,3.000000,steer_control_mode);
  int x = (steer_control_mode - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,5,2,x0);
}
/******************
signalname: target_steer_angle_value;
signalclass: int16;
StartBit: 16;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: -1000;
Minimum: -1000;
Maximum: 1000;
******************/
void Steer_Cmd_Msg::Settarget_steer_angle_value(double target_steer_angle_value){
  target_steer_angle_value_=target_steer_angle_value;
}
void Steer_Cmd_Msg::Set_p_target_steer_angle_value(double target_steer_angle_value){
  target_steer_angle_value=BoundedValue(-1000.000000,1000.000000,target_steer_angle_value);
  int x = (target_steer_angle_value - -1000.000000) / 0.100000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,0,8,x1);
}
/******************
signalname: target_steer_curvature;
signalclass: int16;
StartBit: 32;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0001;
Offset: -3;
Minimum: -3;
Maximum: 3;
******************/
void Steer_Cmd_Msg::Settarget_steer_curvature(double target_steer_curvature){
  target_steer_curvature_=target_steer_curvature;
}
void Steer_Cmd_Msg::Set_p_target_steer_curvature(double target_steer_curvature){
  target_steer_curvature=BoundedValue(-3.000000,3.000000,target_steer_curvature);
  int x = (target_steer_curvature - -3.000000) / 0.000100;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 3,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 4,0,8,x1);
}
