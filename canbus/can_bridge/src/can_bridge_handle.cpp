#include <ros/ros.h>
#include "can_bridge_handle.hpp"
#include "register.h"

namespace ns_can_bridge {

// Constructor
CanBridgeHandle::CanBridgeHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle){
  ROS_INFO("Constructing Handle");
  loadParameters();
}

// Methods
void CanBridgeHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  // Can parameters
  nodeHandle_.param<int>("para/DEV_INDEX" , can_para_._useCanDevIndex,0);
  nodeHandle_.param<int>("para/USE_CAN_NUM", can_para_._useCanChannel,3);
  nodeHandle_.param<int>("para/SND_TYPE", can_para_._useCanSendType,0);
  nodeHandle_.param<int>("para/SND_FRAMES", can_para_._useCanSendFrames,64);
  nodeHandle_.param<int>("para/SND_TIMES", can_para_._useCanSendTimes,1000);
  nodeHandle_.param<int>("para/SND_DELY", can_para_._useCanSendDely,5);

  nodeHandle_.param<std::string>("can_msgs_topic_name",can_msgs_topic_name_,"can_msgs");

  ROS_INFO_STREAM("DEV_INDEX: "<<can_para_._useCanDevIndex);
}

}