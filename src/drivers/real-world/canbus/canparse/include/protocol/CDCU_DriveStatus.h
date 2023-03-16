#pragma once
#include "protocol.h" 
class CDCU_DriveStatus:public protocol{
  public:
    CDCU_DriveStatus();
    virtual ~CDCU_DriveStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_DrvSt_Checksum();
    void UpdateCDCU_DrvSt_Checksum();
    double CDCU_DrvSt_RollCnt();
    void UpdateCDCU_DrvSt_RollCnt();
    double CDCU_MCU_ErrLevel();
    void UpdateCDCU_MCU_ErrLevel();
    double CDCU_MCU_GearAct();
    void UpdateCDCU_MCU_GearAct();
    double CDCU_MCU_MtrCurt();
    void UpdateCDCU_MCU_MtrCurt();
    double CDCU_MCU_MtrSpd();
    void UpdateCDCU_MCU_MtrSpd();
    double CDCU_MCU_RunDir();
    void UpdateCDCU_MCU_RunDir();
    double CDCU_MCU_ThrotAct();
    void UpdateCDCU_MCU_ThrotAct();
    double CDCU_MCU_WorkMode();
    void UpdateCDCU_MCU_WorkMode();
  private:
    double CDCU_DrvSt_Checksum_;
    double CDCU_DrvSt_RollCnt_;
    double CDCU_MCU_ErrLevel_;
    double CDCU_MCU_GearAct_;
    double CDCU_MCU_MtrCurt_;
    double CDCU_MCU_MtrSpd_;
    double CDCU_MCU_RunDir_;
    double CDCU_MCU_ThrotAct_;
    double CDCU_MCU_WorkMode_;
};
