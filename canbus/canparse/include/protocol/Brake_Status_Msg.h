#pragma once
#include "protocol.h" 
class Brake_Status_Msg:public protocol{
  public:
    Brake_Status_Msg();
    virtual ~Brake_Status_Msg()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double act_fault_level();
    void Updateact_fault_level();
    double brk_condition();
    void Updatebrk_condition();
    double brk_mode();
    void Updatebrk_mode();
    double checksum();
    void Updatechecksum();
    double real_brk_pressure();
    void Updatereal_brk_pressure();
    double rolling_counter();
    void Updaterolling_counter();
  private:
    double act_fault_level_;
    double brk_condition_;
    double brk_mode_;
    double checksum_;
    double real_brk_pressure_;
    double rolling_counter_;
};
