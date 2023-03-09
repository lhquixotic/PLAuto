#ifndef CANPARSE_HANDLE_HPP
#define CANPARSE_HANDLE_HPP

#include "canparse.hpp"

namespace ns_canparse {

class CanparseHandle {

 public:
  // Constructor
  CanparseHandle(ros::NodeHandle &nodeHandle);

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
  ros::Subscriber canbusReceiveSubscriber_;
  ros::Publisher vehicleDynamicStatePublisher_;
  ros::Publisher chassisStatusPublisher_;

  void CanbusReceiveCallback(const can_msgs::Frames &msg);

  std::string vehicle_dynamic_state_topic_name_; 
  std::string canbus_receive_topic_name_;
  std::string chassis_status_topic_name_;

  int node_rate_;

  Canparse canparse_;

};
}

#endif //CANPARSE_HANDLE_HPP
