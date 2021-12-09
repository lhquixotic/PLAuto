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

#ifndef CANPARSE_HANDLE_HPP
#define CANPARSE_HANDLE_HPP

#include "canparse.hpp"

namespace ns_canparse {

class CanparseHandle {

 public:
  // Constructor
  CanparseHandle(ros::NodeHandle &nodeHandle);

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
  ros::Subscriber canbus_receive_Subscriber_;
  ros::Publisher chassisStatePublisher_;

  void CanbusReceiveCallback(const can_msgs::Frame &f);

  std::string chassis_state_topic_name_; 
  std::string canbus_receive_topic_name_;

  int node_rate_;

  Canparse canparse_;

};
}

#endif //CANPARSE_HANDLE_HPP
