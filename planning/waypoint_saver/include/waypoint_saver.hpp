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

#ifndef WAYPOINT_SAVER_HPP
#define WAYPOINT_SAVER_HPP

#include "std_msgs/String.h"
#include "common_msgs/VehicleDynamicState.h"
#include "nav_msgs/Odometry.h"

namespace ns_waypoint_saver {

class Wp_saver {

 public:
  // Constructor
  Wp_saver(ros::NodeHandle &nh);

  // Getters

  // Setters
  void setLocalization(nav_msgs::Odometry msg);
  void setVehicleDynamicState(const common_msgs::VehicleDynamicState &msg);
  void runAlgorithm(double min_dis, std::string file_name);
  inline double distance_compute(nav_msgs::Odometry msg1, nav_msgs::Odometry msg2);
  void write2File(std::string waypoint_filename, nav_msgs::Odometry msg,common_msgs::VehicleDynamicState vd);

 private:

  ros::NodeHandle &nh_;

  nav_msgs::Odometry cur_pose;
  nav_msgs::Odometry recorded_pose;
  common_msgs::VehicleDynamicState vehicle_dynamic_state;

};
}
#endif //WAYPOINT_SAVER_HPP
