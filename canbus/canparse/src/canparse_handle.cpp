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
#include "canparse_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_canparse {

// Constructor
CanparseHandle::CanparseHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    canparse_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  subscribeToTopics();
  publishToTopics();
}

// Getters
int CanparseHandle::getNodeRate() const { return node_rate_; }

// Methods
void CanparseHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("canbus_receive_topic_name",
                                      canbus_receive_topic_name_,
                                      "/received_messages")) {
    ROS_WARN_STREAM("Did not load canbus_receive_topic_name_. Standard value is: " << canbus_receive_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("chassis_state_topic_name",
                                      chassis_state_topic_name_,
                                      "/chassis/vehicle_state")) {
    ROS_WARN_STREAM("Did not load chassis_state_topic_name_. Standard value is: " << chassis_state_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
}

void CanparseHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  canbus_receive_Subscriber_ =
      nodeHandle_.subscribe(canbus_receive_topic_name_, 100, &CanparseHandle::CanbusReceiveCallback, this);
}

void CanparseHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  chassisStatePublisher_ = nodeHandle_.advertise<common_msgs::ChassisState>(chassis_state_topic_name_,1);
}

void CanparseHandle::run() {
  // std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  canparse_.runAlgorithm();
  // std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  // double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  // std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  sendMsg();
}

void CanparseHandle::sendMsg() {
  chassisStatePublisher_.publish(canparse_.getChassisState());
}

void CanparseHandle::CanbusReceiveCallback(const can_msgs::Frame &f) {
  canparse_.Parse(f);
}
}
