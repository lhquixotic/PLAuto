#ifndef TOPIC_TO_CAN_HANDLE_HPP
#define TOPIC_TO_CAN_HANDLE_HPP

#include "topic_to_can.hpp"

namespace ns_topic_to_can {

class TopicToCanHandle {

 public:
  // Constructor
  TopicToCanHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();

 private:
  ros::NodeHandle nodeHandle_;
  
  ros::Publisher canHandlePublisher_;
  ros::Subscriber canMsgsSubscriber_;

  void canMsgsCallback(const can_msgs::Frame &msg);

  std::string can_msgs_topic_name_;
  std::string can_handle_topic_name_;

  int node_rate_;
  Para can_para_; 

  TopicToCan topic_to_can_;

};
}

#endif //TOPIC_TO_CAN_HANDLE_HPP
