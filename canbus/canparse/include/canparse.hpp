#ifndef CANPARSE_HPP
#define CANPARSE_HPP

#include "std_msgs/String.h"
#include <can_msgs/Frame.h>
#include <can_msgs/Frames.h>
#include <common_msgs/VehicleDynamicState.h>
#include <common_msgs/ChassisStatus.h>


//  include protocol files
#include "CDCU_BatStatus.h"
#include "CDCU_BodyStatus.h"
#include "CDCU_BrakeStatus.h"
#include "CDCU_DriveStatus.h"
#include "CDCU_ParkStatus.h"
#include "CDCU_PowerStatus.h"
#include "CDCU_SteerStatus.h"
#include "CDCU_VehDyncState.h"
#include "CDCU_VehState.h"


namespace ns_canparse {

class Canparse {

 public:
  // Constructor
  Canparse(ros::NodeHandle &nh);
  CDCU_VehDyncState vehicle_dynamic_state;
  CDCU_SteerStatus steer_status;
  CDCU_BrakeStatus brake_status;
  CDCU_DriveStatus throt_status;
  CDCU_VehState vehicle_state;

  // Getters
  common_msgs::VehicleDynamicState getVehicleDynamicState();
  common_msgs::ChassisStatus getChassisStatus();

  // Setters
  void Parse(can_msgs::Frame f);

  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;

  // common_msgs::ChassisState chassis_state;
  common_msgs::VehicleDynamicState msg_vehicle_dynamic_state;
  common_msgs::ChassisStatus msg_chassis_status;
};
}

#endif //CANPARSE_HPP
