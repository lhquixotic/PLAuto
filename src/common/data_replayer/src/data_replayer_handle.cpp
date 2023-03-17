#include <ros/ros.h>
#include "data_replayer_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_data_replayer {

// Constructor
DataReplayerHandle::DataReplayerHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    data_replayer_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  data_replayer_.setParameters(para_);
  data_replayer_.loadLogFile(para_.log_filename);
  subscribeToTopics();
  publishToTopics();
  replay_trigger_ = false;
}

// Getters
int DataReplayerHandle::getNodeRate() const { return node_rate_; }

// Methods
void DataReplayerHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("virtual_vehicle_state_topic_name",
                                      virtual_vehicle_state_topic_name_,
                                      "/virtual_vehicle_state")) {
    ROS_WARN_STREAM(
        "Did not load virtual_vehicle_state_topic_name. Standard value is: " << virtual_vehicle_state_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("replay_trigger_topic_name",
                                      replay_trigger_topic_name_,
                                      "/control/replay_trigger")) {
    ROS_WARN_STREAM(
        "Did not load replay_trigger_topic_name. Standard value is: " << replay_trigger_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  //nodeHandle_.param("config_name",variable_name,value);
  nodeHandle_.param<std::string>("log_filename",para_.log_filename," ");
  nodeHandle_.param<double>("init_distance",para_.init_distance,5);
}

void DataReplayerHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  replayTriggerSubscriber_ =
      nodeHandle_.subscribe(replay_trigger_topic_name_, 10, &DataReplayerHandle::replayTriggerCallback, this);
}

void DataReplayerHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  virtualVehicleStatePublisher_ = nodeHandle_.advertise<common_msgs::VirtualVehicleState>(virtual_vehicle_state_topic_name_, 1);
}

void DataReplayerHandle::run() {
  // std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  if (replay_trigger_){
    data_replayer_.runAlgorithm();
    sendMsg();
  }else{
    ROS_WARN("Wating for replay trigger signal...");
  }
  // std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  // double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  // std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;

}

void DataReplayerHandle::sendMsg() {
  virtualVehicleStatePublisher_.publish(data_replayer_.getVirtualVehicleState());
}

void DataReplayerHandle::replayTriggerCallback(const common_msgs::Trigger &msg){
  replay_trigger_ = msg.trigger;
}

}