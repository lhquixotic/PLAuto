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

#ifndef WAYPOINT_LOADER_HANDLE_HPP
#define WAYPOINT_LOADER_HANDLE_HPP

#include "autoware_msgs/Lane.h"
#include "autoware_msgs/Waypoint.h"
#include "waypoint_loader.hpp"

namespace ns_waypoint_loader {

class Waypoint_loaderHandle {

 public:
  // Constructor
  Waypoint_loaderHandle(ros::NodeHandle &nodeHandle);

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
  ros::Publisher waypoint_loaderStatePublisher_;
  ros::Publisher waypoint_loaderVisualPublisher_;
  std::string waypoint_loader_state_topic_name_;
  std::string waypoint_loader_visual_topic_name_;

  int node_rate_;
  std::string waypoint_filename_;

  Waypoint_loader waypoint_loader_;
  
};
}

#endif //WAYPOINT_LOADER_HANDLE_HPP
