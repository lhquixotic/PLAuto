#pragma once 
#include "protocol.h" 
class Park_Cmd_Msg:public protocol{
  public:
    Park_Cmd_Msg();
    virtual ~Park_Cmd_Msg()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double checksum();
    void Setchecksum(double checksum);
    void Set_p_checksum(double checksum);
    double control_active();
    void Setcontrol_active(double control_active);
    void Set_p_control_active(double control_active);
    double park_control_enable();
    void Setpark_control_enable(double park_control_enable);
    void Set_p_park_control_enable(double park_control_enable);
    double rolling_counter();
    void Setrolling_counter(double rolling_counter);
    void Set_p_rolling_counter(double rolling_counter);
  private:
    double checksum_;
    double control_active_;
    double park_control_enable_;
    double rolling_counter_;
};
