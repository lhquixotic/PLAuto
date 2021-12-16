#include "Vehicle_Dynamic_State.h"
Vehicle_Dynamic_State::Vehicle_Dynamic_State(){
  id_ = 0x250;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  checksum_=0;
  rolling_counter_=0;
  run_direction_=0;
  tripmeter_=0;
  veh_lon_acceleration_=0;
  vehicle_speed_=0;
}
void Vehicle_Dynamic_State::Reset(){
  checksum_=0;
  rolling_counter_=0;
  run_direction_=0;
  tripmeter_=0;
  veh_lon_acceleration_=0;
  vehicle_speed_=0;
}
void Vehicle_Dynamic_State::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  Updatechecksum();
  Updaterolling_counter();
  Updaterun_direction();
  Updatetripmeter();
  Updateveh_lon_acceleration();
  Updatevehicle_speed();
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
void Vehicle_Dynamic_State::Updatechecksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  checksum_ = ret;
}
double Vehicle_Dynamic_State::checksum(){
  return checksum_;
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
void Vehicle_Dynamic_State::Updaterolling_counter(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  rolling_counter_ = ret;
}
double Vehicle_Dynamic_State::rolling_counter(){
  return rolling_counter_;
}
/******************
signalname: run_direction;
signalclass: uint8;
StartBit: 54;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void Vehicle_Dynamic_State::Updaterun_direction(){
  int16_t x0 = GetByte(data_ + 6,6,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  run_direction_ = ret;
}
double Vehicle_Dynamic_State::run_direction(){
  return run_direction_;
}
/******************
signalname: tripmeter;
signalclass: uint16;
StartBit: 40;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Vehicle_Dynamic_State::Updatetripmeter(){
  int32_t x0 = GetByte(data_ + 5,0,8);
  int32_t x1 = GetByte(data_ + 4,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  tripmeter_ = ret;
}
double Vehicle_Dynamic_State::tripmeter(){
  return tripmeter_;
}
/******************
signalname: veh_lon_acceleration;
signalclass: int16;
StartBit: 8;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: -40;
Minimum: -10;
Maximum: 10;
******************/
void Vehicle_Dynamic_State::Updateveh_lon_acceleration(){
  int32_t x0 = GetByte(data_ + 1,0,8);
  int32_t x1 = GetByte(data_ + 0,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  x0<<=16;
  x0>>=16;
  double ret = x0 * 0.0100000000 + -40.0000000000;
  veh_lon_acceleration_ = ret;
}
double Vehicle_Dynamic_State::veh_lon_acceleration(){
  return veh_lon_acceleration_;
}
/******************
signalname: vehicle_speed;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.0039063;
Offset: 0;
Minimum: 0;
Maximum: 100;
******************/
void Vehicle_Dynamic_State::Updatevehicle_speed(){
  int32_t x0 = GetByte(data_ + 3,0,8);
  int32_t x1 = GetByte(data_ + 2,0,8);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 0.0039062500 + 0.0000000000;
  vehicle_speed_ = ret;
}
double Vehicle_Dynamic_State::vehicle_speed(){
  return vehicle_speed_;
}
