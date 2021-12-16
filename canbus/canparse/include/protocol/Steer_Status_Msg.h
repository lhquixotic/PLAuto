#pragma once
#include "protocol.h" 
class Steer_Status_Msg:public protocol{
  public:
    Steer_Status_Msg();
    virtual ~Steer_Status_Msg()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double act_fault_level();
    void Updateact_fault_level();
    double act_work_mode();
    void Updateact_work_mode();
    double checksum();
    void Updatechecksum();
    double real_steer_angle();
    void Updatereal_steer_angle();
    double real_steer_angle_gradiant();
    void Updatereal_steer_angle_gradiant();
    double rolling_counter();
    void Updaterolling_counter();
    double steer_torque_value();
    void Updatesteer_torque_value();
  private:
    double act_fault_level_;
    double act_work_mode_;
    double checksum_;
    double real_steer_angle_;
    double real_steer_angle_gradiant_;
    double rolling_counter_;
    double steer_torque_value_;
};
