#include "CDCU_PowerStatus.h"
CDCU_PowerStatus::CDCU_PowerStatus(){
  id_ = 0x260;
  dlc_ = 8;
  is_extended_ = 0;
  is_error_ = 0;
  is_rtr_ = 0;
  for(int i=0;i<dlc_;i++) data_[i] = 0;
  CDCU_12VCS4PwrSupply_St_=0;
  CDCU_12VCS5PwrSupply_St_=0;
  CDCU_12VCS6PwrSupply_St_=0;
  CDCU_12VMCPwrSupply_St_=0;
  CDCU_12VMCPwrSwh_St_=0;
  CDCU_12VMCPwrdown_Req_=0;
  CDCU_12VRCPwrSupply_St_=0;
  CDCU_12VRCPwrSwh_St_=0;
  CDCU_12VRCPwrdown_Req_=0;
  CDCU_12VSC1PwrSupply_St_=0;
  CDCU_12VSC2PwrSupply_St_=0;
  CDCU_12VSC3PwrSupply_St_=0;
  CDCU_24VMCPwrSupply_St_=0;
  CDCU_24VMCPwrSwh_St_=0;
  CDCU_24VMCPwrdown_Req_=0;
  CDCU_ChasPwrSupply_St_=0;
  CDCU_ChasPwrSwh_St_=0;
  CDCU_PA12VPwrSupply_St_=0;
  CDCU_PA12VPwrSwh_St_=0;
  CDCU_PA12VPwrdown_Req_=0;
  CDCU_PA24VPwrSupply_St_=0;
  CDCU_PA24VPwrSwh_St_=0;
  CDCU_PA24VPwrdown_Req_=0;
  CDCU_PowerState_=0;
  CDCU_Pwr_BatChgSt_=0;
  CDCU_Pwr_BatLackSt_=0;
  CDCU_Pwr_BatReadySt_=0;
  CDCU_Pwr_Checksum_=0;
  CDCU_Pwr_ChgRlySt_=0;
  CDCU_Pwr_DisChgRlySt_=0;
  CDCU_Pwr_PreChgRlySt_=0;
  CDCU_Pwr_PreChgSt_=0;
  CDCU_Pwr_RollCnt_=0;
  CDCU_PwrdownTime_Chn_=0;
  CDCU_Pwrdown_Time_=0;
  CDCU_VehPwrSupply_St_=0;
  CDCU_VehPwrSwh_St_=0;
}
void CDCU_PowerStatus::Reset(){
  CDCU_12VCS4PwrSupply_St_=0;
  CDCU_12VCS5PwrSupply_St_=0;
  CDCU_12VCS6PwrSupply_St_=0;
  CDCU_12VMCPwrSupply_St_=0;
  CDCU_12VMCPwrSwh_St_=0;
  CDCU_12VMCPwrdown_Req_=0;
  CDCU_12VRCPwrSupply_St_=0;
  CDCU_12VRCPwrSwh_St_=0;
  CDCU_12VRCPwrdown_Req_=0;
  CDCU_12VSC1PwrSupply_St_=0;
  CDCU_12VSC2PwrSupply_St_=0;
  CDCU_12VSC3PwrSupply_St_=0;
  CDCU_24VMCPwrSupply_St_=0;
  CDCU_24VMCPwrSwh_St_=0;
  CDCU_24VMCPwrdown_Req_=0;
  CDCU_ChasPwrSupply_St_=0;
  CDCU_ChasPwrSwh_St_=0;
  CDCU_PA12VPwrSupply_St_=0;
  CDCU_PA12VPwrSwh_St_=0;
  CDCU_PA12VPwrdown_Req_=0;
  CDCU_PA24VPwrSupply_St_=0;
  CDCU_PA24VPwrSwh_St_=0;
  CDCU_PA24VPwrdown_Req_=0;
  CDCU_PowerState_=0;
  CDCU_Pwr_BatChgSt_=0;
  CDCU_Pwr_BatLackSt_=0;
  CDCU_Pwr_BatReadySt_=0;
  CDCU_Pwr_Checksum_=0;
  CDCU_Pwr_ChgRlySt_=0;
  CDCU_Pwr_DisChgRlySt_=0;
  CDCU_Pwr_PreChgRlySt_=0;
  CDCU_Pwr_PreChgSt_=0;
  CDCU_Pwr_RollCnt_=0;
  CDCU_PwrdownTime_Chn_=0;
  CDCU_Pwrdown_Time_=0;
  CDCU_VehPwrSupply_St_=0;
  CDCU_VehPwrSwh_St_=0;
}
void CDCU_PowerStatus::Update(uint8_t *data){
  for(int i=0;i<dlc_;i++) data_[i] = data[i];
  UpdateCDCU_12VCS4PwrSupply_St();
  UpdateCDCU_12VCS5PwrSupply_St();
  UpdateCDCU_12VCS6PwrSupply_St();
  UpdateCDCU_12VMCPwrSupply_St();
  UpdateCDCU_12VMCPwrSwh_St();
  UpdateCDCU_12VMCPwrdown_Req();
  UpdateCDCU_12VRCPwrSupply_St();
  UpdateCDCU_12VRCPwrSwh_St();
  UpdateCDCU_12VRCPwrdown_Req();
  UpdateCDCU_12VSC1PwrSupply_St();
  UpdateCDCU_12VSC2PwrSupply_St();
  UpdateCDCU_12VSC3PwrSupply_St();
  UpdateCDCU_24VMCPwrSupply_St();
  UpdateCDCU_24VMCPwrSwh_St();
  UpdateCDCU_24VMCPwrdown_Req();
  UpdateCDCU_ChasPwrSupply_St();
  UpdateCDCU_ChasPwrSwh_St();
  UpdateCDCU_PA12VPwrSupply_St();
  UpdateCDCU_PA12VPwrSwh_St();
  UpdateCDCU_PA12VPwrdown_Req();
  UpdateCDCU_PA24VPwrSupply_St();
  UpdateCDCU_PA24VPwrSwh_St();
  UpdateCDCU_PA24VPwrdown_Req();
  UpdateCDCU_PowerState();
  UpdateCDCU_Pwr_BatChgSt();
  UpdateCDCU_Pwr_BatLackSt();
  UpdateCDCU_Pwr_BatReadySt();
  UpdateCDCU_Pwr_Checksum();
  UpdateCDCU_Pwr_ChgRlySt();
  UpdateCDCU_Pwr_DisChgRlySt();
  UpdateCDCU_Pwr_PreChgRlySt();
  UpdateCDCU_Pwr_PreChgSt();
  UpdateCDCU_Pwr_RollCnt();
  UpdateCDCU_PwrdownTime_Chn();
  UpdateCDCU_Pwrdown_Time();
  UpdateCDCU_VehPwrSupply_St();
  UpdateCDCU_VehPwrSwh_St();
}
/******************
signalname: CDCU_12VCS4PwrSupply_St;
signalclass: uint8;
StartBit: 28;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VCS4PwrSupply_St(){
  int16_t x0 = GetByte(data_ + 3,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VCS4PwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VCS4PwrSupply_St(){
  return CDCU_12VCS4PwrSupply_St_;
}
/******************
signalname: CDCU_12VCS5PwrSupply_St;
signalclass: uint8;
StartBit: 27;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VCS5PwrSupply_St(){
  int16_t x0 = GetByte(data_ + 3,3,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VCS5PwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VCS5PwrSupply_St(){
  return CDCU_12VCS5PwrSupply_St_;
}
/******************
signalname: CDCU_12VCS6PwrSupply_St;
signalclass: uint8;
StartBit: 26;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VCS6PwrSupply_St(){
  int16_t x0 = GetByte(data_ + 3,2,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VCS6PwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VCS6PwrSupply_St(){
  return CDCU_12VCS6PwrSupply_St_;
}
/******************
signalname: CDCU_12VMCPwrSupply_St;
signalclass: uint8;
StartBit: 5;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VMCPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VMCPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VMCPwrSupply_St(){
  return CDCU_12VMCPwrSupply_St_;
}
/******************
signalname: CDCU_12VMCPwrSwh_St;
signalclass: uint8;
StartBit: 13;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VMCPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 1,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VMCPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VMCPwrSwh_St(){
  return CDCU_12VMCPwrSwh_St_;
}
/******************
signalname: CDCU_12VMCPwrdown_Req;
signalclass: uint8;
StartBit: 33;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VMCPwrdown_Req(){
  int16_t x0 = GetByte(data_ + 4,1,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VMCPwrdown_Req_ = ret;
}
double CDCU_PowerStatus::CDCU_12VMCPwrdown_Req(){
  return CDCU_12VMCPwrdown_Req_;
}
/******************
signalname: CDCU_12VRCPwrSupply_St;
signalclass: uint8;
StartBit: 4;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VRCPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VRCPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VRCPwrSupply_St(){
  return CDCU_12VRCPwrSupply_St_;
}
/******************
signalname: CDCU_12VRCPwrSwh_St;
signalclass: uint8;
StartBit: 12;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VRCPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 1,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VRCPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VRCPwrSwh_St(){
  return CDCU_12VRCPwrSwh_St_;
}
/******************
signalname: CDCU_12VRCPwrdown_Req;
signalclass: uint8;
StartBit: 32;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VRCPwrdown_Req(){
  int16_t x0 = GetByte(data_ + 4,0,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VRCPwrdown_Req_ = ret;
}
double CDCU_PowerStatus::CDCU_12VRCPwrdown_Req(){
  return CDCU_12VRCPwrdown_Req_;
}
/******************
signalname: CDCU_12VSC1PwrSupply_St;
signalclass: uint8;
StartBit: 31;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VSC1PwrSupply_St(){
  int16_t x0 = GetByte(data_ + 3,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VSC1PwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VSC1PwrSupply_St(){
  return CDCU_12VSC1PwrSupply_St_;
}
/******************
signalname: CDCU_12VSC2PwrSupply_St;
signalclass: uint8;
StartBit: 30;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VSC2PwrSupply_St(){
  int16_t x0 = GetByte(data_ + 3,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VSC2PwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VSC2PwrSupply_St(){
  return CDCU_12VSC2PwrSupply_St_;
}
/******************
signalname: CDCU_12VSC3PwrSupply_St;
signalclass: uint8;
StartBit: 29;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_12VSC3PwrSupply_St(){
  int16_t x0 = GetByte(data_ + 3,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_12VSC3PwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_12VSC3PwrSupply_St(){
  return CDCU_12VSC3PwrSupply_St_;
}
/******************
signalname: CDCU_24VMCPwrSupply_St;
signalclass: uint8;
StartBit: 3;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_24VMCPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,3,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_24VMCPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_24VMCPwrSupply_St(){
  return CDCU_24VMCPwrSupply_St_;
}
/******************
signalname: CDCU_24VMCPwrSwh_St;
signalclass: uint8;
StartBit: 11;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_24VMCPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 1,3,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_24VMCPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_24VMCPwrSwh_St(){
  return CDCU_24VMCPwrSwh_St_;
}
/******************
signalname: CDCU_24VMCPwrdown_Req;
signalclass: uint8;
StartBit: 47;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_24VMCPwrdown_Req(){
  int16_t x0 = GetByte(data_ + 5,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_24VMCPwrdown_Req_ = ret;
}
double CDCU_PowerStatus::CDCU_24VMCPwrdown_Req(){
  return CDCU_24VMCPwrdown_Req_;
}
/******************
signalname: CDCU_ChasPwrSupply_St;
signalclass: uint8;
StartBit: 6;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_ChasPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_ChasPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_ChasPwrSupply_St(){
  return CDCU_ChasPwrSupply_St_;
}
/******************
signalname: CDCU_ChasPwrSwh_St;
signalclass: uint8;
StartBit: 14;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_ChasPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 1,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_ChasPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_ChasPwrSwh_St(){
  return CDCU_ChasPwrSwh_St_;
}
/******************
signalname: CDCU_PA12VPwrSupply_St;
signalclass: uint8;
StartBit: 2;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_PA12VPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,2,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PA12VPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_PA12VPwrSupply_St(){
  return CDCU_PA12VPwrSupply_St_;
}
/******************
signalname: CDCU_PA12VPwrSwh_St;
signalclass: uint8;
StartBit: 25;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_PA12VPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 3,1,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PA12VPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_PA12VPwrSwh_St(){
  return CDCU_PA12VPwrSwh_St_;
}
/******************
signalname: CDCU_PA12VPwrdown_Req;
signalclass: uint8;
StartBit: 46;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_PA12VPwrdown_Req(){
  int16_t x0 = GetByte(data_ + 5,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PA12VPwrdown_Req_ = ret;
}
double CDCU_PowerStatus::CDCU_PA12VPwrdown_Req(){
  return CDCU_PA12VPwrdown_Req_;
}
/******************
signalname: CDCU_PA24VPwrSupply_St;
signalclass: uint8;
StartBit: 1;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_PA24VPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,1,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PA24VPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_PA24VPwrSupply_St(){
  return CDCU_PA24VPwrSupply_St_;
}
/******************
signalname: CDCU_PA24VPwrSwh_St;
signalclass: uint8;
StartBit: 24;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_PA24VPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 3,0,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PA24VPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_PA24VPwrSwh_St(){
  return CDCU_PA24VPwrSwh_St_;
}
/******************
signalname: CDCU_PA24VPwrdown_Req;
signalclass: uint8;
StartBit: 45;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_PA24VPwrdown_Req(){
  int16_t x0 = GetByte(data_ + 5,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PA24VPwrdown_Req_ = ret;
}
double CDCU_PowerStatus::CDCU_PA24VPwrdown_Req(){
  return CDCU_PA24VPwrdown_Req_;
}
/******************
signalname: CDCU_PowerState;
signalclass: uint8;
StartBit: 8;
SignalSize: 3;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 7;
******************/
void CDCU_PowerStatus::UpdateCDCU_PowerState(){
  int16_t x0 = GetByte(data_ + 1,0,3);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PowerState_ = ret;
}
double CDCU_PowerStatus::CDCU_PowerState(){
  return CDCU_PowerState_;
}
/******************
signalname: CDCU_Pwr_BatChgSt;
signalclass: uint8;
StartBit: 22;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_BatChgSt(){
  int16_t x0 = GetByte(data_ + 2,6,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_BatChgSt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_BatChgSt(){
  return CDCU_Pwr_BatChgSt_;
}
/******************
signalname: CDCU_Pwr_BatLackSt;
signalclass: uint8;
StartBit: 21;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_BatLackSt(){
  int16_t x0 = GetByte(data_ + 2,5,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_BatLackSt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_BatLackSt(){
  return CDCU_Pwr_BatLackSt_;
}
/******************
signalname: CDCU_Pwr_BatReadySt;
signalclass: uint8;
StartBit: 20;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_BatReadySt(){
  int16_t x0 = GetByte(data_ + 2,4,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_BatReadySt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_BatReadySt(){
  return CDCU_Pwr_BatReadySt_;
}
/******************
signalname: CDCU_Pwr_Checksum;
signalclass: uint8;
StartBit: 56;
SignalSize: 8;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 255;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_Checksum(){
  int16_t x0 = GetByte(data_ + 7,0,8);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_Checksum_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_Checksum(){
  return CDCU_Pwr_Checksum_;
}
/******************
signalname: CDCU_Pwr_ChgRlySt;
signalclass: uint8;
StartBit: 18;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_ChgRlySt(){
  int16_t x0 = GetByte(data_ + 2,2,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_ChgRlySt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_ChgRlySt(){
  return CDCU_Pwr_ChgRlySt_;
}
/******************
signalname: CDCU_Pwr_DisChgRlySt;
signalclass: uint8;
StartBit: 19;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_DisChgRlySt(){
  int16_t x0 = GetByte(data_ + 2,3,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_DisChgRlySt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_DisChgRlySt(){
  return CDCU_Pwr_DisChgRlySt_;
}
/******************
signalname: CDCU_Pwr_PreChgRlySt;
signalclass: uint8;
StartBit: 17;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_PreChgRlySt(){
  int16_t x0 = GetByte(data_ + 2,1,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_PreChgRlySt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_PreChgRlySt(){
  return CDCU_Pwr_PreChgRlySt_;
}
/******************
signalname: CDCU_Pwr_PreChgSt;
signalclass: uint8;
StartBit: 23;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_PreChgSt(){
  int16_t x0 = GetByte(data_ + 2,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_PreChgSt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_PreChgSt(){
  return CDCU_Pwr_PreChgSt_;
}
/******************
signalname: CDCU_Pwr_RollCnt;
signalclass: uint8;
StartBit: 48;
SignalSize: 4;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 15;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwr_RollCnt(){
  int16_t x0 = GetByte(data_ + 6,0,4);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwr_RollCnt_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwr_RollCnt(){
  return CDCU_Pwr_RollCnt_;
}
/******************
signalname: CDCU_PwrdownTime_Chn;
signalclass: uint8;
StartBit: 42;
SignalSize: 3;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 7;
******************/
void CDCU_PowerStatus::UpdateCDCU_PwrdownTime_Chn(){
  int16_t x0 = GetByte(data_ + 5,2,3);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_PwrdownTime_Chn_ = ret;
}
double CDCU_PowerStatus::CDCU_PwrdownTime_Chn(){
  return CDCU_PwrdownTime_Chn_;
}
/******************
signalname: CDCU_Pwrdown_Time;
signalclass: uint8;
StartBit: 52;
SignalSize: 6;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 63;
******************/
void CDCU_PowerStatus::UpdateCDCU_Pwrdown_Time(){
  int16_t x0 = GetByte(data_ + 6,4,4);
  int16_t x1 = GetByte(data_ + 5,0,2);
  x0<<=0;
  x1<<=8;
  x0|=x1;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_Pwrdown_Time_ = ret;
}
double CDCU_PowerStatus::CDCU_Pwrdown_Time(){
  return CDCU_Pwrdown_Time_;
}
/******************
signalname: CDCU_VehPwrSupply_St;
signalclass: uint8;
StartBit: 7;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_VehPwrSupply_St(){
  int16_t x0 = GetByte(data_ + 0,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehPwrSupply_St_ = ret;
}
double CDCU_PowerStatus::CDCU_VehPwrSupply_St(){
  return CDCU_VehPwrSupply_St_;
}
/******************
signalname: CDCU_VehPwrSwh_St;
signalclass: uint8;
StartBit: 15;
SignalSize: 1;
ByteOrder: BigEndian;
Factor: 1;
Offset: 0;
Minimum: 0;
Maximum: 1;
******************/
void CDCU_PowerStatus::UpdateCDCU_VehPwrSwh_St(){
  int16_t x0 = GetByte(data_ + 1,7,1);
  x0<<=0;
  double ret = x0 * 1.0000000000 + 0.0000000000;
  CDCU_VehPwrSwh_St_ = ret;
}
double CDCU_PowerStatus::CDCU_VehPwrSwh_St(){
  return CDCU_VehPwrSwh_St_;
}
