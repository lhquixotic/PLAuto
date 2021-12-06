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

#ifndef CAN_TO_TOPIC_HPP
#define CAN_TO_TOPIC_HPP

#include "fsd_common_msgs/ConeDetections.h"
#include "std_msgs/String.h"

namespace ns_can_to_topic {

class CanToTopic {

 public:
  // Constructor
  CanToTopic(ros::NodeHandle &nh);

  // Getters
  fsd_common_msgs::ConeDetections getConeDetections();//FIXME: change value names you want to get from config files.

  // Setters
  void setConeDetections(fsd_common_msgs::ConeDetections cones);//FIXME: change value names you want to get from subscribers: msg type & function name.

  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;

  fsd_common_msgs::ConeDetections cone_current;//FIXME: change value names you want to get from subscriber.

};
}

#endif //CAN_TO_TOPIC_HPP
