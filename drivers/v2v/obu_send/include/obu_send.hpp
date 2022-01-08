#ifndef OBU_SEND_HPP
#define OBU_SEND_HPP

#include "common_msgs/GpsInfo.h"
#include "common_msgs/VehicleDynamicState.h"
#include "common_msgs/ChassisStatus.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/Vector3.h"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <boost/thread/thread.hpp>
#include <nav_msgs/Odometry.h>

#include <sstream>

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <vector>

#include "std_msgs/String.h"

#define DEST_PORT 11255
#define DSET_IP_ADDRESS  "192.168.20.224"

namespace ns_obu_send {
  static void _split(const std::string& s, char delim, std::vector<std::string>& elems);
  std::vector<std::string> split(const std::string& s, char delim);
  void multi_callback(const common_msgs::ChassisStatus::ConstPtr& chassis, 
    const nav_msgs::Odometry::ConstPtr& pose, 
		const common_msgs::VehicleDynamicState::ConstPtr& vehicle);

class ObuSend {

 public:
  // Constructor
  ObuSend(ros::NodeHandle &nh);

  // Getters
  int getSockfd();
  struct sockaddr_in getSockaddr();
  int getSocklen();

  // Setters
  void setChassisStatus(common_msgs::ChassisStatus msg);
  void setVehicleDynamicState(common_msgs::VehicleDynamicState msg);
  void setUtmPose(nav_msgs::Odometry msg);

  void socketComSetup();
  void runAlgorithm();


 private:

  ros::NodeHandle &nh_;
  
  struct sockaddr_in addr_serv;
  int len;
  int sock_fd;

  common_msgs::ChassisStatus chassis_status;
  common_msgs::VehicleDynamicState vehicle_dynamic_state;
  // common_msgs::GpsInfo gps_info;
  nav_msgs::Odometry utm_pose;
};
}

#endif //OBU_SEND_HPP
