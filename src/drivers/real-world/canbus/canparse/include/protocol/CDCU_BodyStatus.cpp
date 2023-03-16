#include "CDCU_BodyStatus.h"
CDCU_BodyStatus::CDCU_BodyStatus(){
  id_ = 0x219;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_AcostOptic_WorkMode_=0;
  CDCU_BackLamp_St_=0;
  CDCU_BodyStatus_Checksum_=0;
  CDCU_BodyStatus_RollCnt_=0;
  CDCU_BrkLamp_St_=0;
  CDCU_Buzzer_St_=0;
  CDCU_DblFlashLamp_St_=0;
  CDCU_FogLamp_St_=0;
  CDCU_HeadLamp_St_=0;
  CDCU_Horn_St_=0;
  CDCU_RunLamp_St_=0;
  CDCU_TurnLLamp_St_=0;
  CDCU_TurnRLamp_St_=0;
  CDCU_WidthLamp_St_=0;
}
void CDCU_BodyStatus::Reset(){
  CDCU_AcostOptic_WorkMode_=0;
  CDCU_BackLamp_St_=0;
  CDCU_BodyStatus_Checksum_=0;
  CDCU_BodyStatus_RollCnt_=0;
  CDCU_BrkLamp_St_=0;
  CDCU_Buzzer_St_=0;
  CDCU_DblFlashLamp_St_=0;
  CDCU_FogLamp_St_=0;
  CDCU_HeadLamp_St_=0;
  CDCU_Horn_St_=0;
  CDCU_RunLamp_St_=0;
  CDCU_TurnLLamp_St_=0;
  CDCU_TurnRLamp_St_=0;
  CDCU_WidthLamp_St_=0;
}
void CDCU_BodyStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_AcostOptic_WorkMode();
  UpdateCDCU_BackLamp_St();
  UpdateCDCU_BodyStatus_Checksum();
  UpdateCDCU_BodyStatus_RollCnt();
  UpdateCDCU_BrkLamp_St();
  UpdateCDCU_Buzzer_St();
  UpdateCDCU_DblFlashLamp_St();
  UpdateCDCU_FogLamp_St();
  UpdateCDCU_HeadLamp_St();
  UpdateCDCU_Horn_St();
  UpdateCDCU_RunLamp_St();
  UpdateCDCU_TurnLLamp_St();
  UpdateCDCU_TurnRLamp_St();
  UpdateCDCU_WidthLamp_St();
}
/******************
signalname: CDCU_AcostOptic_WorkMode;
signalclass: uint8;
StartBit: 4;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_BodyStatus::UpdateCDCU_AcostOptic_WorkMode(){
  int16_t x0 = GetByte(data_ + 0,4,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_AcostOptic_WorkMode_ = ret;
}
double CDCU_BodyStatus::CDCU_AcostOptic_WorkMode(){
  return CDCU_AcostOptic_WorkMode_;
}
/******************
signalname: CDCU_BackLamp_St;
signalclass: uint8;
StartBit: 11;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_BackLamp_St(){
  int16_t x0 = GetByte(data_ + 1,3,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BackLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_BackLamp_St(){
  return CDCU_BackLamp_St_;
}
/******************
signalname: CDCU_BodyStatus_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_BodyStatus::UpdateCDCU_BodyStatus_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BodyStatus_Checksum_ = ret;
}
double CDCU_BodyStatus::CDCU_BodyStatus_Checksum(){
  return CDCU_BodyStatus_Checksum_;
}
/******************
signalname: CDCU_BodyStatus_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_BodyStatus::UpdateCDCU_BodyStatus_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BodyStatus_RollCnt_ = ret;
}
double CDCU_BodyStatus::CDCU_BodyStatus_RollCnt(){
  return CDCU_BodyStatus_RollCnt_;
}
/******************
signalname: CDCU_BrkLamp_St;
signalclass: uint8;
StartBit: 23;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_BrkLamp_St(){
  int16_t x0 = GetByte(data_ + 2,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_BrkLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_BrkLamp_St(){
  return CDCU_BrkLamp_St_;
}
/******************
signalname: CDCU_Buzzer_St;
signalclass: uint8;
StartBit: 10;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_Buzzer_St(){
  int16_t x0 = GetByte(data_ + 1,2,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Buzzer_St_ = ret;
}
double CDCU_BodyStatus::CDCU_Buzzer_St(){
  return CDCU_Buzzer_St_;
}
/******************
signalname: CDCU_DblFlashLamp_St;
signalclass: uint8;
StartBit: 14;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_DblFlashLamp_St(){
  int16_t x0 = GetByte(data_ + 1,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_DblFlashLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_DblFlashLamp_St(){
  return CDCU_DblFlashLamp_St_;
}
/******************
signalname: CDCU_FogLamp_St;
signalclass: uint8;
StartBit: 22;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_FogLamp_St(){
  int16_t x0 = GetByte(data_ + 2,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_FogLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_FogLamp_St(){
  return CDCU_FogLamp_St_;
}
/******************
signalname: CDCU_HeadLamp_St;
signalclass: uint8;
StartBit: 15;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_HeadLamp_St(){
  int16_t x0 = GetByte(data_ + 1,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_HeadLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_HeadLamp_St(){
  return CDCU_HeadLamp_St_;
}
/******************
signalname: CDCU_Horn_St;
signalclass: uint8;
StartBit: 9;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_Horn_St(){
  int16_t x0 = GetByte(data_ + 1,1,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Horn_St_ = ret;
}
double CDCU_BodyStatus::CDCU_Horn_St(){
  return CDCU_Horn_St_;
}
/******************
signalname: CDCU_RunLamp_St;
signalclass: uint8;
StartBit: 8;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_RunLamp_St(){
  int16_t x0 = GetByte(data_ + 1,0,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_RunLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_RunLamp_St(){
  return CDCU_RunLamp_St_;
}
/******************
signalname: CDCU_TurnLLamp_St;
signalclass: uint8;
StartBit: 13;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_TurnLLamp_St(){
  int16_t x0 = GetByte(data_ + 1,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_TurnLLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_TurnLLamp_St(){
  return CDCU_TurnLLamp_St_;
}
/******************
signalname: CDCU_TurnRLamp_St;
signalclass: uint8;
StartBit: 12;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_TurnRLamp_St(){
  int16_t x0 = GetByte(data_ + 1,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_TurnRLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_TurnRLamp_St(){
  return CDCU_TurnRLamp_St_;
}
/******************
signalname: CDCU_WidthLamp_St;
signalclass: uint8;
StartBit: 31;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_BodyStatus::UpdateCDCU_WidthLamp_St(){
  int16_t x0 = GetByte(data_ + 3,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_WidthLamp_St_ = ret;
}
double CDCU_BodyStatus::CDCU_WidthLamp_St(){
  return CDCU_WidthLamp_St_;
}
