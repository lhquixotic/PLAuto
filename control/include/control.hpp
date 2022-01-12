#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "autoware_msgs/Lane.h"
#include "common_msgs/V2V.h"
#include "common_msgs/VehicleDynamicState.h"
#include "autoware_msgs/ControlCommandStamped.h"
#include "nav_msgs/Odometry.h"


// #include "common_msgs/ControlCmd.h"
// #include "common_msgs/VehicleState.h"
// #include "geometry_msgs/Twist.h"
// #include "geometry_msgs/Point.h"

#include "std_msgs/String.h"
#include "pid.hpp"
#include "pure_pursuit.hpp"

namespace ns_control {

struct Para{
  bool longitudinal_control_switch;
  bool lateral_control_switch;
  int  longitudinal_mode; // 1:constant speed, 2: planned speed, 3: desired distance
  double desired_speed;
  double desired_distance;
};

class Control {

 public:
  // Constructor
  Control(ros::NodeHandle &nh);

  // Getters
  autoware_msgs::ControlCommandStamped getControlCommand();
  geometry_msgs::PointStamped getLookaheadPoint();

  // Setters
  void setFinalWaypoints(const autoware_msgs::Lane &msg);
  void setVehicleDynamicState(const common_msgs::VehicleDynamicState &mgs);
  void setV2VInfo(const common_msgs::V2V &msg);
  void setUtmPose(const nav_msgs::Odometry &msg);
  void setPidParameters(const Pid_para &msg);
  void setPurePursuitParameters(const Pure_pursuit_para &msg);
  void setControlParameters(const Para &msg);

  // Methods
  void runAlgorithm();
  void initializeController();
  void latControlUpdate();
  void longControlUpdate();
  bool finalWaypointsFlag = false;
  bool vehicleDynamicStateFlag = false;
  bool v2vInfoFlag = false;
  bool utmPoseFlag = false;

 private:

  ros::NodeHandle &nh_;

  autoware_msgs::Lane final_waypoints;
  common_msgs::VehicleDynamicState vehicle_dynamic_state;
  autoware_msgs::ControlCommand control_cmd;
  autoware_msgs::ControlCommandStamped ccs;
  nav_msgs::Odometry utm_pose;
  common_msgs::V2V v2v_info;
  geometry_msgs::Pose current_pose;
  geometry_msgs::Pose leader_pose;
  geometry_msgs::PointStamped lookahead_point;
  std::vector<autoware_msgs::Waypoint> current_waypoints;

  PID pid_controller;
  Pure_pursuit pp_controller;

  Pid_para pid_para;
  Pure_pursuit_para pp_para;
  Para control_para;
  
  // methods
  int next_waypoint_number_;
  int findLookAheadWaypoint(float lookAheadDistance);
};
}

#endif //CONTROL_HPP
