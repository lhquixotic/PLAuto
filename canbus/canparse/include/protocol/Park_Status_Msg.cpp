#include "Park_Status_Msg.h"
Park_Status_Msg::Park_Status_Msg(){
  id_ = 0x213;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  act_fault_level_=0;
  act_work_mode_=0;
  checksum_=0;
  park_status_=0;
  rolling_counter_=0;
}
void Park_Status_Msg::Reset(){
  act_fault_level_=0;
  act_work_mode_=0;
  checksum_=0;
  park_status_=0;
  rolling_counter_=0;
}
void Park_Status_Msg::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  Updateact_fault_level();
  Updateact_work_mode();
  Updatechecksum();
  Updatepark_status();
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
void Park_Status_Msg::Updateact_fault_level(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  act_fault_level_ = ret;
}
double Park_Status_Msg::act_fault_level(){
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
void Park_Status_Msg::Updateact_work_mode(){
  int16_t x0 = GetByte(data_ + 0,6,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  act_work_mode_ = ret;
}
double Park_Status_Msg::act_work_mode(){
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
void Park_Status_Msg::Updatechecksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  checksum_ = ret;
}
double Park_Status_Msg::checksum(){
  return checksum_;
}
/******************
signalname: park_status;
signalclass: uint8;
StartBit: 4;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Park_Status_Msg::Updatepark_status(){
  int16_t x0 = GetByte(data_ + 0,4,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  park_status_ = ret;
}
double Park_Status_Msg::park_status(){
  return park_status_;
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
void Park_Status_Msg::Updaterolling_counter(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  rolling_counter_ = ret;
}
double Park_Status_Msg::rolling_counter(){
  return rolling_counter_;
}
