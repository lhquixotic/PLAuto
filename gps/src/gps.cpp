#include <ros/ros.h>
#include "gps.hpp"
#include <sstream>

namespace ns_gps {
// Constructor
GPS::GPS(ros::NodeHandle &nh) : nh_(nh) {

};
// Getters
common_msgs::GpsInfo GPS::getGpsState() {return gps_state;}

// Setters
void GPS::setSerialInfo(nmea_msgs::Sentence msg){
  serial_info = msg;
}
void GPS::setGpsParameters(Para msg){
  gps_para = msg;
}

// Methods
void GPS::runAlgorithm() {
  if (serialInfoFlag){
    serialInfoParse();
  }
  else{
   ROS_WARN("Waiting for serial info...");
  }
}

void GPS::serialInfoParse(){
  // Trim and check the serial data
  std::string s = serial_info.sentence;
  s = trim(s," ");
  s = trim(s,"+");
  
  if (!serialInfoCheck(s)){
    ROS_WARN_STREAM("GPS info check failed!");
  }

  // Parse serial info according to the protocol type
  std::string protocol_recv = s.substr(3,3);
  if (gps_para.protocol_name == "GPGGA"){
      if (!(protocol_recv=="GGA")){
        ROS_WARN_STREAM("Protocol received is "<<protocol_recv);
      } else {
        parseGPGGA(s);
      }
    }
  else{
    if (gps_para.protocol_name == "GPRMC"){
      if (!(protocol_recv=="RMC")){
        ROS_WARN_STREAM("Protocol received is "<<protocol_recv);
      } else {
        parseGPRMC(s);
      }
    }
    else{
      if (gps_para.protocol_name == "GPCHC"){
        if (!(protocol_recv=="CHC")){
          ROS_WARN_STREAM("Protocol received is "<<protocol_recv);
        } else {
          parseGPCHC(s);
        }
      }
      else{
        ROS_WARN_STREAM("Wrong protocol name: " << gps_para.protocol_name << " !");
      }
    }
  }
}

void GPS::parseGPGGA(std::string s){
  //TODO: supplement GPGGA parse
}

void GPS::parseGPRMC(std::string s){
  //TODO: supplement GPRMC parse
}

void GPS::parseGPCHC(std::string s){
  //ROS_INFO("GPCHC parse");
  // header
  gps_state.header.frame_id = "world";
  gps_state.header.stamp = ros::Time::now();
  // fix
  gps_state.fix.latitude  = safe_double(gps_buffer[12]);
  gps_state.fix.longitude = safe_double(gps_buffer[13]);
  gps_state.fix.altitude  = safe_double(gps_buffer[14]);
  // rpy deg
  double roll = safe_double(gps_buffer[5]);
  double pitch = safe_double(gps_buffer[4]);
  double yaw = safe_double(gps_buffer[3]);
  gps_state.rpy.x = roll;
  gps_state.rpy.y = pitch;
  gps_state.rpy.z = yaw;
  // twist m/s
  double east_vel = safe_double(gps_buffer[15]);// east velocity
  double north_vel = safe_double(gps_buffer[16]);// north velocity
  gps_state.twist.linear.x  = east_vel * sin(yaw*M_PI/180.0) + north_vel * cos(yaw*M_PI/180.0); 
  gps_state.twist.linear.y  = east_vel * cos(yaw*M_PI/180.0) - north_vel * sin(yaw*M_PI/180.0); 
  gps_state.twist.linear.z  = safe_double(gps_buffer[17]);
  gps_state.twist.angular.x = safe_double(gps_buffer[6]);
  gps_state.twist.angular.y = safe_double(gps_buffer[7]);
  gps_state.twist.angular.z = safe_double(gps_buffer[8]);
  // acc
  gps_state.acc.x = safe_double(gps_buffer[9]);
  gps_state.acc.y = safe_double(gps_buffer[10]);
  gps_state.acc.z = safe_double(gps_buffer[11]);
  // Warning
  int warning = safe_int(gps_buffer[23]);
  if ((GET_BIT(warning,0))==1){
    // No gps message
    ROS_WARN("No GPS message!");
  }
  if ((GET_BIT(warning,1))==1){
    // No vehicle1 message
    // ROS_WARN("No Vehicle state message!")
  }
  if ((GET_BIT(warning,2))==1){
    // No gyro message
    ROS_WARN("No gyro message!");
  }
  if ((GET_BIT(warning,3))==1){
    // No acc message
    ROS_WARN("No acc message!");
  }
  //ROS_INFO("GPCHC parse end");
}

std::string& GPS::trim(std::string &s, std::string e){
  // delete the string in the front and rear
  if (!s.empty()){
    s = s.erase(0, s.find_first_not_of(e));
    s = s.erase(s.find_last_not_of(e) + 1);
  }
  else{
    return s;
  }
  // delete the string inside of the string
  if (!s.empty()){
    std::string::size_type i = 0;
    while ((i = s.find(e)) != std::string::npos){
      s.erase(i,1);
    }
  }
  else{
    return s;
  }
  return s; 
}

bool GPS::serialInfoCheck(std::string s){
  gps_buffer.clear();

	std::stringstream sstream;
	std::string check_value_str;
	std::string check_sum_str;
	int check_sum = 0;
	std::string ss;
	std::string sp_1 = "*";
	std::string sp_2 = "$";
	std::string sp_3 = ",";
	std::string::size_type pos = 0;
	std::string::size_type pos_1 = s.find(sp_1);
	std::string::size_type pos_2 = s.find(sp_2);
	
  // modify sentence no $ *
	if (pos_1 != std::string::npos) {
		check_value_str = s.substr(pos_1 + 1, 2);
		ss = s.substr(pos_2 + 1, pos_1 - pos_2 - 1);
	}
	else
	{
		ROS_WARN_STREAM("[GPS parse] No * found in sentence data_check()");	
		return false;
	}
	// Check the sum of the serial info
	for (int i = 0; i < ss.size(); i++) {
		check_sum ^= int(ss[i]);
	}
	sstream << std::hex << std::setfill('0') << std::setw(2) << check_sum;
	check_sum_str = sstream.str();
	std::transform(check_sum_str.begin(), check_sum_str.end(), check_sum_str.begin(), ((int(*)(int)) (std::toupper)) );// std::toupper in <cctype> use int(*)(int) form
	if (check_sum_str == check_value_str) {
    s = s + ",";
		// split sentence into a vector
		while ((pos = s.find(',')) != std::string::npos){
      gps_buffer.push_back(s.substr(0, pos));
      s = s.substr(pos + 1);
		}
		return true;
	}
	else
	{
		ROS_WARN_STREAM("[GPS parse] Check wrong");
		return false;
	}
}

int GPS::safe_int(const std::string &s) {
	int result;
	try {
		result = std::stoi(s);
		return result;
	}
	catch (...) {
		result = 0;
		ROS_WARN_STREAM("wrong in stoi() no sentence data");
		return result;
	}

}

double GPS::safe_double(const std::string& s) {
	double result;
	try {
		result = std::stod(s);
		return result;
	}
	catch (...) {
		result = 0;
		ROS_WARN_STREAM("wrong in stod() no sentence data");
		return result;
	}
}

double GPS::deg2rad (double deg) {
    return deg * 3.1415926 / 180.0;
}

}
