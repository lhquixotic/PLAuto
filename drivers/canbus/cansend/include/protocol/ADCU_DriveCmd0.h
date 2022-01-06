#pragma once 
#include "protocol.h" 
class ADCU_DriveCmd0:public protocol{
  public:
    ADCU_DriveCmd0();
    virtual ~ADCU_DriveCmd0()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double ADCU_DrvCmd_Checksum();
    void SetADCU_DrvCmd_Checksum(double ADCU_DrvCmd_Checksum);
    void Set_p_ADCU_DrvCmd_Checksum(double ADCU_DrvCmd_Checksum);
    double ADCU_DrvCmd_RollCnt();
    void SetADCU_DrvCmd_RollCnt(double ADCU_DrvCmd_RollCnt);
    void Set_p_ADCU_DrvCmd_RollCnt(double ADCU_DrvCmd_RollCnt);
    double ADCU_Drv_Active();
    void SetADCU_Drv_Active(double ADCU_Drv_Active);
    void Set_p_ADCU_Drv_Active(double ADCU_Drv_Active);
    double ADCU_Drv_CtrlMode();
    void SetADCU_Drv_CtrlMode(double ADCU_Drv_CtrlMode);
    void Set_p_ADCU_Drv_CtrlMode(double ADCU_Drv_CtrlMode);
    double ADCU_Drv_TgtGear();
    void SetADCU_Drv_TgtGear(double ADCU_Drv_TgtGear);
    void Set_p_ADCU_Drv_TgtGear(double ADCU_Drv_TgtGear);
    double ADCU_Drv_TgtPedpos();
    void SetADCU_Drv_TgtPedpos(double ADCU_Drv_TgtPedpos);
    void Set_p_ADCU_Drv_TgtPedpos(double ADCU_Drv_TgtPedpos);
    double ADCU_Drv_TgtVehAccSpd();
    void SetADCU_Drv_TgtVehAccSpd(double ADCU_Drv_TgtVehAccSpd);
    void Set_p_ADCU_Drv_TgtVehAccSpd(double ADCU_Drv_TgtVehAccSpd);
    double ADCU_Drv_TgtVehSpd0();
    void SetADCU_Drv_TgtVehSpd0(double ADCU_Drv_TgtVehSpd0);
    void Set_p_ADCU_Drv_TgtVehSpd0(double ADCU_Drv_TgtVehSpd0);
    double ADCU_Drv_VehSpdLimit();
    void SetADCU_Drv_VehSpdLimit(double ADCU_Drv_VehSpdLimit);
    void Set_p_ADCU_Drv_VehSpdLimit(double ADCU_Drv_VehSpdLimit);
  private:
    double ADCU_DrvCmd_Checksum_;
    double ADCU_DrvCmd_RollCnt_;
    double ADCU_Drv_Active_;
    double ADCU_Drv_CtrlMode_;
    double ADCU_Drv_TgtGear_;
    double ADCU_Drv_TgtPedpos_;
    double ADCU_Drv_TgtVehAccSpd_;
    double ADCU_Drv_TgtVehSpd0_;
    double ADCU_Drv_VehSpdLimit_;
};
