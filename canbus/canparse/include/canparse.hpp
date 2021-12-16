#ifndef CANPARSE_HPP
#define CANPARSE_HPP

#include "std_msgs/String.h"
#include <can_msgs/Frame.h>
#include <can_msgs/Frames.h>
#include "Vehicle_Dynamic_State.h"
#include <common_msgs/VehicleDynamicState.h>

namespace ns_canparse {

class Canparse {

 public:
  // Constructor
  Canparse(ros::NodeHandle &nh);
  Vehicle_Dynamic_State vehicle_dynamic_state;

  // Getters
  common_msgs::VehicleDynamicState getVehicleDynamicState();

  // Setters
  void Parse(can_msgs::Frame f);

  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;

  // common_msgs::ChassisState chassis_state;
  common_msgs::VehicleDynamicState msg_vehicle_dynamic_state;

};
}

#endif //CANPARSE_HPP
