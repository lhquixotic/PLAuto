#ifndef OBU_RECV_HPP
#define OBU_RECV_HPP

#include "common_msgs/V2V.h"
#include "std_msgs/String.h"
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

namespace ns_obu_recv {

  static void _split(const std::string& s, 
                    char delim,
                    std::vector<std::string>& elems);
  std::vector<std::string> split(const std::string &s, char delim);

class ObuRecv {

 public:
  // Constructor
  ObuRecv(ros::NodeHandle &nh);

  // Getters
  common_msgs::V2V getV2VInfo();
  int getSockfd();
   
  void runAlgorithm();

  void socketComSetup();


 private:
  
  struct sockaddr_in addr_serv;
  int len;
  int sock_fd;

  ros::NodeHandle &nh_;

  common_msgs::V2V v2v_info;

};
}

#endif //OBU_RECV_HPP
