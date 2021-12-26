#ifndef CANSEND_HANDLE_HPP
#define CANSEND_HANDLE_HPP

#include "cansend.hpp"

namespace ns_cansend {

class CansendHandle {

 public:
  // Constructor
  CansendHandle(ros::NodeHandle &nodeHandle);

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
  
  ros::Subscriber controlCmdSubscriber_;
  ros::Subscriber chassisStatusSubscriber_;
  ros::Publisher cansendPublisher_;
  std::string control_cmd_topic_name_;
  std::string cansend_topic_name_;
  std::string chassis_status_topic_name_;

  int node_rate_;
  Para para_;

  Cansend cansend_;
  void controlCmdCallback(const autoware_msgs::ControlCommand & msg);
  void chassisStatusCallback(const common_msgs::ChassisStatus & msg);
};
}

#endif //CANSEND_HANDLE_HPP
