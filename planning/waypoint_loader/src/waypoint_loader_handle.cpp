/*
    Formula Student Driverless Project (FSD-Project).
    Copyright (c) 2019:
     - chentairan <killasipilin@gmail.com>

    FSD-Project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FSD-Project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FSD-Project.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <ros/ros.h>
#include "waypoint_loader_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_waypoint_loader {

// Constructor
Waypoint_loaderHandle::Waypoint_loaderHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    waypoint_loader_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();

  waypoint_loader_.loadWaypointFile(waypoint_filename_);

  subscribeToTopics();
  publishToTopics();
}

// Getters
int Waypoint_loaderHandle::getNodeRate() const { return node_rate_; }

// Methods
void Waypoint_loaderHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("waypoint_loader_state_topic_name",
                                      waypoint_loader_state_topic_name_,
                                      "/map/global_path")) {
    ROS_WARN_STREAM("Did not load waypoint_loader_state_topic_name. Standard value is: " << waypoint_loader_state_topic_name_);
  }

  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }

  if (!nodeHandle_.param<std::string>("waypoint_filename",
                                      waypoint_filename_,
                                      "../data/track01.csv")) {
    ROS_WARN_STREAM("Did not load waypoint_filename. Standard value is: " << waypoint_filename_);
  }

  if (!nodeHandle_.param<std::string>("waypoint_loader_visual_topic_name",
                                      waypoint_loader_visual_topic_name_,
                                      "/map/global_path_rviz")) {
    ROS_WARN_STREAM("Did not load waypoint_loader_visual_topic_name. Standard value is: " << waypoint_loader_state_topic_name_);
  }
}


void Waypoint_loaderHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
}

void Waypoint_loaderHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  waypoint_loaderStatePublisher_ = nodeHandle_.advertise<autoware_msgs::Lane>(waypoint_loader_state_topic_name_, 1);
  waypoint_loaderVisualPublisher_ = nodeHandle_.advertise<nav_msgs::Path>(waypoint_loader_visual_topic_name_,1);
}

void Waypoint_loaderHandle::run() {
  /*
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  */
  waypoint_loader_.runAlgorithm();
  /*
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  */
  sendMsg();
}

void Waypoint_loaderHandle::sendMsg() {
  waypoint_loaderStatePublisher_.publish(waypoint_loader_.getGlobalPath());
  waypoint_loaderVisualPublisher_.publish(waypoint_loader_.getGlobalPathVisual());
}
}