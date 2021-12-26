#pragma once
#include "protocol.h" 
class CDCU_BodyStatus:public protocol{
  public:
    CDCU_BodyStatus();
    virtual ~CDCU_BodyStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_AcostOptic_WorkMode();
    void UpdateCDCU_AcostOptic_WorkMode();
    double CDCU_BackLamp_St();
    void UpdateCDCU_BackLamp_St();
    double CDCU_BodyStatus_Checksum();
    void UpdateCDCU_BodyStatus_Checksum();
    double CDCU_BodyStatus_RollCnt();
    void UpdateCDCU_BodyStatus_RollCnt();
    double CDCU_BrkLamp_St();
    void UpdateCDCU_BrkLamp_St();
    double CDCU_Buzzer_St();
    void UpdateCDCU_Buzzer_St();
    double CDCU_DblFlashLamp_St();
    void UpdateCDCU_DblFlashLamp_St();
    double CDCU_FogLamp_St();
    void UpdateCDCU_FogLamp_St();
    double CDCU_HeadLamp_St();
    void UpdateCDCU_HeadLamp_St();
    double CDCU_Horn_St();
    void UpdateCDCU_Horn_St();
    double CDCU_RunLamp_St();
    void UpdateCDCU_RunLamp_St();
    double CDCU_TurnLLamp_St();
    void UpdateCDCU_TurnLLamp_St();
    double CDCU_TurnRLamp_St();
    void UpdateCDCU_TurnRLamp_St();
    double CDCU_WidthLamp_St();
    void UpdateCDCU_WidthLamp_St();
  private:
    double CDCU_AcostOptic_WorkMode_;
    double CDCU_BackLamp_St_;
    double CDCU_BodyStatus_Checksum_;
    double CDCU_BodyStatus_RollCnt_;
    double CDCU_BrkLamp_St_;
    double CDCU_Buzzer_St_;
    double CDCU_DblFlashLamp_St_;
    double CDCU_FogLamp_St_;
    double CDCU_HeadLamp_St_;
    double CDCU_Horn_St_;
    double CDCU_RunLamp_St_;
    double CDCU_TurnLLamp_St_;
    double CDCU_TurnRLamp_St_;
    double CDCU_WidthLamp_St_;
};
