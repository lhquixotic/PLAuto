#include <ros/ros.h>
#include "localization_adapter.hpp"
#include <sstream>

namespace ns_localization_adapter {
// Constructor
Localization_adapter::Localization_adapter(ros::NodeHandle &nh) : nh_(nh) {
  utm_pose.header.frame_id = "world";
};
// Getters
nav_msgs::Odometry Localization_adapter::getUTMPose() { return utm_pose; }


// Setters
void Localization_adapter::setSimulationPose(const geometry_msgs::PoseStamped &msg) {
  simulation_pose = msg;
}
void Localization_adapter::setGpsInfo(const common_msgs::GpsInfo &msg){
  gps_info = msg;
}

void Localization_adapter::setRunMode(const std::string &msg){
  run_mode = msg;
}

void Localization_adapter::setGpsOrigin(const utm::Gps_point &msg){
  origin = msg;
}

void Localization_adapter::runAlgorithm() {
  if (rawLocFlag){
  utm_pose.header.stamp = ros::Time::now();
  if (run_mode == "simulation"){
    utm_pose.pose.pose = simulation_pose.pose;
  }
  else{
    if (run_mode == "real_car"){
      utm_pose = utm::gps2odom(gps_info);
      utm_pose.pose.pose.position.x -= origin.x;
      utm_pose.pose.pose.position.y -= origin.y;
      utm_pose.pose.pose.position.z -= origin.z;
  }
    else{
      ROS_ERROR_STREAM("No such run mode!");
    }
  }
}
  else{
      ROS_WARN_STREAM("Waiting for " << run_mode <<" localization messages..."); 
  }
}
}
