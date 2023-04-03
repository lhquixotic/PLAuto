#ifndef CONTROL_HANDLE_HPP
#define CONTROL_HANDLE_HPP

#include "control.hpp"

namespace ns_control {

class ControlHandle {

 public:
  // Constructor
  ControlHandle(ros::NodeHandle &nodeHandle);

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
  ros::Subscriber stopFlagSubscriber_;
  ros::Subscriber finalWaypointsSubscriber_;
  ros::Subscriber egoStateSubscriber_;
  ros::Subscriber platoonStateSubscriber_;
  ros::Subscriber utmPoseSubscriber_;

  ros::Publisher controlCommandPublisher_;
  ros::Publisher lookaheadpointPublisher_;

  void stopFlagCallback(const common_msgs::StopDecision &msg);
  void finalWaypointsCallback(const autoware_msgs::Lane &msg);
  void egoStateCallback(const common_msgs::VehicleState &msg); 
  void platoonStateCallback(const common_msgs::PlatoonState &msg);
  void utmPoseCallback(const nav_msgs::Odometry &msg);

  std::string stop_flag_topic_name_;
  std::string final_waypoints_topic_name_;
  std::string ego_state_topic_name_;
  std::string platoon_state_topic_name_;
  std::string localization_utm_topic_name_;
  std::string lookahead_point_topic_name_;

  std::string control_command_topic_name_;

  int node_rate_;
  int control_mode_;
  int stop_flag_;
  Para control_para_;
  Pid_para pid_para_;
  Pure_pursuit_para pp_para_;

  Control control_;

};
}

#endif //CONTROL_HANDLE_HPP
