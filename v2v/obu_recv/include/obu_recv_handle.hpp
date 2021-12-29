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

#ifndef OBU_RECV_HANDLE_HPP
#define OBU_RECV_HANDLE_HPP


#include "obu_recv.hpp"

namespace ns_obu_recv {

class ObuRecvHandle {

 public:
  // Constructor
  ObuRecvHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void publishToTopics();
  void run();
  void sendMsg();
  int sock_fd_;

 private:
  ros::NodeHandle nodeHandle_;
  ros::Publisher v2vInfoPublisher_;


  std::string v2v_info_topic_name_;

  int node_rate_;

  ObuRecv obu_recv_;

};
}

#endif //OBU_RECV_HANDLE_HPP
