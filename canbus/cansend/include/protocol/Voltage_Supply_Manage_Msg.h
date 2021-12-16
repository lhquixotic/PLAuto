#pragma once 
#include "protocol.h" 
class Voltage_Supply_Manage_Msg:public protocol{
  public:
    Voltage_Supply_Manage_Msg();
    virtual ~Voltage_Supply_Manage_Msg()=default;
    virtual void Update(uint8_t *data) override;
    void Reset() override;
    double ad1_voltage_supply_active();
    void Setad1_voltage_supply_active(double ad1_voltage_supply_active);
    void Set_p_ad1_voltage_supply_active(double ad1_voltage_supply_active);
    double ad1_voltage_supply_reboot();
    void Setad1_voltage_supply_reboot(double ad1_voltage_supply_reboot);
    void Set_p_ad1_voltage_supply_reboot(double ad1_voltage_supply_reboot);
    double ad2_voltage_supply_active();
    void Setad2_voltage_supply_active(double ad2_voltage_supply_active);
    void Set_p_ad2_voltage_supply_active(double ad2_voltage_supply_active);
    double ad2_voltage_supply_reboot();
    void Setad2_voltage_supply_reboot(double ad2_voltage_supply_reboot);
    void Set_p_ad2_voltage_supply_reboot(double ad2_voltage_supply_reboot);
    double chassis_voltage_supply_active();
    void Setchassis_voltage_supply_active(double chassis_voltage_supply_active);
    void Set_p_chassis_voltage_supply_active(double chassis_voltage_supply_active);
    double chassis_voltage_supply_reboot();
    void Setchassis_voltage_supply_reboot(double chassis_voltage_supply_reboot);
    void Set_p_chassis_voltage_supply_reboot(double chassis_voltage_supply_reboot);
    double checksum();
    void Setchecksum(double checksum);
    void Set_p_checksum(double checksum);
    double rolling_counter();
    void Setrolling_counter(double rolling_counter);
    void Set_p_rolling_counter(double rolling_counter);
    double total_voltage_supply_active();
    void Settotal_voltage_supply_active(double total_voltage_supply_active);
    void Set_p_total_voltage_supply_active(double total_voltage_supply_active);
    double total_voltage_supply_reboot();
    void Settotal_voltage_supply_reboot(double total_voltage_supply_reboot);
    void Set_p_total_voltage_supply_reboot(double total_voltage_supply_reboot);
  private:
    double ad1_voltage_supply_active_;
    double ad1_voltage_supply_reboot_;
    double ad2_voltage_supply_active_;
    double ad2_voltage_supply_reboot_;
    double chassis_voltage_supply_active_;
    double chassis_voltage_supply_reboot_;
    double checksum_;
    double rolling_counter_;
    double total_voltage_supply_active_;
    double total_voltage_supply_reboot_;
};
