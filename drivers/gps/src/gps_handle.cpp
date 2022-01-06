#include <ros/ros.h>
#include "gps_handle.hpp"
#include "register.h"

#include <chrono>

namespace ns_gps {

// Constructor
GPSHandle::GPSHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    gps_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  gps_.setGpsParameters(gps_para_);
  subscribeToTopics();
  publishToTopics();
}

// Getters
int GPSHandle::getNodeRate() const { return node_rate_; }

// Methods
void GPSHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("serial_info_topic_name",
                                      serial_info_topic_name_,
                                      "/drivers/serial_info")) {
    ROS_WARN_STREAM(
        "Did not load serial_info_topic_name. Standard value is: " << serial_info_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("gps_state_topic_name",
                                      gps_state_topic_name_,
                                      "/drivers/gps")){
    ROS_WARN_STREAM("Did not load gps_state_topic_name. Standard value is: " << gps_state_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  nodeHandle_.param<std::string>("protocol_name",gps_para_.protocol_name,"GPCHC");
  ROS_INFO_STREAM("[GPS parameters] protocol_name: "<<gps_para_.protocol_name);
}

void GPSHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  serialInfoSubscriber_ =
      nodeHandle_.subscribe(serial_info_topic_name_, 1, &GPSHandle::serialInfoCallback, this);
}

void GPSHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  gpsStatePublisher_ = nodeHandle_.advertise<common_msgs::GpsInfo>(gps_state_topic_name_, 1);
}

void GPSHandle::run() {
  // std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  gps_.runAlgorithm();
  // std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  // double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  // std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  sendMsg();
}

void GPSHandle::sendMsg() {
  //ROS_INFO_STREAM("gps state" << gps_.getGpsState());
  gpsStatePublisher_.publish(gps_.getGpsState());
}

void GPSHandle::serialInfoCallback(const nmea_msgs::Sentence &msg) {
  gps_.serialInfoFlag = true;
  gps_.setSerialInfo(msg);
}
}
