#ifndef TEMPLATE_HANDLE_HPP
#define TEMPLATE_HANDLE_HPP

#include "fsd_common_msgs/ConeDetections.h"
#include "template.hpp"

namespace ns_template {

class TemplateHandle {

 public:
  // Constructor
  TemplateHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  // void sendVisualization();

 private:
  ros::NodeHandle nodeHandle_;
  ros::Subscriber visionConeDetectionsSubscriber_;
  ros::Publisher templateStatePublisher_;

  void visionConeDetectionsCallback(const fsd_common_msgs::ConeDetections &cones);// FIXME:change the name of callback function.

  std::string vision_cone_detections_topic_name_; // FIXME:change the topic name
  std::string template_state_topic_name_;

  int node_rate_;

  Template template_;
  Para para_;

};
}

#endif //TEMPLATE_HANDLE_HPP
