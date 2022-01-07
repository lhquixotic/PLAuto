#pragma once 
#include "protocol.h" 
class ADCU_BrakeCmd:public protocol{
  public:
    ADCU_BrakeCmd();
    virtual ~ADCU_BrakeCmd()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double ADCU_BrkCmd_Checksum();
    void SetADCU_BrkCmd_Checksum(double ADCU_BrkCmd_Checksum);
    void Set_p_ADCU_BrkCmd_Checksum(double ADCU_BrkCmd_Checksum);
    double ADCU_BrkCmd_RollCnt();
    void SetADCU_BrkCmd_RollCnt(double ADCU_BrkCmd_RollCnt);
    void Set_p_ADCU_BrkCmd_RollCnt(double ADCU_BrkCmd_RollCnt);
    double ADCU_Brk_Active();
    void SetADCU_Brk_Active(double ADCU_Brk_Active);
    void Set_p_ADCU_Brk_Active(double ADCU_Brk_Active);
    double ADCU_Brk_CtrlMode();
    void SetADCU_Brk_CtrlMode(double ADCU_Brk_CtrlMode);
    void Set_p_ADCU_Brk_CtrlMode(double ADCU_Brk_CtrlMode);
    double ADCU_Brk_TgtAccSpd();
    void SetADCU_Brk_TgtAccSpd(double ADCU_Brk_TgtAccSpd);
    void Set_p_ADCU_Brk_TgtAccSpd(double ADCU_Brk_TgtAccSpd);
    double ADCU_Brk_TgtPedpos();
    void SetADCU_Brk_TgtPedpos(double ADCU_Brk_TgtPedpos);
    void Set_p_ADCU_Brk_TgtPedpos(double ADCU_Brk_TgtPedpos);
    double ADCU_Brk_TgtPress();
    void SetADCU_Brk_TgtPress(double ADCU_Brk_TgtPress);
    void Set_p_ADCU_Brk_TgtPress(double ADCU_Brk_TgtPress);
  private:
    double ADCU_BrkCmd_Checksum_;
    double ADCU_BrkCmd_RollCnt_;
    double ADCU_Brk_Active_;
    double ADCU_Brk_CtrlMode_;
    double ADCU_Brk_TgtAccSpd_;
    double ADCU_Brk_TgtPedpos_;
    double ADCU_Brk_TgtPress_;
};
