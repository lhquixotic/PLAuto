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

#ifndef CANSEND_HANDLE_HPP
#define CANSEND_HANDLE_HPP

#include "cansend.hpp"

namespace ns_cansend {

class CansendHandle {

 public:
  // Constructor
  CansendHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();

 private:
  ros::NodeHandle nodeHandle_;
  // ros::Subscriber chassisControlSubscriber_;
  ros::Publisher cansendStatePublisher_;

  // void chassisControlCallback(const common_msgs::ChassisControl &msg);

  // std::string chassis_control_topic_name_;
  std::string cansend_topic_name_;
  // can_msgs::Frames sendframes;

  int node_rate_;

  Cansend cansend_;

};
}

#endif //CANSEND_HANDLE_HPP
