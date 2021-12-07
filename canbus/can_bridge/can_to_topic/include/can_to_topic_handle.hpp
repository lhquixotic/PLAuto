
#ifndef CAN_TO_TOPIC_HANDLE_HPP
#define CAN_TO_TOPIC_HANDLE_HPP

#include "can_to_topic.hpp"

namespace ns_can_to_topic {

class CanToTopicHandle {

 public:
  // Constructor
  CanToTopicHandle(ros::NodeHandle &nodeHandle);

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
  ros::Publisher can_to_topicStatePublisher_;
  ros::Subscriber canInfoSubscriber_;

  void canInfoCallback(const can_msgs::CanInfo &msg);

  // void visionConeDetectionsCallback(const fsd_common_msgs::ConeDetections &cones);// FIXME:change the name of callback function.
  std::string can_info_topic_name_;
  std::string can_to_topic_state_topic_name_;

  int node_rate_;
  
   Para can_para_;
  CanToTopic can_to_topic_;

};
}

#endif //CAN_TO_TOPIC_HANDLE_HPP
