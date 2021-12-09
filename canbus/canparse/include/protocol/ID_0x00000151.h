#pragma once
#include "protocol.h" 
class ID_0x00000151:public protocol{
  public:
    ID_0x00000151();
    virtual ~ID_0x00000151()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double FootControlSysInfo();
    void UpdateFootControlSysInfo();
  private:
    double FootControlSysInfo_;
};
