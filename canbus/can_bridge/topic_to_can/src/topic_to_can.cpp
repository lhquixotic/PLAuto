#include <ros/ros.h>
#include "topic_to_can.hpp"
#include <sstream>

namespace ns_topic_to_can {
// Constructor
TopicToCan::TopicToCan(ros::NodeHandle &nh) : nh_(nh) {
  can_msgs::Frame frame;
  frame.id = 0x00000345;
  frame.dlc = 8;
  frame.is_error = 0;
  frame.is_extended = 1;
  frame.is_rtr = 0;
  for (int i = 0;i < 8;i++){
      frame.data[i] = i+3;
  }
  test_frames.push_back(frame);
};

// Getters
void TopicToCan::setCanParameters(const Para &msg){
    can_para =  msg;
}

void TopicToCan::initializeCanDevice(){
    likecan.setCanParameters(can_para);
  likecan.openCanDevice(); // TODO: check success or not
  likecan.readCanDeviceInfo();
  likecan.openCanChannel(0);  
}

void TopicToCan::runAlgorithm() {
  likecan.sendProc(test_frames);
}
}
