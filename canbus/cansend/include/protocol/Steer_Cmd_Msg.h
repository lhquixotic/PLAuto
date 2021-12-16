#pragma once 
#include "protocol.h" 
class Steer_Cmd_Msg:public protocol{
  public:
    Steer_Cmd_Msg();
    virtual ~Steer_Cmd_Msg()=default;
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
    double steer_control_mode();
    void Setsteer_control_mode(double steer_control_mode);
    void Set_p_steer_control_mode(double steer_control_mode);
    double target_steer_angle_value();
    void Settarget_steer_angle_value(double target_steer_angle_value);
    void Set_p_target_steer_angle_value(double target_steer_angle_value);
    double target_steer_curvature();
    void Settarget_steer_curvature(double target_steer_curvature);
    void Set_p_target_steer_curvature(double target_steer_curvature);
  private:
    double checksum_;
    double control_active_;
    double rolling_counter_;
    double steer_control_mode_;
    double target_steer_angle_value_;
    double target_steer_curvature_;
};
