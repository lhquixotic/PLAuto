#include "Voltage_Supply_Manage_Msg.h" 
Voltage_Supply_Manage_Msg::Voltage_Supply_Manage_Msg(){
  id_ = 0x117;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void Voltage_Supply_Manage_Msg::Reset(){
  ad1_voltage_supply_active_=0;
  ad1_voltage_supply_reboot_=0;
  ad2_voltage_supply_active_=0;
  ad2_voltage_supply_reboot_=0;
  chassis_voltage_supply_active_=0;
  chassis_voltage_supply_reboot_=0;
  checksum_=0;
  rolling_counter_=0;
  total_voltage_supply_active_=0;
  total_voltage_supply_reboot_=0;
}
void Voltage_Supply_Manage_Msg::Update(uint8_t *data){
  Set_p_ad1_voltage_supply_active(ad1_voltage_supply_active_);
  Set_p_ad1_voltage_supply_reboot(ad1_voltage_supply_reboot_);
  Set_p_ad2_voltage_supply_active(ad2_voltage_supply_active_);
  Set_p_ad2_voltage_supply_reboot(ad2_voltage_supply_reboot_);
  Set_p_chassis_voltage_supply_active(chassis_voltage_supply_active_);
  Set_p_chassis_voltage_supply_reboot(chassis_voltage_supply_reboot_);
  Set_p_checksum(checksum_);
  Set_p_rolling_counter(rolling_counter_);
  Set_p_total_voltage_supply_active(total_voltage_supply_active_);
  Set_p_total_voltage_supply_reboot(total_voltage_supply_reboot_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ad1_voltage_supply_active;
signalclass: uint8;
StartBit: 3;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Setad1_voltage_supply_active(double ad1_voltage_supply_active){
  ad1_voltage_supply_active_=ad1_voltage_supply_active;
}
void Voltage_Supply_Manage_Msg::Set_p_ad1_voltage_supply_active(double ad1_voltage_supply_active){
  ad1_voltage_supply_active=BoundedValue(0.000000,0.000000,ad1_voltage_supply_active);
  int x = (ad1_voltage_supply_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,3,1,x0);
}
/******************
signalname: ad1_voltage_supply_reboot;
signalclass: uint8;
StartBit: 2;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Setad1_voltage_supply_reboot(double ad1_voltage_supply_reboot){
  ad1_voltage_supply_reboot_=ad1_voltage_supply_reboot;
}
void Voltage_Supply_Manage_Msg::Set_p_ad1_voltage_supply_reboot(double ad1_voltage_supply_reboot){
  ad1_voltage_supply_reboot=BoundedValue(0.000000,0.000000,ad1_voltage_supply_reboot);
  int x = (ad1_voltage_supply_reboot - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,2,1,x0);
}
/******************
signalname: ad2_voltage_supply_active;
signalclass: uint8;
StartBit: 1;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Setad2_voltage_supply_active(double ad2_voltage_supply_active){
  ad2_voltage_supply_active_=ad2_voltage_supply_active;
}
void Voltage_Supply_Manage_Msg::Set_p_ad2_voltage_supply_active(double ad2_voltage_supply_active){
  ad2_voltage_supply_active=BoundedValue(0.000000,0.000000,ad2_voltage_supply_active);
  int x = (ad2_voltage_supply_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,1,1,x0);
}
/******************
signalname: ad2_voltage_supply_reboot;
signalclass: uint8;
StartBit: 0;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Setad2_voltage_supply_reboot(double ad2_voltage_supply_reboot){
  ad2_voltage_supply_reboot_=ad2_voltage_supply_reboot;
}
void Voltage_Supply_Manage_Msg::Set_p_ad2_voltage_supply_reboot(double ad2_voltage_supply_reboot){
  ad2_voltage_supply_reboot=BoundedValue(0.000000,0.000000,ad2_voltage_supply_reboot);
  int x = (ad2_voltage_supply_reboot - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,0,1,x0);
}
/******************
signalname: chassis_voltage_supply_active;
signalclass: uint8;
StartBit: 5;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Setchassis_voltage_supply_active(double chassis_voltage_supply_active){
  chassis_voltage_supply_active_=chassis_voltage_supply_active;
}
void Voltage_Supply_Manage_Msg::Set_p_chassis_voltage_supply_active(double chassis_voltage_supply_active){
  chassis_voltage_supply_active=BoundedValue(0.000000,0.000000,chassis_voltage_supply_active);
  int x = (chassis_voltage_supply_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,5,1,x0);
}
/******************
signalname: chassis_voltage_supply_reboot;
signalclass: uint8;
StartBit: 4;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Setchassis_voltage_supply_reboot(double chassis_voltage_supply_reboot){
  chassis_voltage_supply_reboot_=chassis_voltage_supply_reboot;
}
void Voltage_Supply_Manage_Msg::Set_p_chassis_voltage_supply_reboot(double chassis_voltage_supply_reboot){
  chassis_voltage_supply_reboot=BoundedValue(0.000000,0.000000,chassis_voltage_supply_reboot);
  int x = (chassis_voltage_supply_reboot - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,4,1,x0);
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
void Voltage_Supply_Manage_Msg::Setchecksum(double checksum){
  checksum_=checksum;
}
void Voltage_Supply_Manage_Msg::Set_p_checksum(double checksum){
  checksum=BoundedValue(0.000000,255.000000,checksum);
  int x = (checksum - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 7,0,8,x0);
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
void Voltage_Supply_Manage_Msg::Setrolling_counter(double rolling_counter){
  rolling_counter_=rolling_counter;
}
void Voltage_Supply_Manage_Msg::Set_p_rolling_counter(double rolling_counter){
  rolling_counter=BoundedValue(0.000000,15.000000,rolling_counter);
  int x = (rolling_counter - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: total_voltage_supply_active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Settotal_voltage_supply_active(double total_voltage_supply_active){
  total_voltage_supply_active_=total_voltage_supply_active;
}
void Voltage_Supply_Manage_Msg::Set_p_total_voltage_supply_active(double total_voltage_supply_active){
  total_voltage_supply_active=BoundedValue(0.000000,0.000000,total_voltage_supply_active);
  int x = (total_voltage_supply_active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: total_voltage_supply_reboot;
signalclass: uint8;
StartBit: 6;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 0;
******************/
void Voltage_Supply_Manage_Msg::Settotal_voltage_supply_reboot(double total_voltage_supply_reboot){
  total_voltage_supply_reboot_=total_voltage_supply_reboot;
}
void Voltage_Supply_Manage_Msg::Set_p_total_voltage_supply_reboot(double total_voltage_supply_reboot){
  total_voltage_supply_reboot=BoundedValue(0.000000,0.000000,total_voltage_supply_reboot);
  int x = (total_voltage_supply_reboot - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,6,1,x0);
}
