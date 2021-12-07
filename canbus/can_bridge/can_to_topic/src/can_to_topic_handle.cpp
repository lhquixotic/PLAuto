#include <ros/ros.h>
#include "can_to_topic_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_can_to_topic {

// Constructor
CanToTopicHandle::CanToTopicHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    can_to_topic_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  can_to_topic_.setCanParameters(can_para_);
  subscribeToTopics();
  can_to_topic_.initializeCanDevice();
  publishToTopics();
}

// Getters
int CanToTopicHandle::getNodeRate() const { return node_rate_; }

// Methods
void CanToTopicHandle::loadParameters() {
    ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  nodeHandle_.param<std::string>("can_info_topic_name",can_info_topic_name_,"can_info");
   // Can parameters
  nodeHandle_.param<int>("para/DEV_INDEX" , can_para_._useCanDevIndex,0);
  nodeHandle_.param<int>("para/USE_CAN_NUM", can_para_._useCanChannel,3);
  nodeHandle_.param<int>("para/SND_TYPE", can_para_._useCanSendType,0);
  nodeHandle_.param<int>("para/SND_FRAMES", can_para_._useCanSendFrames,64);
  nodeHandle_.param<int>("para/SND_TIMES", can_para_._useCanSendTimes,1000);
  nodeHandle_.param<int>("para/SND_DELY", can_para_._useCanSendDely,5);
  ROS_INFO_STREAM("DEV_INDEX: "<<can_para_._useCanDevIndex);
}

void CanToTopicHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  canInfoSubscriber_ =  
        nodeHandle_.subscribe(can_info_topic_name_,1,&CanToTopicHandle::canInfoCallback,this);
}

void CanToTopicHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  // can_to_topicStatePublisher_ = nodeHandle_.advertise<fsd_common_msgs::ConeDetections>(can_to_topic_state_topic_name_, 1);
}

void CanToTopicHandle::run() {
    can_to_topic_.runAlgorithm();
    sendMsg();
}

void CanToTopicHandle::sendMsg() {
  
}

void CanToTopicHandle::canInfoCallback(const can_msgs::CanInfo & msg){
  can_to_topic_.can_info = msg;
}

}