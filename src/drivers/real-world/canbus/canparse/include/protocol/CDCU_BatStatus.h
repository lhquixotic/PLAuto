#pragma once
#include "protocol.h" 
class CDCU_BatStatus:public protocol{
  public:
    CDCU_BatStatus();
    virtual ~CDCU_BatStatus()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double CDCU_BMS_BatCurt();
    void UpdateCDCU_BMS_BatCurt();
    double CDCU_BMS_BatSOC();
    void UpdateCDCU_BMS_BatSOC();
    double CDCU_BMS_BatSOH();
    void UpdateCDCU_BMS_BatSOH();
    double CDCU_BMS_BatTemp();
    void UpdateCDCU_BMS_BatTemp();
    double CDCU_BMS_BatVolt();
    void UpdateCDCU_BMS_BatVolt();
    double CDCU_BMS_ChgSt();
    void UpdateCDCU_BMS_ChgSt();
    double CDCU_BMS_DisChgSt();
    void UpdateCDCU_BMS_DisChgSt();
    double CDCU_BMS_FeedBackSt();
    void UpdateCDCU_BMS_FeedBackSt();
    double CDCU_BatInfo_Checksum();
    void UpdateCDCU_BatInfo_Checksum();
    double CDCU_BatInfo_RollCnt();
    void UpdateCDCU_BatInfo_RollCnt();
    double CDCU_LvBat_Volt();
    void UpdateCDCU_LvBat_Volt();
  private:
    double CDCU_BMS_BatCurt_;
    double CDCU_BMS_BatSOC_;
    double CDCU_BMS_BatSOH_;
    double CDCU_BMS_BatTemp_;
    double CDCU_BMS_BatVolt_;
    double CDCU_BMS_ChgSt_;
    double CDCU_BMS_DisChgSt_;
    double CDCU_BMS_FeedBackSt_;
    double CDCU_BatInfo_Checksum_;
    double CDCU_BatInfo_RollCnt_;
    double CDCU_LvBat_Volt_;
};
