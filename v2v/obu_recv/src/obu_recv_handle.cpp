
#include <ros/ros.h>
#include "obu_recv_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_obu_recv {

// Constructor
ObuRecvHandle::ObuRecvHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    obu_recv_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  obu_recv_.socketComSetup();
  sock_fd_ = obu_recv_.getSockfd();
  publishToTopics();
}

// Getters
int ObuRecvHandle::getNodeRate() const { return node_rate_; }

// Methods
void ObuRecvHandle::loadParameters() {
  // ROS_INFO("loading handle parameters");
  // if (!nodeHandle_.param<std::string>("vision_cone_detections_topic_name",
  //                                     vision_cone_detections_topic_name_,
  //                                     "/perception/vision/cone_detections")) {
  //   ROS_WARN_STREAM(
  //       "Did not load vision_cone_detections_topic_name. Standard value is: " << vision_cone_detections_topic_name_);
  // }
  if (!nodeHandle_.param<std::string>("v2v_info_topic_name",
                                      v2v_info_topic_name_,
                                      "/drivers/v2vinfo")) {
    ROS_WARN_STREAM("Did not load v2v_info_topic_name. Standard value is: " << v2v_info_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
}


void ObuRecvHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  v2vInfoPublisher_ = nodeHandle_.advertise<common_msgs::V2V>(v2v_info_topic_name_, 1);
}

void ObuRecvHandle::run() {
  obu_recv_.runAlgorithm();
  sendMsg();
}

void ObuRecvHandle::sendMsg() {
  v2vInfoPublisher_.publish(obu_recv_.getV2VInfo());
}


}