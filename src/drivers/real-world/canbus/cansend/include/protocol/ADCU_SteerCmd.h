#pragma once 
#include "protocol.h" 
class ADCU_SteerCmd:public protocol{
  public:
    ADCU_SteerCmd();
    virtual ~ADCU_SteerCmd()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double ADCU_StrCmd_Checksum();
    void SetADCU_StrCmd_Checksum(double ADCU_StrCmd_Checksum);
    void Set_p_ADCU_StrCmd_Checksum(double ADCU_StrCmd_Checksum);
    double ADCU_StrCmd_RollCnt();
    void SetADCU_StrCmd_RollCnt(double ADCU_StrCmd_RollCnt);
    void Set_p_ADCU_StrCmd_RollCnt(double ADCU_StrCmd_RollCnt);
    double ADCU_Str_Active();
    void SetADCU_Str_Active(double ADCU_Str_Active);
    void Set_p_ADCU_Str_Active(double ADCU_Str_Active);
    double ADCU_Str_CtrlMode();
    void SetADCU_Str_CtrlMode(double ADCU_Str_CtrlMode);
    void Set_p_ADCU_Str_CtrlMode(double ADCU_Str_CtrlMode);
    double ADCU_Str_TgtAngle();
    void SetADCU_Str_TgtAngle(double ADCU_Str_TgtAngle);
    void Set_p_ADCU_Str_TgtAngle(double ADCU_Str_TgtAngle);
    double ADCU_Str_TgtAngleSpd();
    void SetADCU_Str_TgtAngleSpd(double ADCU_Str_TgtAngleSpd);
    void Set_p_ADCU_Str_TgtAngleSpd(double ADCU_Str_TgtAngleSpd);
    double ADCU_Str_TgtCurvature();
    void SetADCU_Str_TgtCurvature(double ADCU_Str_TgtCurvature);
    void Set_p_ADCU_Str_TgtCurvature(double ADCU_Str_TgtCurvature);
  private:
    double ADCU_StrCmd_Checksum_;
    double ADCU_StrCmd_RollCnt_;
    double ADCU_Str_Active_;
    double ADCU_Str_CtrlMode_;
    double ADCU_Str_TgtAngle_;
    double ADCU_Str_TgtAngleSpd_;
    double ADCU_Str_TgtCurvature_;
};
