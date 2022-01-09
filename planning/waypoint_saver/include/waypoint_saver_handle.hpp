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

#ifndef WAYPOINT_SAVER_HANDLE_HPP
#define WAYPOINT_SAVER_HANDLE_HPP

#include "waypoint_saver.hpp"


namespace ns_waypoint_saver {

class Wp_saverHandle {

 public:
  // Constructor
  Wp_saverHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;
  double getMinDis() const{ return min_dis_; }

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  // void sendVisualization();

 private:
  ros::NodeHandle nodeHandle_;
  ros::Subscriber localizationSubscriber_;

  void localizationCallback(const nav_msgs::Odometry &msg);

  std::string localization_topic_name_;

  std::string waypoint_filename_;
  int node_rate_;
  double min_dis_;

  Wp_saver waypoint_saver_;

};

}

#endif //WAYPOINT_SAVER_HANDLE_HPP
