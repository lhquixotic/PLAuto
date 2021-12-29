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
#include "cansend_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_cansend {

// Constructor
CansendHandle::CansendHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    cansend_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  cansend_.setParameters(para_);
  subscribeToTopics();
  publishToTopics();
}

// Getters
int CansendHandle::getNodeRate() const { return node_rate_; }

// Methods
void CansendHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("cansend_topic_name",
                                      cansend_topic_name_,
                                      "/sent_messages")) {
    ROS_WARN_STREAM("Did not load cansend_topic_name. Standard value is: " << cansend_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("control_cmd_topic_name",
                                      control_cmd_topic_name_,
                                      "ctrl_raw")) {
    ROS_WARN_STREAM("Did not load control_cmd_topic_name. Standard value is: " << control_cmd_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("chassis_status_topic_name",
                                      chassis_status_topic_name_,
                                      "/chassis/status")) {
    ROS_WARN_STREAM("Did not load chassis_status_topic_name. Standard value is: " << chassis_status_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  nodeHandle_.param<int>("cansend_para/send_mode", para_.send_mode,0);
  nodeHandle_.param<double>("cansend_para/steer_angle",para_.steer_angle, 0);
  nodeHandle_.param<double>("cansend_para/steer_scale",para_.steer_scale,16.5);
  nodeHandle_.param<double>("cansend_para/drive_target_speed",para_.drive_target_speed,0);
  nodeHandle_.param<double>("cansend_para/drive_target_gear",para_.drive_target_gear,0);
  nodeHandle_.param<double>("cansend_para/drive_limit_speed",para_.drive_limit_speed,0);
}

void CansendHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  controlCmdSubscriber_ = 
    nodeHandle_.subscribe(control_cmd_topic_name_,1,&CansendHandle::controlCmdCallback,this);
  chassisStatusSubscriber_ = 
    nodeHandle_.subscribe(chassis_status_topic_name_,1,&CansendHandle::chassisStatusCallback,this);
}

void CansendHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  cansendPublisher_ = nodeHandle_.advertise<can_msgs::Frames>(cansend_topic_name_, 100);
}

void CansendHandle::run() {
  cansend_.runAlgorithm();
  sendMsg();
}

void CansendHandle::sendMsg() {
  cansendPublisher_.publish(cansend_.getFrames());
}

void CansendHandle::controlCmdCallback(const autoware_msgs::ControlCommandStamped &msg){
  cansend_.setControlCmd(msg);
}
void CansendHandle::chassisStatusCallback(const common_msgs::ChassisStatus & msg){
  cansend_.setChassisStatus(msg);
}

}
