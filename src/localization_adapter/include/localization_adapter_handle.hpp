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

#ifndef LOCALIZATION_ADAPTER_HANDLE_HPP
#define LOCALIZATION_ADAPTER_HANDLE_HPP

#include "localization_adapter.hpp"

namespace ns_localization_adapter {

class Localization_adapterHandle {

 public:
  // Constructor
  Localization_adapterHandle(ros::NodeHandle &nodeHandle);

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
  ros::Subscriber simulationPoseSubscriber_;
  ros::Subscriber gpsInfoSubscriber_;
  ros::Publisher utmPosePublisher_;

  // void simulationPoseCallback(const geometry_msgs::PoseStamped &msg);
  void simulationOdomCallback(const nav_msgs::Odometry &msg);
  void gpsInfoCallback(const common_msgs::GpsInfo &msg);

  std::string simulation_pose_topic_name_;
  std::string gps_info_topic_name_;
  std::string localization_utm_topic_name_;

  int node_rate_;
  std::string run_mode_;

  Localization_adapter localization_adapter_;
  utm::Gps_point origin_;
  utm::Gps_para para_;

};
}

#endif //LOCALIZATION_ADAPTER_HANDLE_HPP
