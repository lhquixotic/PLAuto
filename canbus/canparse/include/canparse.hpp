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

#ifndef CANPARSE_HPP
#define CANPARSE_HPP

#include "common_msgs/ChassisState.h"
#include "std_msgs/String.h"
#include <can_msgs/Frame.h>
#include "ID_0x00000650.h"
#include "ID_0x0000005A.h"
#include "ID_0x18F01D48.h"
#include "ID_0x18F02501.h"
#include"ID_0x18F02502.h"
#include "ID_0x18F02505.h"
#include"ID_0x18FF4BD1.h"
#include"ID_0x00000059.h"
#include"ID_0x00000151.h"

namespace ns_canparse {

class Canparse {

 public:
  // Constructor
  Canparse(ros::NodeHandle &nh);
  ID_0x00000650 id_0x00000650;
  ID_0x0000005A id_0x0000005A;
  ID_0x18F01D48 id_0x18F01D48;
  ID_0x18F02501 id_0x18F02501;
  ID_0x18F02502 id_0x18F02502;
  ID_0x18F02505 id_0x18F02505;
  ID_0x18FF4BD1 id_0x18FF4BD1;
  ID_0x00000059 id_0x00000059;
  ID_0x00000151 id_0x00000151;

  // Getters
  common_msgs::ChassisState getChassisState();

  // Setters
  void Parse(can_msgs::Frame f);

  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;

  common_msgs::ChassisState chassis_state;

};
}

#endif //CANPARSE_HPP
