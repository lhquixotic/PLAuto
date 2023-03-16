#pragma once
#include "protocol.h" 
class CDCU_BrakeStatus:public protocol{
  public:
    CDCU_BrakeStatus();
    virtual ~CDCU_BrakeStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_BrkSt_Checksum();
    void UpdateCDCU_BrkSt_Checksum();
    double CDCU_BrkSt_RollCnt();
    void UpdateCDCU_BrkSt_RollCnt();
    double CDCU_EHB_BrkMode();
    void UpdateCDCU_EHB_BrkMode();
    double CDCU_EHB_BrkPedpos();
    void UpdateCDCU_EHB_BrkPedpos();
    double CDCU_EHB_BrkPresur();
    void UpdateCDCU_EHB_BrkPresur();
    double CDCU_EHB_ErrLevel();
    void UpdateCDCU_EHB_ErrLevel();
    double CDCU_EHB_WorkMode();
    void UpdateCDCU_EHB_WorkMode();
  private:
    double CDCU_BrkSt_Checksum_;
    double CDCU_BrkSt_RollCnt_;
    double CDCU_EHB_BrkMode_;
    double CDCU_EHB_BrkPedpos_;
    double CDCU_EHB_BrkPresur_;
    double CDCU_EHB_ErrLevel_;
    double CDCU_EHB_WorkMode_;
};
