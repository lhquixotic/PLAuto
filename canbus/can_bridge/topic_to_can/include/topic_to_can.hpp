#ifndef TOPIC_TO_CAN_HPP
#define TOPIC_TO_CAN_HPP

#include "likecan.hpp"
#include "std_msgs/String.h"

namespace ns_topic_to_can {

class TopicToCan {

 public:
  // Constructor
  TopicToCan(ros::NodeHandle &nh);

  // Getters
  // fsd_common_msgs::ConeDetections getConeDetections();//FIXME: change value names you want to get from config files.

  // Setters
  void setCanParameters(const Para &msg);

  void runAlgorithm();
  void initializeCanDevice();
  std::vector<can_msgs::Frame>  frame_queue;

 private:

  ros::NodeHandle &nh_;

  Para can_para;
  LikeCan likecan;
  std::vector<can_msgs::Frame> test_frames;


};
}

#endif //TOPIC_TO_CAN_HPP
