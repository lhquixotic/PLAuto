#include <ros/ros.h>
#include "canparse.hpp"
#include <sstream>
namespace ns_canparse {
// Constructor
Canparse::Canparse(ros::NodeHandle &nh) : nh_(nh) {

};

// Getters
common_msgs::VehicleDynamicState Canparse::getVehicleDynamicState() {return msg_vehicle_dynamic_state;}
common_msgs::ChassisStatus Canparse::getChassisStatus(){return msg_chassis_status;}
// Setters
void Canparse::Parse(can_msgs::Frame f) {
  //ROS_INFO("frame id: %X",f.id);
  switch (f.id)
  {
  case 0x250: // vehicle dynamic state
    vehicle_dynamic_state.Update(f.data.c_array());
    ROS_INFO("Vehicle_Dynamic_State:  vehicle_speed: %f; vehicle_lon_acceleration: %f", 
    vehicle_dynamic_state.CDCU_Veh_LongtdnalSpd(),vehicle_dynamic_state.CDCU_Veh_LongtdnalAccSpd());
    break;

  case 0x211:// brake status
    brake_status.Update(f.data.c_array());
    ROS_INFO("Brake_Status: real_brake_pressure: %f",brake_status.CDCU_EHB_BrkPresur());
    break; 

  case 0x215: // steer status
    steer_status.Update(f.data.c_array());
    ROS_INFO("Steer_Status: real_steer_angle: %f", steer_status.CDCU_EPS_StrWhlAngle());
    break;

  case 0x217: // throttle status
    throt_status.Update(f.data.c_array());
    ROS_INFO("Throt_Status: real_throt_angle: %f", throt_status.CDCU_MCU_ThrotAct());
    break;

  case 0x240: // vehicle state
    vehicle_state.Update(f.data.c_array());
    ROS_INFO("Vehicle_State: vehicle_run_mode: %d", vehicle_state.CDCU_Veh_RunMode());
    if (vehicle_state.CDCU_Veh_ErrLevel()>0){
      ROS_WARN_STREAM("Vehicle Error Level is " << vehicle_state.CDCU_Veh_ErrLevel());
    }
    if (vehicle_state.CDCU_VehEmgcySwh_St()>0){
      ROS_WARN_STREAM("Emergency Switch is on!");
    }
    if (vehicle_state.CDCU_LvBat_LowVolt()>0){
      ROS_WARN_STREAM("Low-voltage Battery's Voltage is Low!");
    }
    if (vehicle_state.CDCU_Bat_LowSOC() > 0){
      ROS_WARN_STREAM("Battery's SOC is Low!");
    }
    break;

  default:
    break;
  }
}

void Canparse::runAlgorithm() {

  msg_vehicle_dynamic_state.header.stamp = ros::Time::now();
  msg_vehicle_dynamic_state.vehicle_speed = vehicle_dynamic_state.CDCU_Veh_LongtdnalSpd();
  msg_vehicle_dynamic_state.vehicle_lon_acceleration = vehicle_dynamic_state.CDCU_Veh_LongtdnalAccSpd();

  msg_chassis_status.real_throttle = throt_status.CDCU_MCU_ThrotAct();  
  msg_chassis_status.real_brake_pressure = brake_status.CDCU_EHB_BrkPresur();
  msg_chassis_status.real_steer_angle = steer_status.CDCU_EPS_StrWhlAngle();
  msg_chassis_status.vehicle_run_mode = vehicle_state.CDCU_Veh_RunMode();
  
}

}
