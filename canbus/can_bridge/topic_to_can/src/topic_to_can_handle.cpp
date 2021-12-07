#include <ros/ros.h>
#include "topic_to_can_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_topic_to_can {

// Constructor
TopicToCanHandle::TopicToCanHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    topic_to_can_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  topic_to_can_.setCanParameters(can_para_);
  topic_to_can_.initializeCanDevice();
  subscribeToTopics();
  publishToTopics();
}

// Getters
int TopicToCanHandle::getNodeRate() const { return node_rate_; }

// Methods
void TopicToCanHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  nodeHandle_.param<std::string>("can_handle_topic_name",can_handle_topic_name_,"can_handle");
  // Can parameters
  nodeHandle_.param<int>("para/DEV_INDEX" , can_para_._useCanDevIndex,0);
  nodeHandle_.param<int>("para/USE_CAN_NUM", can_para_._useCanChannel,3);
  nodeHandle_.param<int>("para/SND_TYPE", can_para_._useCanSendType,0);
  nodeHandle_.param<int>("para/SND_FRAMES", can_para_._useCanSendFrames,64);
  nodeHandle_.param<int>("para/SND_TIMES", can_para_._useCanSendTimes,1000);
  nodeHandle_.param<int>("para/SND_DELY", can_para_._useCanSendDely,5);

  ROS_INFO_STREAM("DEV_INDEX: "<<can_para_._useCanDevIndex);

}

void TopicToCanHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  canMsgsSubscriber_ =
      nodeHandle_.subscribe(can_msgs_topic_name_, 1, &TopicToCanHandle::canMsgsCallback, this);
}

void TopicToCanHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  canHandlePublisher_ = nodeHandle_.advertise<can_msgs::CanInfo>(can_handle_topic_name_,1);
  }

void TopicToCanHandle::run() {
  topic_to_can_.runAlgorithm();
  sendMsg();
}

void TopicToCanHandle::sendMsg() {
  // topic_to_canStatePublisher_.publish(topic_to_can_.getConeDetections());
  canHandlePublisher_.publish(topic_to_can_.getCanHandle());
}

void TopicToCanHandle::canMsgsCallback(const can_msgs::Frame & msg){
  topic_to_can_.frame_queue.push_back(msg);
}

}