#include "ros/ros.h"
#include "beginner_tutorials/V2V.h"
#include "std_msgs/String.h"
#include "std_msgs/Header.h"
#include "sensor_msgs/NavSatFix.h"
#include "geometry_msgs/Vector3.h"
#include <sstream>

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <vector>


#define DEST_PORT 11255
#define DSET_IP_ADDRESS  "192.168.20.224"

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

int main(int argc, char** argv) {
  ros::init(argc, argv, "V2VListener");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("/V2VData", 1000);
  ros::Rate loop_rate(10);
  int count = 0;

  int sock_fd;

  /* 建立udp socket */
  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }

  /* 设置address */
  struct sockaddr_in addr_serv;
  int len;
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
  
  while(ros::ok()) {
        beginner_tutorials::V2V v2v_msg;
	std_msgs::String msg;
        std_msgs::Header header_msg;
        sensor_msgs::NavSatFix nav_msg;
        geometry_msgs::Vector3 vector_msg;
 	std::stringstream ss;

        int recv_num;
	char recv_buf[4096];

	recv_num = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_serv, (socklen_t *)&len);

	if(recv_num < 0)
	{
	  perror("recvfrom error:");
	  exit(1);
        }

	recv_buf[recv_num] = '\0';
	printf("client receive %d bytes: %s\n", recv_num, recv_buf);
        std::string sstr = recv_buf;
        
        std::vector<std::string> stringvector = split(sstr, ' ');

        header_msg.frame_id = "frame";
        header_msg.stamp = ros::Time::now();
        
        nav_msg.latitude = std::atof(stringvector[0].c_str());
        nav_msg.longitude = std::atof(stringvector[1].c_str());
        nav_msg.altitude = std::atof(stringvector[2].c_str());

        vector_msg.x = std::atof(stringvector[3].c_str());
        vector_msg.y = std::atof(stringvector[4].c_str());
        vector_msg.z = std::atof(stringvector[5].c_str());

        v2v_msg.header = header_msg;
        v2v_msg.fix = nav_msg;
        v2v_msg.rpy = vector_msg;
        v2v_msg.leader_speed = std::atof(stringvector[6].c_str());
        v2v_msg.leader_acc = std::atof(stringvector[7].c_str());
        v2v_msg.leader_acc_pedal = std::atof(stringvector[8].c_str());
        v2v_msg.leader_brake_pedal = std::atof(stringvector[9].c_str());
        v2v_msg.leader_frontwheel_angle = std::atof(stringvector[10].c_str());
        
	msg.data = sstr;
	ROS_INFO("%s", msg.data.c_str());
	chatter_pub.publish(v2v_msg);
	ros::spinOnce();
	loop_rate.sleep();
  }
  close(sock_fd);
  return 0;
}
