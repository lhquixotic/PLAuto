#include "Park_Cmd_Msg.h" 
Park_Cmd_Msg::Park_Cmd_Msg(){
  id_ = 0x112;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void Park_Cmd_Msg::Reset(){
  checksum_=0;
  control_active_=0;
  park_control_enable_=0;
  rolling_counter_=0;
}
void Park_Cmd_Msg::Update(uint8_t *data){
  Set_p_control_active(control_active_);
  Set_p_park_control_enable(park_control_enable_);
  Set_p_rolling_counter(rolling_counter_);
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
void Park_Cmd_Msg::Setchecksum(double checksum){
  checksum_=checksum;
}
void Park_Cmd_Msg::Set_p_checksum(double checksum){
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
void Park_Cmd_Msg::Setcontrol_active(double control_active){
  control_active_=control_active;
}
void Park_Cmd_Msg::Set_p_control_active(double control_active){
  control_active=BoundedValue(0.000000,1.000000,control_active);
  int x = (control_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: park_control_enable;
signalclass: uint8;
StartBit: 6;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Park_Cmd_Msg::Setpark_control_enable(double park_control_enable){
  park_control_enable_=park_control_enable;
}
void Park_Cmd_Msg::Set_p_park_control_enable(double park_control_enable){
  park_control_enable=BoundedValue(0.000000,1.000000,park_control_enable);
  int x = (park_control_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,6,1,x0);
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
void Park_Cmd_Msg::Setrolling_counter(double rolling_counter){
  rolling_counter_=rolling_counter;
}
void Park_Cmd_Msg::Set_p_rolling_counter(double rolling_counter){
  rolling_counter=BoundedValue(0.000000,15.000000,rolling_counter);
  int x = (rolling_counter - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
