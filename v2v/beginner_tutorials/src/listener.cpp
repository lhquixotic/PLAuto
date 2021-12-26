#include "ros/ros.h"
#include "beginner_tutorials/V2V.h"
#include "beginner_tutorials/ChassisStatus.h"
#include "beginner_tutorials/GpsInfo.h"
#include "beginner_tutorials/VehicleDynamicState.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/Vector3.h"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <boost/thread/thread.hpp>

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


#define DEST_PORT 11255
#define DSET_IP_ADDRESS  "192.168.20.224"

int sock_fd;

struct sockaddr_in addr_serv;
int len;


static void _split(const std::string& s, char delim, std::vector<std::string>& elems) {
  std::stringstream ss(s);
  std::string item;
  while(std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
}

std::vector<std::string> split(const std::string& s, char delim) {
  std::vector<std::string> elems;
  _split(s, delim, elems);
  return elems;
}

void multi_callback(const beginner_tutorials::ChassisStatus::ConstPtr& chassis, 
		const beginner_tutorials::GpsInfo::ConstPtr& gpsinfo, 
		const beginner_tutorials::VehicleDynamicState::ConstPtr& vehicle) {
  ROS_INFO("i heard::");
  std::string s = "";
  s += std::to_string(gpsinfo->fix.latitude);
  s += " ";
  s += std::to_string(gpsinfo->fix.longitude);
  s += " ";
  s += std::to_string(gpsinfo->fix.altitude);
  s += " ";
  s += std::to_string(gpsinfo->rpy.x);
  s += " ";
  s += std::to_string(gpsinfo->rpy.y);
  s += " ";
  s += std::to_string(gpsinfo->rpy.z);
  s += " ";
  s += std::to_string(vehicle->vehicle_speed);
  s += " ";
  s += std::to_string(vehicle->vehicle_lon_acceleration);
  s += " ";
  s += std::to_string(vehicle->vehicle_lon_acceleration);
  s += " ";
  s += std::to_string(chassis->real_brake_pressure);
  s += " ";
  s += std::to_string(chassis->real_steer_angle);
  char c[s.size() + 1];
  strcpy(c, s.c_str());
  int send_num = sendto(sock_fd, c, strlen(c), 0, (struct sockaddr *)&addr_serv, len);

  if(send_num < 0)
  {
    perror("sendto error:");
    exit(1);
  }
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "V2VTalker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("/V2VData", 1000);
  ros::Rate loop_rate(10);
  int count = 0;


  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }


//  struct sockaddr_in addr_serv;
//  int len;
  memset(&addr_serv, 0, sizeof(addr_serv));
  addr_serv.sin_family = AF_INET;
  addr_serv.sin_addr.s_addr = inet_addr(DSET_IP_ADDRESS);
  addr_serv.sin_port = htons(DEST_PORT);
  len = sizeof(addr_serv);

  int send_num;
  int recv_num;
  // 发送接收数据时数组结尾加\0
  char send_buf[2] = {'1', '\0'};

  std::string ssss = send_buf;

  printf("client send: %s\n", ssss.c_str());

  send_num = sendto(sock_fd, send_buf, strlen(send_buf), 0, (struct sockaddr *)&addr_serv, len);

  if(send_num < 0)
  {
    perror("sendto error:");
    exit(1);
  }
  
 
    message_filters::Subscriber<beginner_tutorials::ChassisStatus> subscriber_chassis(n,"chassis_topic",1000,ros::TransportHints().tcpNoDelay());
    message_filters::Subscriber<beginner_tutorials::GpsInfo> subscriber_gps(n,"gps_topic",1000,ros::TransportHints().tcpNoDelay());
    message_filters::Subscriber<beginner_tutorials::VehicleDynamicState> subscriber_vehicle(n,"vehicle_topic",1000,ros::TransportHints().tcpNoDelay());
    
    typedef message_filters::sync_policies::ApproximateTime<beginner_tutorials::ChassisStatus, beginner_tutorials::GpsInfo, beginner_tutorials::VehicleDynamicState> syncPolicy;
    //message_filters::TimeSynchronizer<beginner_tutorials::ChassisStatus,beginner_tutorials::GpsInfo,beginner_tutorials::VehicleDynamicState> sync(subscriber_chassis, subscriber_gps, subscriber_vehicle, 10);
    message_filters::Synchronizer<syncPolicy> sync(syncPolicy(10), subscriber_chassis, subscriber_gps, subscriber_vehicle);  
    sync.registerCallback(boost::bind(&multi_callback, _1, _2, _3));

  ros::spin();
  close(sock_fd);
  return 0;
}
