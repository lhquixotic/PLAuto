#pragma once
#include "protocol.h" 
class Vehicle_Dynamic_State:public protocol{
  public:
    Vehicle_Dynamic_State();
    virtual ~Vehicle_Dynamic_State()=default;
    void Reset() override;
    virtual void Update(uint8_t *data) override;
    double checksum();
    void Updatechecksum();
    double rolling_counter();
    void Updaterolling_counter();
    double run_direction();
    void Updaterun_direction();
    double tripmeter();
    void Updatetripmeter();
    double veh_lon_acceleration();
    void Updateveh_lon_acceleration();
    double vehicle_speed();
    void Updatevehicle_speed();
  private:
    double checksum_;
    double rolling_counter_;
    double run_direction_;
    double tripmeter_;
    double veh_lon_acceleration_;
    double vehicle_speed_;
};
