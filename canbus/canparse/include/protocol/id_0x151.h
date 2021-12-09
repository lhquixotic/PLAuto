#pragma once
#include "protocol.h" 
class id_0x151:public protocol{
  public:
    id_0x151();
    virtual ~id_0x151()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double FootControlSysInfo();
    void UpdateFootControlSysInfo();
  private:
    double FootControlSysInfo_;
};
