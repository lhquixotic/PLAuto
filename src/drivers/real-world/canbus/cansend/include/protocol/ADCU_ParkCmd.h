#pragma once 
#include "protocol.h" 
class ADCU_ParkCmd:public protocol{
  public:
    ADCU_ParkCmd();
    virtual ~ADCU_ParkCmd()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double ADCU_PrkCmd_Checksum();
    void SetADCU_PrkCmd_Checksum(double ADCU_PrkCmd_Checksum);
    void Set_p_ADCU_PrkCmd_Checksum(double ADCU_PrkCmd_Checksum);
    double ADCU_PrkCmd_RollCnt();
    void SetADCU_PrkCmd_RollCnt(double ADCU_PrkCmd_RollCnt);
    void Set_p_ADCU_PrkCmd_RollCnt(double ADCU_PrkCmd_RollCnt);
    double ADCU_Prk_Active();
    void SetADCU_Prk_Active(double ADCU_Prk_Active);
    void Set_p_ADCU_Prk_Active(double ADCU_Prk_Active);
    double ADCU_Prk_Enable();
    void SetADCU_Prk_Enable(double ADCU_Prk_Enable);
    void Set_p_ADCU_Prk_Enable(double ADCU_Prk_Enable);
  private:
    double ADCU_PrkCmd_Checksum_;
    double ADCU_PrkCmd_RollCnt_;
    double ADCU_Prk_Active_;
    double ADCU_Prk_Enable_;
};
