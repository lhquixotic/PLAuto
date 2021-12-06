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
#include "can_to_topic.hpp"
#include <sstream>

namespace ns_can_to_topic {
// Constructor
CanToTopic::CanToTopic(ros::NodeHandle &nh) : nh_(nh) {

};//FIXME:load config params.

// Getters
fsd_common_msgs::ConeDetections CanToTopic::getConeDetections() { return cone_current; }
//FIXME: get value from next layer.

// Setters
void CanToTopic::setConeDetections(fsd_common_msgs::ConeDetections cones) {
  cone_current = cones;
}// FIXME:set value from subscriber or config files.

void CanToTopic::runAlgorithm() {

}//FIXME:add code you want to execute.

}
