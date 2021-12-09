#pragma once
#include "protocol.h" 
class ID_0x18F02505:public protocol{
  public:
    ID_0x18F02505();
    virtual ~ID_0x18F02505()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double flwPdlAccfreq();
    void UpdateflwPdlAccfreq();
    double flwPdlAccobj();
    void UpdateflwPdlAccobj();
    double flwPedBrkfreq();
    void UpdateflwPedBrkfreq();
    double flwPedBrkobj();
    void UpdateflwPedBrkobj();
  private:
    double flwPdlAccfreq_;
    double flwPdlAccobj_;
    double flwPedBrkfreq_;
    double flwPedBrkobj_;
};
