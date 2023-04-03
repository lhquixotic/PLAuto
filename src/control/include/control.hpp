#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "common_msgs/StopDecision.h"
#include "autoware_msgs/Lane.h"
// #include "common_msgs/V2V.h"
#include "common_msgs/VehicleState.h"
#include "common_msgs/ControlCommand.h"
#include "nav_msgs/Odometry.h"
#include "common_msgs/PlatoonState.h"


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
  int  longitudinal_mode; // 1:constant speed, 2: planned speed, 3: desired distance 4: trajectory reference
  double desired_speed;
  double desired_distance;
};

class Control {

 public:
  // Constructor
  Control(ros::NodeHandle &nh);

  // Getters
  common_msgs::ControlCommand getControlCommand();
  geometry_msgs::PointStamped getLookaheadPoint();

  // Setters
  void setFinalWaypoints(const autoware_msgs::Lane &msg);
  void setEgoState(const common_msgs::VehicleState &mgs);
  void setPlatoonState(const common_msgs::PlatoonState &msg);
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
  bool egoStateFlag = false;
  bool v2vInfoFlag = false;
  bool utmPoseFlag = false;

 private:

  ros::NodeHandle &nh_;

  autoware_msgs::Lane final_waypoints;
  common_msgs::VehicleState ego_state;
  common_msgs::ControlCommand control_cmd;
  nav_msgs::Odometry utm_pose;
  common_msgs::PlatoonState platoon_state;
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
  int nearest_idx;
  int findLookAheadWaypoint(float lookAheadDistance);
};
}

#endif //CONTROL_HPP
