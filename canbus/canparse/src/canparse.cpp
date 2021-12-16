#include <ros/ros.h>
#include "canparse.hpp"
#include <sstream>
namespace ns_canparse {
// Constructor
Canparse::Canparse(ros::NodeHandle &nh) : nh_(nh) {

};

// Getters
common_msgs::VehicleDynamicState Canparse::getVehicleDynamicState() {return msg_vehicle_dynamic_state;}

// Setters
void Canparse::Parse(can_msgs::Frame f) {
  //ROS_INFO("frame id: %X",f.id);
  switch (f.id)
  {
  
  case 0x250: // vehicle dynamic state
    vehicle_dynamic_state.Update(f.data.c_array());
    ROS_INFO("Vehicle_Dynamic_State:  vehicle_speed: %f; rolling_counter: %f; vehicle_lon_acceleration: %f", 
    vehicle_dynamic_state.vehicle_speed(),vehicle_dynamic_state.rolling_counter(),vehicle_dynamic_state.veh_lon_acceleration());
  
  default:
    break;
  }
}

void Canparse::runAlgorithm() {

  msg_vehicle_dynamic_state.header.stamp = ros::Time::now();
  msg_vehicle_dynamic_state.vehicle_speed = vehicle_dynamic_state.vehicle_speed();
  msg_vehicle_dynamic_state.vehicle_lon_acceleration = vehicle_dynamic_state.veh_lon_acceleration();
  

}

}
