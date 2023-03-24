
#ifndef WAYPOINT_RECONSTRUCTOR_HPP
#define WAYPOINT_RECONSTRUCTOR_HPP

#include <deque>
#include "common_msgs/GpsInfo.h"
#include "common_msgs/V2V.h"
#include "common_msgs/PlatoonState.h"
#include "autoware_msgs/Lane.h"
#include "std_msgs/String.h"
#include "tf/transform_datatypes.h"//转换函数头文件
#include <nav_msgs/Odometry.h>//里程计信息格式
#include <nav_msgs/Path.h>
#include "tf/transform_datatypes.h"

namespace ns_waypoint_reconstructor {

class Waypoint_Reconstructor {

 public:
  // Constructor
  Waypoint_Reconstructor(ros::NodeHandle &nh);

  // Getters
  autoware_msgs::Lane getFinalWaypoints();
  geometry_msgs::PoseStamped getCurrentPose();
  nav_msgs::Path getFinalWaypointsVis();
  nav_msgs::Odometry getLeaderPose();

  // Setters
  void setSelfPose(const nav_msgs::OdometryConstPtr &msg);
  void setV2V(const common_msgs::V2VConstPtr &msg);
  void setPlatoonState(const common_msgs::PlatoonStateConstPtr &msg);
  
  void initWaypoints();
  void updateWaypoints();
  void updateLane();
  void runAlgorithm();
  bool isInited();
 private:
  double getPlaneDistance(geometry_msgs::Point,geometry_msgs::Point);
  ros::NodeHandle &nh_;
  bool initFlag;

  nav_msgs::Odometry leader_pose;
  // common_msgs::V2V v2v_info;
  common_msgs::PlatoonState platoon_state;

  autoware_msgs::Lane lane;
  geometry_msgs::Pose current_pose;
  nav_msgs::Path leader_path_vis;
  geometry_msgs::Point current_leader_point,current_follower_point;
  std::deque<geometry_msgs::Point> leader_path;
};
}

#endif //WAYPOINT_RECONSTRUCTOR_HPP
