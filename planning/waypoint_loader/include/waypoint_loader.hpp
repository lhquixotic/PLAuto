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

#ifndef WAYPOINT_LOADER_HPP
#define WAYPOINT_LOADER_HPP

#define INFO_NUM 3

#include <autoware_msgs/Lane.h>
#include <autoware_msgs/Waypoint.h>
#include "nav_msgs/Path.h"
#include "std_msgs/String.h"
#include <fstream>

namespace ns_waypoint_loader {

class Waypoint_loader {

 public:
  // Constructor
  Waypoint_loader(ros::NodeHandle &nh);

  // Getters
  autoware_msgs::Lane getGlobalPath();
  nav_msgs::Path getGlobalPathVisual();
  
  // Methods
  void loadWaypointFile(std::string filename);


  void runAlgorithm();

 private:
  ros::NodeHandle &nh_;

  std::fstream waypoint_record_file;

  autoware_msgs::Lane global_path;
  nav_msgs::Path global_path_rviz;

};
}

#endif //WAYPOINT_LOADER_HPP
