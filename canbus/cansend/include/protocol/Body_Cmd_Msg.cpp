#include "Body_Cmd_Msg.h" 
Body_Cmd_Msg::Body_Cmd_Msg(){
  id_ = 0x115;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void Body_Cmd_Msg::Reset(){
  backup_light_enable_=0;
  buzzer_enable_=0;
  checksum_=0;
  control_active_=0;
  daytime_lights_enable_=0;
  hazard_enable_=0;
  headlight_enable_=0;
  klaxon_enable_=0;
  rolling_counter_=0;
  turnlight_left_enable_=0;
  turnlight_right_enable_=0;
}
void Body_Cmd_Msg::Update(uint8_t *data){
  Set_p_backup_light_enable(backup_light_enable_);
  Set_p_buzzer_enable(buzzer_enable_);
  Set_p_control_active(control_active_);
  Set_p_daytime_lights_enable(daytime_lights_enable_);
  Set_p_hazard_enable(hazard_enable_);
  Set_p_headlight_enable(headlight_enable_);
  Set_p_klaxon_enable(klaxon_enable_);
  Set_p_rolling_counter(rolling_counter_);
  Set_p_turnlight_left_enable(turnlight_left_enable_);
  Set_p_turnlight_right_enable(turnlight_right_enable_);
  Set_p_checksum(checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: backup_light_enable;
signalclass: uint8;
StartBit: 11;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Setbackup_light_enable(double backup_light_enable){
  backup_light_enable_=backup_light_enable;
}
void Body_Cmd_Msg::Set_p_backup_light_enable(double backup_light_enable){
  backup_light_enable=BoundedValue(0.000000,1.000000,backup_light_enable);
  int x = (backup_light_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,3,1,x0);
}
/******************
signalname: buzzer_enable;
signalclass: uint8;
StartBit: 10;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Setbuzzer_enable(double buzzer_enable){
  buzzer_enable_=buzzer_enable;
}
void Body_Cmd_Msg::Set_p_buzzer_enable(double buzzer_enable){
  buzzer_enable=BoundedValue(0.000000,1.000000,buzzer_enable);
  int x = (buzzer_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,2,1,x0);
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
void Body_Cmd_Msg::Setchecksum(double checksum){
  checksum_=checksum;
}
void Body_Cmd_Msg::Set_p_checksum(double checksum){
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
void Body_Cmd_Msg::Setcontrol_active(double control_active){
  control_active_=control_active;
}
void Body_Cmd_Msg::Set_p_control_active(double control_active){
  control_active=BoundedValue(0.000000,1.000000,control_active);
  int x = (control_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: daytime_lights_enable;
signalclass: uint8;
StartBit: 8;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Body_Cmd_Msg::Setdaytime_lights_enable(double daytime_lights_enable){
  daytime_lights_enable_=daytime_lights_enable;
}
void Body_Cmd_Msg::Set_p_daytime_lights_enable(double daytime_lights_enable){
  daytime_lights_enable=BoundedValue(0.000000,0.000000,daytime_lights_enable);
  int x = (daytime_lights_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,0,1,x0);
}
/******************
signalname: hazard_enable;
signalclass: uint8;
StartBit: 14;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Sethazard_enable(double hazard_enable){
  hazard_enable_=hazard_enable;
}
void Body_Cmd_Msg::Set_p_hazard_enable(double hazard_enable){
  hazard_enable=BoundedValue(0.000000,1.000000,hazard_enable);
  int x = (hazard_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,6,1,x0);
}
/******************
signalname: headlight_enable;
signalclass: uint8;
StartBit: 15;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Setheadlight_enable(double headlight_enable){
  headlight_enable_=headlight_enable;
}
void Body_Cmd_Msg::Set_p_headlight_enable(double headlight_enable){
  headlight_enable=BoundedValue(0.000000,1.000000,headlight_enable);
  int x = (headlight_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,7,1,x0);
}
/******************
signalname: klaxon_enable;
signalclass: uint8;
StartBit: 9;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Setklaxon_enable(double klaxon_enable){
  klaxon_enable_=klaxon_enable;
}
void Body_Cmd_Msg::Set_p_klaxon_enable(double klaxon_enable){
  klaxon_enable=BoundedValue(0.000000,1.000000,klaxon_enable);
  int x = (klaxon_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,1,1,x0);
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
void Body_Cmd_Msg::Setrolling_counter(double rolling_counter){
  rolling_counter_=rolling_counter;
}
void Body_Cmd_Msg::Set_p_rolling_counter(double rolling_counter){
  rolling_counter=BoundedValue(0.000000,15.000000,rolling_counter);
  int x = (rolling_counter - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: turnlight_left_enable;
signalclass: uint8;
StartBit: 13;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Setturnlight_left_enable(double turnlight_left_enable){
  turnlight_left_enable_=turnlight_left_enable;
}
void Body_Cmd_Msg::Set_p_turnlight_left_enable(double turnlight_left_enable){
  turnlight_left_enable=BoundedValue(0.000000,1.000000,turnlight_left_enable);
  int x = (turnlight_left_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,5,1,x0);
}
/******************
signalname: turnlight_right_enable;
signalclass: uint8;
StartBit: 12;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void Body_Cmd_Msg::Setturnlight_right_enable(double turnlight_right_enable){
  turnlight_right_enable_=turnlight_right_enable;
}
void Body_Cmd_Msg::Set_p_turnlight_right_enable(double turnlight_right_enable){
  turnlight_right_enable=BoundedValue(0.000000,1.000000,turnlight_right_enable);
  int x = (turnlight_right_enable - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 1,4,1,x0);
}
