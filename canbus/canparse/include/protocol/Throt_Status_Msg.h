#pragma once
#include "protocol.h" 
class Throt_Status_Msg:public protocol{
  public:
    Throt_Status_Msg();
    virtual ~Throt_Status_Msg()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double act_fault_level();
    void Updateact_fault_level();
    double checksum();
    void Updatechecksum();
    double mc_real_throttle();
    void Updatemc_real_throttle();
    double mc_run_direction();
    void Updatemc_run_direction();
    double motor_current();
    void Updatemotor_current();
    double motor_speed();
    void Updatemotor_speed();
    double real_gear();
    void Updatereal_gear();
    double rolling_counter();
    void Updaterolling_counter();
    double throt_mode();
    void Updatethrot_mode();
  private:
    double act_fault_level_;
    double checksum_;
    double mc_real_throttle_;
    double mc_run_direction_;
    double motor_current_;
    double motor_speed_;
    double real_gear_;
    double rolling_counter_;
    double throt_mode_;
};
