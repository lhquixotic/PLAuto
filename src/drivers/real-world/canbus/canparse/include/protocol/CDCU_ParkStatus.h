#pragma once
#include "protocol.h" 
class CDCU_ParkStatus:public protocol{
  public:
    CDCU_ParkStatus();
    virtual ~CDCU_ParkStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_Park_Checksum();
    void UpdateCDCU_Park_Checksum();
    double CDCU_Park_ErrLevel();
    void UpdateCDCU_Park_ErrLevel();
    double CDCU_Park_RollCnt();
    void UpdateCDCU_Park_RollCnt();
    double CDCU_Park_St();
    void UpdateCDCU_Park_St();
    double CDCU_Park_WorkMode();
    void UpdateCDCU_Park_WorkMode();
  private:
    double CDCU_Park_Checksum_;
    double CDCU_Park_ErrLevel_;
    double CDCU_Park_RollCnt_;
    double CDCU_Park_St_;
    double CDCU_Park_WorkMode_;
};
