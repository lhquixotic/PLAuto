#pragma once
#include "protocol.h" 
class ID_0x18FF4BD1:public protocol{
  public:
    ID_0x18FF4BD1();
    virtual ~ID_0x18FF4BD1()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double flwStrAgl();
    void UpdateflwStrAgl();
    double flwStrErrCls();
    void UpdateflwStrErrCls();
    double flwStrErrCod();
    void UpdateflwStrErrCod();
  private:
    double flwStrAgl_;
    double flwStrErrCls_;
    double flwStrErrCod_;
};
