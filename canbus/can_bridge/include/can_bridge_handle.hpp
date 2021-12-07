#ifndef CAN_BRIDGE_HANDLE_HPP
#define CAN_BRIDGE_HANDLE_HPP

#include "likecan.hpp"

namespace ns_can_bridge {

class CanBridgeHandle {

 public:
  CanBridgeHandle(ros::NodeHandle &nodeHandle);
  void loadParameters();
  std::string can_msgs_topic_name_;
  Para can_para_; 

 private:
  ros::NodeHandle nodeHandle_;
};
}

#endif //CAN_BRIDGE_HANDLE_HPP
