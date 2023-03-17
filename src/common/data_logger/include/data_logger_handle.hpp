#ifndef DATA_LOGGER_HANDLE_HPP
#define DATA_LOGGER_HANDLE_HPP

#include "data_logger.hpp"

namespace ns_data_logger {

class DataLoggerHandle {

 public:
  // Constructor
  DataLoggerHandle(ros::NodeHandle &nodeHandle);

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
  ros::Subscriber localizationSubscriber_;
  ros::Subscriber chassisStateSubscriber_;
  ros::Subscriber controlCommandSubscriber_;
  ros::Subscriber logTriggerSubscriber_;

  void localizationCallback(const nav_msgs::Odometry &msg);
  void chassisStateCallback(const common_msgs::ChassisState &msg);
  void controlCommandCallback(const common_msgs::ChassisControl &msg);
  void logTriggerCallback(const common_msgs::Trigger &msg);

  std::string localization_topic_name_;
  std::string chassis_state_topic_name_;
  std::string control_command_topic_name_;
  std::string log_trigger_topic_name_;

  int node_rate_;

  int localization_flag = 0;
  int chassis_state_flag = 0;
  int control_command_flag = 0;

  DataLogger data_logger_;
  common_msgs::Trigger log_trigger_;
  Para para_;

};
}

#endif //DATA_LOGGER_HANDLE_HPP
