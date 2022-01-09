#include <ros/ros.h>
#include "waypoint_saver_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_waypoint_saver {

// Constructor
Wp_saverHandle::Wp_saverHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    waypoint_saver_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  subscribeToTopics();
  publishToTopics();
}

// Getters
int Wp_saverHandle::getNodeRate() const { return node_rate_; }

// Methods
void Wp_saverHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("utm_localization_topic_name",
                                      localization_topic_name_,
                                      "/localization/utmpose")) {
    ROS_WARN_STREAM(
        "Did not load utm_localization_topic_name. Standard value is: " << localization_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  if (!nodeHandle_.param<std::string>("waypoint_filename",
                                      waypoint_filename_,
                                      "/waypoint_loader/data/track_data/track_01.txt")) {
    ROS_WARN_STREAM(
        "Did not load waypoint_filename. Standard value is: " << waypoint_filename_);
  }
  if (!nodeHandle_.param("min_dis", min_dis_, 0.05)) {
    ROS_WARN_STREAM("Did not load min_dis. Standard value is: " << min_dis_);
  }
}

void Wp_saverHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  localizationSubscriber_ =
      nodeHandle_.subscribe(localization_topic_name_, 1, &Wp_saverHandle::localizationCallback, this);
}

void Wp_saverHandle::publishToTopics() {
  ROS_INFO("publish to topics");
}

void Wp_saverHandle::run() {
  // std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  waypoint_saver_.runAlgorithm(min_dis_, waypoint_filename_);
  // std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  // double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  // std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  sendMsg();
}

void Wp_saverHandle::sendMsg() {
}

void Wp_saverHandle::localizationCallback(const nav_msgs::Odometry &msg) {
  waypoint_saver_.setLocalization(msg);
}

}