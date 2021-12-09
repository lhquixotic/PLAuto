#pragma once
#include "protocol.h" 
class ID_0x18F02502:public protocol{
  public:
    ID_0x18F02502();
    virtual ~ID_0x18F02502()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double flwPdlAcc();
    void UpdateflwPdlAcc();
    double flwPedBrk();
    void UpdateflwPedBrk();
  private:
    double flwPdlAcc_;
    double flwPedBrk_;
};
