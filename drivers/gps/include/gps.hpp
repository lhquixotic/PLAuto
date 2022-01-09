#ifndef GPS_HPP
#define GPS_HPP

#define GET_BIT(x,bit) ((x & (1 << bit)) >> bit)

#include "std_msgs/String.h"
#include "nmea_msgs/Sentence.h"
#include "nav_msgs/Odometry.h"
#include "common_msgs/GpsInfo.h"
#include <cmath>

#include <sstream>
#include <string>
#include <fstream>
#include <math.h>
#include <stdio.h>

namespace ns_gps {

struct Para{
  std::string protocol_name;
  bool record_to_file;
  std::string filename;
};

class GPS {

 public:
  // Constructor
  GPS(ros::NodeHandle &nh);

  // Getters
  common_msgs::GpsInfo getGpsState();

  // Setters
  void setSerialInfo(nmea_msgs::Sentence msg);
  void setGpsParameters(Para msg);

  // Methods
  void runAlgorithm();
  bool serialInfoFlag = false;

 private:

  ros::NodeHandle &nh_;

  nmea_msgs::Sentence serial_info;
  common_msgs::GpsInfo gps_state;
  Para gps_para;
  std::vector<std::string> gps_buffer;

  void serialInfoParse();
  bool serialInfoCheck(std::string s);

  void parseGPGGA(std::string s);
  void parseGPRMC(std::string s);
  void parseGPCHC(std::string s);

  double deg2rad (double deg);
  double safe_double(const std::string& s);
  int safe_int(const std::string& s);
  std::string &trim(std::string &s, std::string e); // clear the string e in string s
  void write2File(std::string filename);
};
}

#endif //GPS_HPP
