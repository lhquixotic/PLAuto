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
#include "serial_com_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_serial_com {

// Constructor
SerialComHandle::SerialComHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    serial_com_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  serial_com_.setSerialParameters(serial_para_);
  serial_com_.initializeSerial();
  subscribeToTopics();
  publishToTopics();
}

// Getters
int SerialComHandle::getNodeRate() const { return node_rate_; }

// Methods
void SerialComHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("serial_info_topic_name",
                                      serial_info_topic_name_,
                                      "/drivers/serial_info")) {
    ROS_WARN_STREAM(
        "Did not load serial_info_topic_name. Standard value is: " << serial_info_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  nodeHandle_.param("baud",serial_para_.baud,115200);
  nodeHandle_.param<std::string>("port",serial_para_.port,"ttyTHS2");
  ROS_INFO_STREAM("[Serial Parameters] port: "<<serial_para_.port
                <<", baud: "<<serial_para_.baud);
}

void SerialComHandle::subscribeToTopics() {// No topics to subscribe
}

void SerialComHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  serialInfoPublisher_ = nodeHandle_.advertise<nmea_msgs::Sentence>(serial_info_topic_name_, 1);
}

void SerialComHandle::run() {
  //std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  serial_com_.runAlgorithm();
  // std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  // double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  // std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  sendMsg();
}

void SerialComHandle::sendMsg() {
  serialInfoPublisher_.publish(serial_com_.getSerialInfo());
}
}