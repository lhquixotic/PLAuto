#ifndef CAN_TO_TOPIC_HPP
#define CAN_TO_TOPIC_HPP

#include "std_msgs/String.h"
#include "can_msgs/Frame.h"
#include "can_msgs/CanInfo.h"
#include "likecan.hpp"


namespace ns_can_to_topic {

class CanToTopic {

 public:
  // Constructor
  CanToTopic(ros::NodeHandle &nh);

  // Getters
  // fsd_common_msgs::ConeDetections getConeDetections();//FIXME: change value names you want to get from config files.

  // Setters
  void setCanParameters(const Para &msg);

  void runAlgorithm();
  void initializeCanDevice();
  std::vector<can_msgs::Frame> test_frames;
  can_msgs::CanInfo can_info;


 private:
  Para can_para;
  ros::NodeHandle &nh_;
  LikeCan likecan;
       
  // fsd_common_msgs::ConeDetections cone_current;//FIXME: change value names you want to get from subscriber.

};
}

#endif //CAN_TO_TOPIC_HPP
