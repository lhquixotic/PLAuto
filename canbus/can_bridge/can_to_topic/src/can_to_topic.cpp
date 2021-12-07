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
  can_msgs::Frame frame;
  frame.id = 0x00000345;
  frame.dlc = 8;
  frame.is_error = 0;
  frame.is_extended = 1;
  frame.is_rtr = 0;
  for (int i = 0;i < 8;i++){
      frame.data[i] = i+3;
  }
  test_frames.push_back(frame);
};

// Getters
// fsd_common_msgs::ConeDetections CanToTopic::getConeDetections() { return cone_current; }
// //FIXME: get value from next layer.

// Setters
void CanToTopic::setCanParameters(const Para & msg){
  can_para = msg;
}

void CanToTopic::initializeCanDevice(){
  likecan.setCanParameters(can_para);
  // likecan.openCanDevice();
  DWORD device_handle = can_info.can_device_handle;
  likecan.readCanDeviceInfo(1);
  // likecan.openCanChannel(0);  
}

void CanToTopic::runAlgorithm() {
  // while (1){
  //   likecan.recvProc();
  //   likecan.sendProc(test_frames);
  // }
  
}

}
