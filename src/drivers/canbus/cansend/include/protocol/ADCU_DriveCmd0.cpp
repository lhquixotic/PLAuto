#include "ADCU_DriveCmd0.h" 
ADCU_DriveCmd0::ADCU_DriveCmd0(){
  id_ = 0x114;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  Reset();
  for(int i=0;i<dlc_;i++) data_[i] = 0;
}
void ADCU_DriveCmd0::Reset(){
  ADCU_DrvCmd_Checksum_=0;
  ADCU_DrvCmd_RollCnt_=0;
  ADCU_Drv_Active_=0;
  ADCU_Drv_CtrlMode_=0;
  ADCU_Drv_TgtGear_=0;
  ADCU_Drv_TgtPedpos_=0;
  ADCU_Drv_TgtVehAccSpd_=0;
  ADCU_Drv_TgtVehSpd0_=0;
  ADCU_Drv_VehSpdLimit_=0;
}
void ADCU_DriveCmd0::Update(uint8_t *data){
  Set_p_ADCU_DrvCmd_RollCnt(ADCU_DrvCmd_RollCnt_);
  Set_p_ADCU_Drv_Active(ADCU_Drv_Active_);
  Set_p_ADCU_Drv_CtrlMode(ADCU_Drv_CtrlMode_);
  Set_p_ADCU_Drv_TgtGear(ADCU_Drv_TgtGear_);
  Set_p_ADCU_Drv_TgtPedpos(ADCU_Drv_TgtPedpos_);
  Set_p_ADCU_Drv_TgtVehAccSpd(ADCU_Drv_TgtVehAccSpd_);
  Set_p_ADCU_Drv_TgtVehSpd0(ADCU_Drv_TgtVehSpd0_);
  Set_p_ADCU_Drv_VehSpdLimit(ADCU_Drv_VehSpdLimit_);  
  Set_p_ADCU_DrvCmd_Checksum(ADCU_DrvCmd_Checksum_);
  for(int i=0;i<dlc_;i++) data[i] = data_[i];
}
/******************
signalname: ADCU_DrvCmd_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void ADCU_DriveCmd0::SetADCU_DrvCmd_Checksum(double ADCU_DrvCmd_Checksum){
  ADCU_DrvCmd_Checksum_=ADCU_DrvCmd_Checksum;
}
void ADCU_DriveCmd0::Set_p_ADCU_DrvCmd_Checksum(double ADCU_DrvCmd_Checksum){
  uint8_t cs = 0;
  for (int k = 0; k<7; k++) cs += data_[k];
  cs = cs ^ 0xff;
  uint8_t x0 = cs & RANG_MASK_1_L[7];
  SetByte(data_ + 7,0,8,x0);
}
/******************
signalname: ADCU_DrvCmd_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void ADCU_DriveCmd0::SetADCU_DrvCmd_RollCnt(double ADCU_DrvCmd_RollCnt){
  ADCU_DrvCmd_RollCnt_=ADCU_DrvCmd_RollCnt;
}
void ADCU_DriveCmd0::Set_p_ADCU_DrvCmd_RollCnt(double ADCU_DrvCmd_RollCnt){
  ADCU_DrvCmd_RollCnt=BoundedValue(0.000000,15.000000,ADCU_DrvCmd_RollCnt);
  int x = (ADCU_DrvCmd_RollCnt - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[3];
  x >>= 4;
  SetByte(data_ + 6,0,4,x0);
}
/******************
signalname: ADCU_Drv_Active;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_Active(double ADCU_Drv_Active){
  ADCU_Drv_Active_=ADCU_Drv_Active;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_Active(double ADCU_Drv_Active){
  ADCU_Drv_Active=BoundedValue(0.000000,1.000000,ADCU_Drv_Active);
  int x = (ADCU_Drv_Active - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[0];
  x >>= 1;
  SetByte(data_ + 0,7,1,x0);
}
/******************
signalname: ADCU_Drv_CtrlMode;
signalclass: uint8;
StartBit: 5;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_CtrlMode(double ADCU_Drv_CtrlMode){
  ADCU_Drv_CtrlMode_=ADCU_Drv_CtrlMode;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_CtrlMode(double ADCU_Drv_CtrlMode){
  ADCU_Drv_CtrlMode=BoundedValue(0.000000,3.000000,ADCU_Drv_CtrlMode);
  int x = (ADCU_Drv_CtrlMode - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,5,2,x0);
}
/******************
signalname: ADCU_Drv_TgtGear;
signalclass: uint8;
StartBit: 0;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_TgtGear(double ADCU_Drv_TgtGear){
  ADCU_Drv_TgtGear_=ADCU_Drv_TgtGear;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_TgtGear(double ADCU_Drv_TgtGear){
  ADCU_Drv_TgtGear=BoundedValue(0.000000,3.000000,ADCU_Drv_TgtGear);
  int x = (ADCU_Drv_TgtGear - 0.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[1];
  x >>= 2;
  SetByte(data_ + 0,0,2,x0);
}
/******************
signalname: ADCU_Drv_TgtPedpos;
signalclass: uint8;
StartBit: 8;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: -100;
Minimum: -100;
Maximum: 155;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_TgtPedpos(double ADCU_Drv_TgtPedpos){
  ADCU_Drv_TgtPedpos_=ADCU_Drv_TgtPedpos;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_TgtPedpos(double ADCU_Drv_TgtPedpos){
  ADCU_Drv_TgtPedpos=BoundedValue(-100.000000,155.000000,ADCU_Drv_TgtPedpos);
  int x = (ADCU_Drv_TgtPedpos - -100.000000) / 1.000000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 1,0,8,x0);
}
/******************
signalname: ADCU_Drv_TgtVehAccSpd;
signalclass: uint8;
StartBit: 32;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: -15;
Minimum: -15;
Maximum: 10.5;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_TgtVehAccSpd(double ADCU_Drv_TgtVehAccSpd){
  ADCU_Drv_TgtVehAccSpd_=ADCU_Drv_TgtVehAccSpd;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_TgtVehAccSpd(double ADCU_Drv_TgtVehAccSpd){
  ADCU_Drv_TgtVehAccSpd=BoundedValue(-15.000000,10.500000,ADCU_Drv_TgtVehAccSpd);
  int x = (ADCU_Drv_TgtVehAccSpd - -15.000000) / 0.100000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 4,0,8,x0);
}
/******************
signalname: ADCU_Drv_TgtVehSpd0;
signalclass: uint16;
StartBit: 24;
SignalSize: 16;
ByteOrder: BigEndian;
Factor: 0.01;
Offset: -100;
Minimum: -100;
Maximum: 555.35;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_TgtVehSpd0(double ADCU_Drv_TgtVehSpd0){
  ADCU_Drv_TgtVehSpd0_=ADCU_Drv_TgtVehSpd0;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_TgtVehSpd0(double ADCU_Drv_TgtVehSpd0){
  ADCU_Drv_TgtVehSpd0=BoundedValue(-100.000000,555.350000,ADCU_Drv_TgtVehSpd0);
  int x = (ADCU_Drv_TgtVehSpd0 - -100.000000) / 0.010000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 3,0,8,x0);
  uint8_t x1 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 2,0,8,x1);
}
/******************
signalname: ADCU_Drv_VehSpdLimit;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.4;
Offset: 0;
Minimum: 0;
Maximum: 102;
******************/
void ADCU_DriveCmd0::SetADCU_Drv_VehSpdLimit(double ADCU_Drv_VehSpdLimit){
  ADCU_Drv_VehSpdLimit_=ADCU_Drv_VehSpdLimit;
}
void ADCU_DriveCmd0::Set_p_ADCU_Drv_VehSpdLimit(double ADCU_Drv_VehSpdLimit){
  ADCU_Drv_VehSpdLimit=BoundedValue(0.000000,102.000000,ADCU_Drv_VehSpdLimit);
  int x = (ADCU_Drv_VehSpdLimit - 0.000000) / 0.400000;
  uint8_t x0 = x & RANG_MASK_1_L[7];
  x >>= 8;
  SetByte(data_ + 5,0,8,x0);
}
