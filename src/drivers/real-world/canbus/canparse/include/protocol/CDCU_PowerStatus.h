#pragma once
#include "protocol.h" 
class CDCU_PowerStatus:public protocol{
  public:
    CDCU_PowerStatus();
    virtual ~CDCU_PowerStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_12VCS4PwrSupply_St();
    void UpdateCDCU_12VCS4PwrSupply_St();
    double CDCU_12VCS5PwrSupply_St();
    void UpdateCDCU_12VCS5PwrSupply_St();
    double CDCU_12VCS6PwrSupply_St();
    void UpdateCDCU_12VCS6PwrSupply_St();
    double CDCU_12VMCPwrSupply_St();
    void UpdateCDCU_12VMCPwrSupply_St();
    double CDCU_12VMCPwrSwh_St();
    void UpdateCDCU_12VMCPwrSwh_St();
    double CDCU_12VMCPwrdown_Req();
    void UpdateCDCU_12VMCPwrdown_Req();
    double CDCU_12VRCPwrSupply_St();
    void UpdateCDCU_12VRCPwrSupply_St();
    double CDCU_12VRCPwrSwh_St();
    void UpdateCDCU_12VRCPwrSwh_St();
    double CDCU_12VRCPwrdown_Req();
    void UpdateCDCU_12VRCPwrdown_Req();
    double CDCU_12VSC1PwrSupply_St();
    void UpdateCDCU_12VSC1PwrSupply_St();
    double CDCU_12VSC2PwrSupply_St();
    void UpdateCDCU_12VSC2PwrSupply_St();
    double CDCU_12VSC3PwrSupply_St();
    void UpdateCDCU_12VSC3PwrSupply_St();
    double CDCU_24VMCPwrSupply_St();
    void UpdateCDCU_24VMCPwrSupply_St();
    double CDCU_24VMCPwrSwh_St();
    void UpdateCDCU_24VMCPwrSwh_St();
    double CDCU_24VMCPwrdown_Req();
    void UpdateCDCU_24VMCPwrdown_Req();
    double CDCU_ChasPwrSupply_St();
    void UpdateCDCU_ChasPwrSupply_St();
    double CDCU_ChasPwrSwh_St();
    void UpdateCDCU_ChasPwrSwh_St();
    double CDCU_PA12VPwrSupply_St();
    void UpdateCDCU_PA12VPwrSupply_St();
    double CDCU_PA12VPwrSwh_St();
    void UpdateCDCU_PA12VPwrSwh_St();
    double CDCU_PA12VPwrdown_Req();
    void UpdateCDCU_PA12VPwrdown_Req();
    double CDCU_PA24VPwrSupply_St();
    void UpdateCDCU_PA24VPwrSupply_St();
    double CDCU_PA24VPwrSwh_St();
    void UpdateCDCU_PA24VPwrSwh_St();
    double CDCU_PA24VPwrdown_Req();
    void UpdateCDCU_PA24VPwrdown_Req();
    double CDCU_PowerState();
    void UpdateCDCU_PowerState();
    double CDCU_Pwr_BatChgSt();
    void UpdateCDCU_Pwr_BatChgSt();
    double CDCU_Pwr_BatLackSt();
    void UpdateCDCU_Pwr_BatLackSt();
    double CDCU_Pwr_BatReadySt();
    void UpdateCDCU_Pwr_BatReadySt();
    double CDCU_Pwr_Checksum();
    void UpdateCDCU_Pwr_Checksum();
    double CDCU_Pwr_ChgRlySt();
    void UpdateCDCU_Pwr_ChgRlySt();
    double CDCU_Pwr_DisChgRlySt();
    void UpdateCDCU_Pwr_DisChgRlySt();
    double CDCU_Pwr_PreChgRlySt();
    void UpdateCDCU_Pwr_PreChgRlySt();
    double CDCU_Pwr_PreChgSt();
    void UpdateCDCU_Pwr_PreChgSt();
    double CDCU_Pwr_RollCnt();
    void UpdateCDCU_Pwr_RollCnt();
    double CDCU_PwrdownTime_Chn();
    void UpdateCDCU_PwrdownTime_Chn();
    double CDCU_Pwrdown_Time();
    void UpdateCDCU_Pwrdown_Time();
    double CDCU_VehPwrSupply_St();
    void UpdateCDCU_VehPwrSupply_St();
    double CDCU_VehPwrSwh_St();
    void UpdateCDCU_VehPwrSwh_St();
  private:
    double CDCU_12VCS4PwrSupply_St_;
    double CDCU_12VCS5PwrSupply_St_;
    double CDCU_12VCS6PwrSupply_St_;
    double CDCU_12VMCPwrSupply_St_;
    double CDCU_12VMCPwrSwh_St_;
    double CDCU_12VMCPwrdown_Req_;
    double CDCU_12VRCPwrSupply_St_;
    double CDCU_12VRCPwrSwh_St_;
    double CDCU_12VRCPwrdown_Req_;
    double CDCU_12VSC1PwrSupply_St_;
    double CDCU_12VSC2PwrSupply_St_;
    double CDCU_12VSC3PwrSupply_St_;
    double CDCU_24VMCPwrSupply_St_;
    double CDCU_24VMCPwrSwh_St_;
    double CDCU_24VMCPwrdown_Req_;
    double CDCU_ChasPwrSupply_St_;
    double CDCU_ChasPwrSwh_St_;
    double CDCU_PA12VPwrSupply_St_;
    double CDCU_PA12VPwrSwh_St_;
    double CDCU_PA12VPwrdown_Req_;
    double CDCU_PA24VPwrSupply_St_;
    double CDCU_PA24VPwrSwh_St_;
    double CDCU_PA24VPwrdown_Req_;
    double CDCU_PowerState_;
    double CDCU_Pwr_BatChgSt_;
    double CDCU_Pwr_BatLackSt_;
    double CDCU_Pwr_BatReadySt_;
    double CDCU_Pwr_Checksum_;
    double CDCU_Pwr_ChgRlySt_;
    double CDCU_Pwr_DisChgRlySt_;
    double CDCU_Pwr_PreChgRlySt_;
    double CDCU_Pwr_PreChgSt_;
    double CDCU_Pwr_RollCnt_;
    double CDCU_PwrdownTime_Chn_;
    double CDCU_Pwrdown_Time_;
    double CDCU_VehPwrSupply_St_;
    double CDCU_VehPwrSwh_St_;
};