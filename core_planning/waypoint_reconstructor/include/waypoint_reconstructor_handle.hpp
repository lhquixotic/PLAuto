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

#ifndef WAYPOINT_RECONSTRUCTOR_HANDLE_HPP
#define WAYPOINT_RECONSTRUCTOR_HANDLE_HPP

#include "autoware_msgs/GpsInfo.h"
#include "autoware_msgs/V2V.h"
#include "autoware_msgs/Lane.h"
#include "waypoint_reconstructor.hpp"

namespace ns_waypoint_reconstructor {

class Waypoint_ReconstructorHandle {

 public:
  // Constructor
  Waypoint_ReconstructorHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  // void sendVisualization();

 private:
  ros::NodeHandle nodeHandle_,private_nh_;
  ros::Subscriber sub1_,sub2_;
  ros::Publisher pub1_,pub2_;

  void poseCallback(const nav_msgs::OdometryConstPtr &msg);// FIXME:change the name of callback function.
  void V2VCallback(const autoware_msgs::V2VConstPtr &msg);
  std::string current_pose_topic_name_,v2v_topic_name_; // FIXME:change the topic name
  std::string final_waypoint_topic_name_,pose_topic_name_,velocity_topic_name_;
  utm::Gps_point origin_;

  int node_rate_;
  bool poseFlag,v2vFlag;
  Waypoint_Reconstructor waypoint_reconstructor_;

};
}

#endif //WAYPOINT_RECONSTRUCTOR_HANDLE_HPP
