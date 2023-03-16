#include <ros/ros.h>
#include "template_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_template {

// Constructor
TemplateHandle::TemplateHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    template_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  loadParameters();
  template_.setParameters(para_);
  subscribeToTopics();
  publishToTopics();
}

// Getters
int TemplateHandle::getNodeRate() const { return node_rate_; }

// Methods
void TemplateHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("vision_cone_detections_topic_name",
                                      vision_cone_detections_topic_name_,
                                      "/perception/vision/cone_detections")) {
    ROS_WARN_STREAM(
        "Did not load vision_cone_detections_topic_name. Standard value is: " << vision_cone_detections_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("template_state_topic_name",
                                      template_state_topic_name_,
                                      "/perception/vision/state")) {
    ROS_WARN_STREAM("Did not load template_state_topic_name. Standard value is: " << template_state_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  //nodeHandle_.param("config_name",variable_name,value);
}

void TemplateHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  visionConeDetectionsSubscriber_ =
      nodeHandle_.subscribe(vision_cone_detections_topic_name_, 1, &TemplateHandle::visionConeDetectionsCallback, this);
}//FIXME: change topic name you want to subscribe.

void TemplateHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  templateStatePublisher_ = nodeHandle_.advertise<fsd_common_msgs::ConeDetections>(template_state_topic_name_, 1);
}//FIXME: change topic name you want to advertise.

void TemplateHandle::run() {
  std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  template_.runAlgorithm();
  std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  double time_round = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1).count();
  std::cout << "time cost = " << time_round << ", frequency = " << 1 / time_round << std::endl;
  sendMsg();
}

void TemplateHandle::sendMsg() {
  templateStatePublisher_.publish(template_.getConeDetections());
}//FIXME: change the msg name you want to publish.

void TemplateHandle::visionConeDetectionsCallback(const fsd_common_msgs::ConeDetections &cones) {
  template_.setConeDetections(cones);
}//FIXME: change or add callback functions to receive msgs.
}