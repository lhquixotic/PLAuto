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

#ifndef CANSEND_HPP
#define CANSEND_HPP

#include "std_msgs/String.h"
#include "can_msgs/Frame.h"
#include "can_msgs/Frames.h"
// #include "common_msgs/ChassisControl.h"
#include "ID_0x04EF8480.h"
#include "ID_0x0C040B2A.h"
#include "Steer_Cmd_Msg.h"

extern ID_0x04EF8480 *id_0x04EF8480;
extern ID_0x0C040B2A *id_0x0C040B2A;
extern Steer_Cmd_Msg * steer_cmd_msg;

namespace ns_cansend {

class Cansend {

 public:
  // Constructor
  Cansend(ros::NodeHandle &nh);
  ~Cansend();

  // Getters
  can_msgs::Frame getFrame(protocol *frame);
  can_msgs::Frames getFrames();  
  // Setters
  // void setChassisControl(common_msgs::ChassisControl msg);
  // can_msgs::Frames sendframes;
  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;
  int rolling_counter;
 

  // common_msgs::ChassisControl chassis_control_cmd;

};
}

#endif //CANSEND_HPP
