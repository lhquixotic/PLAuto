#pragma once
#include "protocol.h" 
class CDCU_SteerStatus:public protocol{
  public:
    CDCU_SteerStatus();
    virtual ~CDCU_SteerStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_EPS_ErrLevel();
    void UpdateCDCU_EPS_ErrLevel();
    double CDCU_EPS_StrTrq();
    void UpdateCDCU_EPS_StrTrq();
    double CDCU_EPS_StrWhlAngle();
    void UpdateCDCU_EPS_StrWhlAngle();
    double CDCU_EPS_WhlSpd();
    void UpdateCDCU_EPS_WhlSpd();
    double CDCU_EPS_WorkMode();
    void UpdateCDCU_EPS_WorkMode();
    double CDCU_StrSt_Checksum();
    void UpdateCDCU_StrSt_Checksum();
    double CDCU_StrSt_RollCnt();
    void UpdateCDCU_StrSt_RollCnt();
  private:
    double CDCU_EPS_ErrLevel_;
    double CDCU_EPS_StrTrq_;
    double CDCU_EPS_StrWhlAngle_;
    double CDCU_EPS_WhlSpd_;
    double CDCU_EPS_WorkMode_;
    double CDCU_StrSt_Checksum_;
    double CDCU_StrSt_RollCnt_;
};
