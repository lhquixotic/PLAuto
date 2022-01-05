#include <ros/ros.h>
#include "localization_adapter_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_localization_adapter {

// Constructor
Localization_adapterHandle::Localization_adapterHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    localization_adapter_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  localization_adapter_.setRunMode(run_mode_);
  localization_adapter_.setGpsOrigin(origin_);
  subscribeToTopics();
  publishToTopics();
}

// Getters
int Localization_adapterHandle::getNodeRate() const { return node_rate_; }

// Methods
void Localization_adapterHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("simulation_pose_topic_name",
                                      simulation_pose_topic_name_,
                                      "/sim/center_pose")) {
    ROS_WARN_STREAM(
        "Did not load simulation_pose_topic_name. Standard value is: " << simulation_pose_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("gps_info_topic_name",
                                      gps_info_topic_name_,
                                      "/localization/pose")) {
    ROS_WARN_STREAM("Did not load gps_info_topic_name. Standard value is: " << gps_info_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("localization_utm_topic_name",
                                      localization_utm_topic_name_,
                                      "/localization/utmpose")) {
    ROS_WARN_STREAM("Did not load /localization/utmpose. Standard value is: " << localization_utm_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  if (!nodeHandle_.param<std::string>("run_mode", run_mode_, "simulation")){
    ROS_WARN_STREAM("Did not load run_mode. Standard value is: " << run_mode_);
  }
  nodeHandle_.param<double>("Gps_origin/x",origin_.x,274083.3651381);
  nodeHandle_.param<double>("Gps_origin/y",origin_.y,4006502.509805);
  nodeHandle_.param<double>("Gps_origin/z",origin_.z,74.80);
  ROS_INFO_STREAM("Gps origin: x: "<<origin_.x<<", y: " << origin_.y<<", z: "<< origin_.z);
}

void Localization_adapterHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  simulationPoseSubscriber_ =
      nodeHandle_.subscribe(simulation_pose_topic_name_, 1, &Localization_adapterHandle::simulationPoseCallback, this);
  gpsInfoSubscriber_ =
      nodeHandle_.subscribe(gps_info_topic_name_, 1, &Localization_adapterHandle::gpsInfoCallback, this);
}

void Localization_adapterHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  utmPosePublisher_ = nodeHandle_.advertise<nav_msgs::Odometry>(localization_utm_topic_name_, 1);
}

void Localization_adapterHandle::run() {
  //std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  localization_adapter_.runAlgorithm();
  /*
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  */
  sendMsg();
}

void Localization_adapterHandle::sendMsg() {
  utmPosePublisher_.publish(localization_adapter_.getUTMPose());
}

void Localization_adapterHandle::simulationPoseCallback(const geometry_msgs::PoseStamped &msg) {
  localization_adapter_.rawLocFlag = true;
  localization_adapter_.setSimulationPose(msg);
}

void Localization_adapterHandle::gpsInfoCallback(const common_msgs::GpsInfo &msg){
  localization_adapter_.rawLocFlag = true;
  localization_adapter_.setGpsInfo(msg);
}

}
