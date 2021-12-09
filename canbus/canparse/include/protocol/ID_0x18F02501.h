#pragma once
#include "protocol.h" 
class ID_0x18F02501:public protocol{
  public:
    ID_0x18F02501();
    virtual ~ID_0x18F02501()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double flwAcc();
    void UpdateflwAcc();
    double flwBrkPress();
    void UpdateflwBrkPress();
    double flwPedBrk();
    void UpdateflwPedBrk();
    double flwSpd();
    void UpdateflwSpd();
  private:
    double flwAcc_;
    double flwBrkPress_;
    double flwPedBrk_;
    double flwSpd_;
};
