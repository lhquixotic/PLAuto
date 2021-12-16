#pragma once 
#include "protocol.h" 
class Brake_Cmd_Msg:public protocol{
  public:
    Brake_Cmd_Msg();
    virtual ~Brake_Cmd_Msg()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double brk_control_mode();
    void Setbrk_control_mode(double brk_control_mode);
    void Set_p_brk_control_mode(double brk_control_mode);
    double checksum();
    void Setchecksum(double checksum);
    void Set_p_checksum(double checksum);
    double control_active();
    void Setcontrol_active(double control_active);
    void Set_p_control_active(double control_active);
    double rolling_counter();
    void Setrolling_counter(double rolling_counter);
    void Set_p_rolling_counter(double rolling_counter);
    double target_brk_pedal_pos();
    void Settarget_brk_pedal_pos(double target_brk_pedal_pos);
    void Set_p_target_brk_pedal_pos(double target_brk_pedal_pos);
    double target_brk_pressure();
    void Settarget_brk_pressure(double target_brk_pressure);
    void Set_p_target_brk_pressure(double target_brk_pressure);
  private:
    double brk_control_mode_;
    double checksum_;
    double control_active_;
    double rolling_counter_;
    double target_brk_pedal_pos_;
    double target_brk_pressure_;
};
