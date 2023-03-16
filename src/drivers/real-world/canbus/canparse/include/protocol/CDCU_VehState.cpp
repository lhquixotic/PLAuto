#include "CDCU_VehState.h"
CDCU_VehState::CDCU_VehState(){
  id_ = 0x240;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_BCM_ErrLevel_=0;
  CDCU_BMS_ErrLevel_=0;
  CDCU_Bat_LowSOC_=0;
  CDCU_CANBusOff_St_=0;
  CDCU_EHB_ErrLevel_=0;
  CDCU_EPB_ErrLevel_=0;
  CDCU_EPS_ErrLevel_=0;
  CDCU_FtCrash_St_=0;
  CDCU_LvBat_LowVolt_=0;
  CDCU_MCU_ErrLevel_=0;
  CDCU_PDU_ErrLevel_=0;
  CDCU_RrCrash_St_=0;
  CDCU_TirePresrAlarm_St_=0;
  CDCU_VehEmgcySwh_St_=0;
  CDCU_VehSt_Checksum_=0;
  CDCU_VehSt_RollCnt_=0;
  CDCU_Veh_ErrCode_=0;
  CDCU_Veh_ErrLevel_=0;
  CDCU_Veh_RunMode_=0;
  VCU_TestSig_U8_=0;
}
void CDCU_VehState::Reset(){
  CDCU_BCM_ErrLevel_=0;
  CDCU_BMS_ErrLevel_=0;
  CDCU_Bat_LowSOC_=0;
  CDCU_CANBusOff_St_=0;
  CDCU_EHB_ErrLevel_=0;
  CDCU_EPB_ErrLevel_=0;
  CDCU_EPS_ErrLevel_=0;
  CDCU_FtCrash_St_=0;
  CDCU_LvBat_LowVolt_=0;
  CDCU_MCU_ErrLevel_=0;
  CDCU_PDU_ErrLevel_=0;
  CDCU_RrCrash_St_=0;
  CDCU_TirePresrAlarm_St_=0;
  CDCU_VehEmgcySwh_St_=0;
  CDCU_VehSt_Checksum_=0;
  CDCU_VehSt_RollCnt_=0;
  CDCU_Veh_ErrCode_=0;
  CDCU_Veh_ErrLevel_=0;
  CDCU_Veh_RunMode_=0;
  VCU_TestSig_U8_=0;
}
void CDCU_VehState::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_BCM_ErrLevel();
  UpdateCDCU_BMS_ErrLevel();
  UpdateCDCU_Bat_LowSOC();
  UpdateCDCU_CANBusOff_St();
  UpdateCDCU_EHB_ErrLevel();
  UpdateCDCU_EPB_ErrLevel();
  UpdateCDCU_EPS_ErrLevel();
  UpdateCDCU_FtCrash_St();
  UpdateCDCU_LvBat_LowVolt();
  UpdateCDCU_MCU_ErrLevel();
  UpdateCDCU_PDU_ErrLevel();
  UpdateCDCU_RrCrash_St();
  UpdateCDCU_TirePresrAlarm_St();
  UpdateCDCU_VehEmgcySwh_St();
  UpdateCDCU_VehSt_Checksum();
  UpdateCDCU_VehSt_RollCnt();
  UpdateCDCU_Veh_ErrCode();
  UpdateCDCU_Veh_ErrLevel();
  UpdateCDCU_Veh_RunMode();
  UpdateVCU_TestSig_U8();
}
/******************
signalname: CDCU_BCM_ErrLevel;
signalclass: uint8;
StartBit: 30;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_BCM_ErrLevel(){
  int16_t x0 = GetByte(data_ + 3,6,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BCM_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_BCM_ErrLevel(){
  return CDCU_BCM_ErrLevel_;
}
/******************
signalname: CDCU_BMS_ErrLevel;
signalclass: uint8;
StartBit: 9;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_BMS_ErrLevel(){
  int16_t x0 = GetByte(data_ + 1,1,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BMS_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_BMS_ErrLevel(){
  return CDCU_BMS_ErrLevel_;
}
/******************
signalname: CDCU_Bat_LowSOC;
signalclass: uint8;
StartBit: 11;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_VehState::UpdateCDCU_Bat_LowSOC(){
  int16_t x0 = GetByte(data_ + 1,3,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Bat_LowSOC_ = ret;
}
double CDCU_VehState::CDCU_Bat_LowSOC(){
  return CDCU_Bat_LowSOC_;
}
/******************
signalname: CDCU_CANBusOff_St;
signalclass: uint8;
StartBit: 24;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_CANBusOff_St(){
  int16_t x0 = GetByte(data_ + 3,0,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_CANBusOff_St_ = ret;
}
double CDCU_VehState::CDCU_CANBusOff_St(){
  return CDCU_CANBusOff_St_;
}
/******************
signalname: CDCU_EHB_ErrLevel;
signalclass: uint8;
StartBit: 20;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_EHB_ErrLevel(){
  int16_t x0 = GetByte(data_ + 2,4,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EHB_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_EHB_ErrLevel(){
  return CDCU_EHB_ErrLevel_;
}
/******************
signalname: CDCU_EPB_ErrLevel;
signalclass: uint8;
StartBit: 16;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_EPB_ErrLevel(){
  int16_t x0 = GetByte(data_ + 2,0,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EPB_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_EPB_ErrLevel(){
  return CDCU_EPB_ErrLevel_;
}
/******************
signalname: CDCU_EPS_ErrLevel;
signalclass: uint8;
StartBit: 18;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_EPS_ErrLevel(){
  int16_t x0 = GetByte(data_ + 2,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_EPS_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_EPS_ErrLevel(){
  return CDCU_EPS_ErrLevel_;
}
/******************
signalname: CDCU_FtCrash_St;
signalclass: uint8;
StartBit: 15;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_VehState::UpdateCDCU_FtCrash_St(){
  int16_t x0 = GetByte(data_ + 1,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_FtCrash_St_ = ret;
}
double CDCU_VehState::CDCU_FtCrash_St(){
  return CDCU_FtCrash_St_;
}
/******************
signalname: CDCU_LvBat_LowVolt;
signalclass: uint8;
StartBit: 12;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_VehState::UpdateCDCU_LvBat_LowVolt(){
  int16_t x0 = GetByte(data_ + 1,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_LvBat_LowVolt_ = ret;
}
double CDCU_VehState::CDCU_LvBat_LowVolt(){
  return CDCU_LvBat_LowVolt_;
}
/******************
signalname: CDCU_MCU_ErrLevel;
signalclass: uint8;
StartBit: 22;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_MCU_ErrLevel(){
  int16_t x0 = GetByte(data_ + 2,6,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_MCU_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_MCU_ErrLevel(){
  return CDCU_MCU_ErrLevel_;
}
/******************
signalname: CDCU_PDU_ErrLevel;
signalclass: uint8;
StartBit: 28;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_PDU_ErrLevel(){
  int16_t x0 = GetByte(data_ + 3,4,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PDU_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_PDU_ErrLevel(){
  return CDCU_PDU_ErrLevel_;
}
/******************
signalname: CDCU_RrCrash_St;
signalclass: uint8;
StartBit: 14;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_VehState::UpdateCDCU_RrCrash_St(){
  int16_t x0 = GetByte(data_ + 1,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_RrCrash_St_ = ret;
}
double CDCU_VehState::CDCU_RrCrash_St(){
  return CDCU_RrCrash_St_;
}
/******************
signalname: CDCU_TirePresrAlarm_St;
signalclass: uint8;
StartBit: 26;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_TirePresrAlarm_St(){
  int16_t x0 = GetByte(data_ + 3,2,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_TirePresrAlarm_St_ = ret;
}
double CDCU_VehState::CDCU_TirePresrAlarm_St(){
  return CDCU_TirePresrAlarm_St_;
}
/******************
signalname: CDCU_VehEmgcySwh_St;
signalclass: uint8;
StartBit: 13;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_VehState::UpdateCDCU_VehEmgcySwh_St(){
  int16_t x0 = GetByte(data_ + 1,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehEmgcySwh_St_ = ret;
}
double CDCU_VehState::CDCU_VehEmgcySwh_St(){
  return CDCU_VehEmgcySwh_St_;
}
/******************
signalname: CDCU_VehSt_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_VehState::UpdateCDCU_VehSt_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehSt_Checksum_ = ret;
}
double CDCU_VehState::CDCU_VehSt_Checksum(){
  return CDCU_VehSt_Checksum_;
}
/******************
signalname: CDCU_VehSt_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_VehState::UpdateCDCU_VehSt_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehSt_RollCnt_ = ret;
}
double CDCU_VehState::CDCU_VehSt_RollCnt(){
  return CDCU_VehSt_RollCnt_;
}
/******************
signalname: CDCU_Veh_ErrCode;
signalclass: uint8;
StartBit: 40;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_VehState::UpdateCDCU_Veh_ErrCode(){
  int16_t x0 = GetByte(data_ + 5,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Veh_ErrCode_ = ret;
}
double CDCU_VehState::CDCU_Veh_ErrCode(){
  return CDCU_Veh_ErrCode_;
}
/******************
signalname: CDCU_Veh_ErrLevel;
signalclass: uint8;
StartBit: 0;
SignalSize: 2;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 3;
******************/
void CDCU_VehState::UpdateCDCU_Veh_ErrLevel(){
  int16_t x0 = GetByte(data_ + 0,0,2);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Veh_ErrLevel_ = ret;
}
double CDCU_VehState::CDCU_Veh_ErrLevel(){
  return CDCU_Veh_ErrLevel_;
}
/******************
signalname: CDCU_Veh_RunMode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_VehState::UpdateCDCU_Veh_RunMode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Veh_RunMode_ = ret;
}
double CDCU_VehState::CDCU_Veh_RunMode(){
  return CDCU_Veh_RunMode_;
}
/******************
signalname: VCU_TestSig_U8;
signalclass: uint8;
StartBit: 32;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 0.1;
Offset: 0;
Minimum: 0;
Maximum: 25.5;
******************/
void CDCU_VehState::UpdateVCU_TestSig_U8(){
  int16_t x0 = GetByte(data_ + 4,0,8);
  x0<<=0;
  double ret = x0 * 0.1000000000 + 0.0000000000;
  VCU_TestSig_U8_ = ret;
}
double CDCU_VehState::VCU_TestSig_U8(){
  return VCU_TestSig_U8_;
}
