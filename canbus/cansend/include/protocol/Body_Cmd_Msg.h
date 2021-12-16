#pragma once 
#include "protocol.h" 
class Body_Cmd_Msg:public protocol{
  public:
    Body_Cmd_Msg();
    virtual ~Body_Cmd_Msg()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double backup_light_enable();
    void Setbackup_light_enable(double backup_light_enable);
    void Set_p_backup_light_enable(double backup_light_enable);
    double buzzer_enable();
    void Setbuzzer_enable(double buzzer_enable);
    void Set_p_buzzer_enable(double buzzer_enable);
    double checksum();
    void Setchecksum(double checksum);
    void Set_p_checksum(double checksum);
    double control_active();
    void Setcontrol_active(double control_active);
    void Set_p_control_active(double control_active);
    double daytime_lights_enable();
    void Setdaytime_lights_enable(double daytime_lights_enable);
    void Set_p_daytime_lights_enable(double daytime_lights_enable);
    double hazard_enable();
    void Sethazard_enable(double hazard_enable);
    void Set_p_hazard_enable(double hazard_enable);
    double headlight_enable();
    void Setheadlight_enable(double headlight_enable);
    void Set_p_headlight_enable(double headlight_enable);
    double klaxon_enable();
    void Setklaxon_enable(double klaxon_enable);
    void Set_p_klaxon_enable(double klaxon_enable);
    double rolling_counter();
    void Setrolling_counter(double rolling_counter);
    void Set_p_rolling_counter(double rolling_counter);
    double turnlight_left_enable();
    void Setturnlight_left_enable(double turnlight_left_enable);
    void Set_p_turnlight_left_enable(double turnlight_left_enable);
    double turnlight_right_enable();
    void Setturnlight_right_enable(double turnlight_right_enable);
    void Set_p_turnlight_right_enable(double turnlight_right_enable);
  private:
    double backup_light_enable_;
    double buzzer_enable_;
    double checksum_;
    double control_active_;
    double daytime_lights_enable_;
    double hazard_enable_;
    double headlight_enable_;
    double klaxon_enable_;
    double rolling_counter_;
    double turnlight_left_enable_;
    double turnlight_right_enable_;
};
