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
  if (!nodeHandle_.param<std::string>("vehicle_dynamic_state_topic_name",
                                      vehicle_dynamic_state_topic_name_,
                                      "/chassis/vehicle_dynamic_state")) {
    ROS_WARN_STREAM("Did not load chassis_state_topic_name_. Standard value is: " << vehicle_dynamic_state_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("chassis_status_topic_name",
                                      chassis_status_topic_name_,
                                      "/chassis/status")){
    ROS_WARN_STREAM("Did not load chassis_status_topic_name_. Standard value is: "<< chassis_status_topic_name_);
  }
  
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
}

void CanparseHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  canbusReceiveSubscriber_ =
      nodeHandle_.subscribe(canbus_receive_topic_name_, 100, &CanparseHandle::CanbusReceiveCallback, this);
}

void CanparseHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  vehicleDynamicStatePublisher_ = 
      nodeHandle_.advertise<common_msgs::VehicleDynamicState>(vehicle_dynamic_state_topic_name_,10000);
  chassisStatusPublisher_ = 
      nodeHandle_.advertise<common_msgs::ChassisStatus>(chassis_status_topic_name_,100);
}

void CanparseHandle::run() {
  canparse_.runAlgorithm();
  sendMsg();
}

void CanparseHandle::sendMsg() {
  vehicleDynamicStatePublisher_.publish(canparse_.getVehicleDynamicState());
  chassisStatusPublisher_.publish(canparse_.getChassisStatus());
}

void CanparseHandle::CanbusReceiveCallback(const can_msgs::Frames &msg) {
  std::vector<can_msgs::Frame> recv_frames = msg.frames;
  int frame_num = recv_frames.size();
  for (int i = 0; i < frame_num; i++){
    canparse_.Parse(recv_frames[i]);
  }
}
}
