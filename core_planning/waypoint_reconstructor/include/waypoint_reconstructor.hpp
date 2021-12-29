/*
    Formula Student Driverless Project (FSD-Project).
    Copyright (c) 2019:
     - chentairan <killasipilin@gmail.com>

    FSD-Project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FSD-Project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FSD-Project.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef WAYPOINT_RECONSTRUCTOR_HPP
#define WAYPOINT_RECONSTRUCTOR_HPP

#include <deque>
#include "common_msgs/GpsInfo.h"
#include "common_msgs/V2V.h"
#include "autoware_msgs/Lane.h"
#include "std_msgs/String.h"
#include "gps_convert.h"
#include "gps2utm.hpp"
#include "tf/transform_datatypes.h"//转换函数头文件
#include <nav_msgs/Odometry.h>//里程计信息格式


namespace ns_waypoint_reconstructor {

class Waypoint_Reconstructor {

 public:
  // Constructor
  Waypoint_Reconstructor(ros::NodeHandle &nh);

  // Getters
  autoware_msgs::Lane getFinalWaypoints();
  geometry_msgs::PoseStamped getCurrentPose();
  // Setters
  //void setConeDetections(autoware_msgs::ConeDetections cones);//FIXME: change value names you want to get from subscribers: msg type & function name.
  void setSelfPose(const nav_msgs::OdometryConstPtr &msg);
  void setV2V(const common_msgs::V2VConstPtr &msg);
  void setGpsOrigin(const utm::Gps_point &msg);
  
  void initWaypoints();
  void updateWaypoints();
  void updateLane();
  void runAlgorithm();
  bool isInited();
 private:
  double getPlaneDistance(geometry_msgs::Point,geometry_msgs::Point);
  ros::NodeHandle &nh_;
  bool initFlag;
  common_msgs::GpsInfo gpsinfo_;
  common_msgs::V2V v2v_;//FIXME: change value names you want to get from subscriber.
  autoware_msgs::Lane lane_;
  geometry_msgs::Pose current_pose;
  utm::Gps_point origin;
  geometry_msgs::Point current_leader_point,current_follower_point;
  std::deque<geometry_msgs::Point> leader_path;
};
}

#endif //WAYPOINT_RECONSTRUCTOR_HPP
