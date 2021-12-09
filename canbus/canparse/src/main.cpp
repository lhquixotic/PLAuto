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
#include "canparse_handle.hpp"

typedef ns_canparse::CanparseHandle CanparseHandle;

int main(int argc, char **argv) {
  ros::init(argc, argv, "canparse");
  ros::NodeHandle nodeHandle("~");
  CanparseHandle myCanparseHandle(nodeHandle);
  ros::Rate loop_rate(myCanparseHandle.getNodeRate());
  while (ros::ok()) {

    myCanparseHandle.run();

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  return 0;
}

