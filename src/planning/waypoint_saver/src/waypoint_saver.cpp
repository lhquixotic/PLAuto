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

#include <ros/ros.h>
#include "waypoint_saver.hpp"
#include "nav_msgs/Odometry.h"
#include <sstream>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>

namespace ns_waypoint_saver {
// Constructor
Wp_saver::Wp_saver(ros::NodeHandle &nh) : nh_(nh) {
  cur_pose.pose.pose.position.x = 0.0;
  recorded_pose.pose.pose.position.x = 0.0;
};

// Getters

// Setters
void Wp_saver::setLocalization (nav_msgs::Odometry msg) {
  cur_pose = msg;
}
void Wp_saver::setVehicleDynamicState(const common_msgs::VehicleDynamicState &msg){
  vehicle_dynamic_state = msg;
}

void Wp_saver::runAlgorithm(double min_dis, std::string waypoint_filename) {
  //TODO: add code to record the waypoint into waypoint_filename

  std::string output_x = std::to_string(recorded_pose.pose.pose.position.x);
  std::string output_dis = std::to_string(distance_compute(recorded_pose, cur_pose));

  if (distance_compute(cur_pose, recorded_pose) > min_dis){
  ROS_INFO_STREAM("recorded position x is " + output_x);
  ROS_INFO_STREAM("distance is " + output_dis);
  recorded_pose = cur_pose;
  write2File(waypoint_filename, recorded_pose,vehicle_dynamic_state);
  }

}

inline double Wp_saver::distance_compute(nav_msgs::Odometry msg1, nav_msgs::Odometry msg2) {

  double x_dist = msg2.pose.pose.position.x - msg1.pose.pose.position.x;
  double y_dist = msg2.pose.pose.position.y - msg1.pose.pose.position.y;

  double dist = std::sqrt(x_dist * x_dist + y_dist * y_dist);

  return dist;
}

void Wp_saver::write2File(std::string waypoint_filename, nav_msgs::Odometry msg, common_msgs::VehicleDynamicState vd) {

  std::string x = std::to_string(msg.pose.pose.position.x);
  std::string y = std::to_string(msg.pose.pose.position.y);
  std::string v = std::to_string(vd.vehicle_speed);

  std::fstream f;
  f.open(waypoint_filename, std::ios::out|std::ios::app);
  f << x + "," + y + ","+ v<< std::endl;
  f.close();

  }

}
