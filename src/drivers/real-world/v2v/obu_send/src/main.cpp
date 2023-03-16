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
#include "obu_send_handle.hpp"

typedef ns_obu_send::ObuSendHandle ObuSendHandle;

int main(int argc, char **argv) {
  ros::init(argc, argv, "obu_send");
  ros::NodeHandle nodeHandle("~");
  ObuSendHandle myObuSendHandle(nodeHandle);
  ros::Rate loop_rate(myObuSendHandle.getNodeRate());
  // message_filters::Subscriber <common_msgs::ChassisStatus> subscriber_chassis(myObuSendHandle,myObuSendHandle.chassis_status_topic_name_,1000,
  //                             ros::TransportHints().tcpNoDelay());
  // message_filters::Subscriber <common_msgs::GpsInfo> subscriber_gps(myObuSendHandle,myObuSendHandle.gps_info_topic_name_,1000,
  //                             ros::TransportHints().tcpNoDelay());
  // message_filters::Subscriber <common_msgs::VehicleDynamicState> subscriber_vehicle(myObuSendHandle,myObuSendHandle.vehicle_dynamic_state_topic_name_,1000,
  //                             ros::TransportHints().tcpNoDelay());
  // typedef message_filters::sync_policies::ApproximateTime <common_msgs::ChassisStatus, common_msgs::GpsInfo, common_msgs::VehicleDynamicState> syncPolicy;
  // message_filters::Synchronizer<syncPolicy> sync(syncPolicy(10), subscriber_chassis, subscriber_gps, subscriber_vehicle);  
  // sync.registerCallback(boost::bind(&multi_callback, _1, _2, _3));
  while (ros::ok()) {

    myObuSendHandle.run();

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  close(myObuSendHandle.sock_fd_);
  return 0;
}

