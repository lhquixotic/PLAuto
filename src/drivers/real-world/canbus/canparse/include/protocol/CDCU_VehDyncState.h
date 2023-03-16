#pragma once
#include "protocol.h" 
class CDCU_VehDyncState:public protocol{
  public:
    CDCU_VehDyncState();
    virtual ~CDCU_VehDyncState()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_VehDync_Checksum();
    void UpdateCDCU_VehDync_Checksum();
    double CDCU_VehDync_RollCnt();
    void UpdateCDCU_VehDync_RollCnt();
    double CDCU_Veh_Curvture();
    void UpdateCDCU_Veh_Curvture();
    double CDCU_Veh_LongtdnalAccSpd();
    void UpdateCDCU_Veh_LongtdnalAccSpd();
    double CDCU_Veh_LongtdnalSpd();
    void UpdateCDCU_Veh_LongtdnalSpd();
    double CDCU_Veh_RunDir();
    void UpdateCDCU_Veh_RunDir();
  private:
    double CDCU_VehDync_Checksum_;
    double CDCU_VehDync_RollCnt_;
    double CDCU_Veh_Curvture_;
    double CDCU_Veh_LongtdnalAccSpd_;
    double CDCU_Veh_LongtdnalSpd_;
    double CDCU_Veh_RunDir_;
};
