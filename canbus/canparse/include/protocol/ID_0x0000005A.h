#pragma once
#include "protocol.h" 
class ID_0x0000005A:public protocol{
  public:
    ID_0x0000005A();
    virtual ~ID_0x0000005A()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double flwPitchRt();
    void UpdateflwPitchRt();
    double flwYawRt();
    void UpdateflwYawRt();
  private:
    double flwPitchRt_;
    double flwYawRt_;
};
