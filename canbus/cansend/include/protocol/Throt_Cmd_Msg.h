#pragma once 
#include "protocol.h" 
class Throt_Cmd_Msg:public protocol{
  public:
    Throt_Cmd_Msg();
    virtual ~Throt_Cmd_Msg()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double checksum();
    void Setchecksum(double checksum);
    void Set_p_checksum(double checksum);
    double control_active();
    void Setcontrol_active(double control_active);
    void Set_p_control_active(double control_active);
    double rolling_counter();
    void Setrolling_counter(double rolling_counter);
    void Set_p_rolling_counter(double rolling_counter);
    double target_gear();
    void Settarget_gear(double target_gear);
    void Set_p_target_gear(double target_gear);
    double target_throttle();
    void Settarget_throttle(double target_throttle);
    void Set_p_target_throttle(double target_throttle);
    double target_vehicle_speed();
    void Settarget_vehicle_speed(double target_vehicle_speed);
    void Set_p_target_vehicle_speed(double target_vehicle_speed);
    double throt_control_mode();
    void Setthrot_control_mode(double throt_control_mode);
    void Set_p_throt_control_mode(double throt_control_mode);
    double vehicle_speed_max();
    void Setvehicle_speed_max(double vehicle_speed_max);
    void Set_p_vehicle_speed_max(double vehicle_speed_max);
  private:
    double checksum_;
    double control_active_;
    double rolling_counter_;
    double target_gear_;
    double target_throttle_;
    double target_vehicle_speed_;
    double throt_control_mode_;
    double vehicle_speed_max_;
};
