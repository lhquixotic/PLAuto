#include <ros/ros.h>
#include "obu_recv.hpp"
#include <sstream>

namespace ns_obu_recv {
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

// Constructor
ObuRecv::ObuRecv(ros::NodeHandle &nh) : nh_(nh) {
  
};

// Getters
common_msgs::V2V ObuRecv::getV2VInfo(){
  return v2v_info;
}
int ObuRecv::getSockfd(){
  return sock_fd;
}

// Setters


// Methods
void ObuRecv::socketComSetup(){
  /* 建立udp socket */
  sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
  ROS_INFO_STREAM("Sock fd: " << sock_fd);
  if(sock_fd < 0)
  {
    perror("socket");
    exit(1);
  }
  /* 设置address */
  memset(&addr_serv, 0, sizeof(addr_serv));
  addr_serv.sin_family = AF_INET;
  addr_serv.sin_addr.s_addr = inet_addr(DSET_IP_ADDRESS);
  addr_serv.sin_port = htons(DEST_PORT);
  len = sizeof(addr_serv);

  // 发送接收数据时数组结尾加\0
  int send_num;
  char send_buf[2] = {'1', '\0'};
  std::string ssss = send_buf;
  ROS_INFO("client send: %s\n", ssss.c_str());
  send_num = sendto(sock_fd, send_buf, strlen(send_buf), 0, (struct sockaddr *)&addr_serv, len);
  if(send_num < 0)
  {
    perror("sendto error:");
    exit(1);
  }else{
    ROS_INFO("Sent success");
  }
}

void ObuRecv::runAlgorithm() {
  int recv_num;
  char recv_buf[4096];
  recv_num = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_serv, (socklen_t *)&len);
  if(recv_num < 0){
    perror("recvfrom error:");
    exit(1);
  }
  recv_buf[recv_num] = '\0';
  printf("client receive %d bytes: %s\n", recv_num, recv_buf);
  std::string sstr = recv_buf;
  std::vector<std::string> stringvector = split(sstr, ' ');
   
  v2v_info.header.frame_id = "frame";
  v2v_info.header.stamp = ros::Time::now();
  
  v2v_info.odom.header.frame_id = "world";
  v2v_info.odom.header.stamp = ros::Time::now();
  v2v_info.odom.pose.pose.position.x = std::atof(stringvector[0].c_str());
  v2v_info.odom.pose.pose.position.y = std::atof(stringvector[1].c_str());
  v2v_info.odom.pose.pose.position.z = 0;
  v2v_info.odom.pose.pose.orientation.x = std::atof(stringvector[2].c_str());
  v2v_info.odom.pose.pose.orientation.y = std::atof(stringvector[3].c_str());
  v2v_info.odom.pose.pose.orientation.z = std::atof(stringvector[4].c_str());
  v2v_info.odom.pose.pose.orientation.w = std::atof(stringvector[5].c_str());

  v2v_info.leader_speed = std::atof(stringvector[6].c_str());
  v2v_info.leader_acc = std::atof(stringvector[7].c_str());
  v2v_info.leader_acc_pedal = std::atof(stringvector[8].c_str());
  v2v_info.leader_brake_pedal = std::atof(stringvector[9].c_str());
  v2v_info.leader_frontwheel_angle = std::atof(stringvector[10].c_str());

  std_msgs::String msg;
  msg.data = sstr;
  ROS_INFO("%s", msg.data.c_str());

}
}
