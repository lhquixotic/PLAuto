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
#include "waypoint_saver_handle.hpp"

typedef ns_waypoint_saver::Wp_saverHandle Wp_saverHandle;

int main(int argc, char **argv) {

  ros::init(argc, argv, "waypoint_saver");
  ros::NodeHandle nodeHandle("~");
  Wp_saverHandle myWp_saverHandle(nodeHandle);
  ros::Rate loop_rate(myWp_saverHandle.getNodeRate());
  double min_dis = myWp_saverHandle.getMinDis();
  
  while (ros::ok()) {

    myWp_saverHandle.run();

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }

  return 0;

}

