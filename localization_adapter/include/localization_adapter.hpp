#ifndef LOCALIZATION_ADAPTER_HPP
#define LOCALIZATION_ADAPTER_HPP

#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/PoseStamped.h"
#include "gps2utm.hpp"
#include "common_msgs/GpsInfo.h"

namespace ns_localization_adapter {

class Localization_adapter {

 public:
  // Constructor
  Localization_adapter(ros::NodeHandle &nh);

  // Getters
  nav_msgs::Odometry getUTMPose();

  // Setters
  void setSimulationPose(const geometry_msgs::PoseStamped &msg);
  void setGpsInfo(const common_msgs::GpsInfo &msg);
  void setRunMode(const std::string &msg);
  void setGpsOrigin(const utm::Gps_point &msg);

  // Methods
  void runAlgorithm();
  bool rawLocFlag = false;

 private:

  ros::NodeHandle &nh_;

  utm::Gps_point origin;
  std::string run_mode;

  common_msgs::GpsInfo gps_info;
  nav_msgs::Odometry utm_pose;
  geometry_msgs::PoseStamped simulation_pose;

};
}

#endif //LOCALIZATION_ADAPTER_HPP
