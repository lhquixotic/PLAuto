#include <ros/ros.h>
#include "serial_com.hpp"
#include <sstream>

namespace ns_serial_com {
// Constructor
SerialCom::SerialCom(ros::NodeHandle &nh) : nh_(nh) {

};

// Getters
nmea_msgs::Sentence SerialCom::getSerialInfo(){return sentence;}

// Setters
void SerialCom::setSerialParameters(const Para &msg){
  serial_para = msg;
}

// Methods
void SerialCom::initializeSerial(){
  // Parameters initialization
  serial::Timeout to = serial::Timeout::simpleTimeout(1000);
  sp.setPort(serial_para.port);
  sp.setBaudrate(serial_para.baud);
  sp.setTimeout(to);

  // Check the serial port
  try{
    sp.open();
  }
  catch(serial::IOException &e){
    ROS_WARN_STREAM("Fail to open serial!");
  }

  if(sp.isOpen()){
    ROS_INFO("Serial initialized success!");
  }
  else{
    ROS_WARN("Serial initialization failed, not open!");
  }
}

void SerialCom::runAlgorithm() {
  if(sp.isOpen()){
    // Read serial data
    std::string data;
    data = sp.readline();
    data = trim(data);

    // Decode data
    sentence.sentence = data;
    sentence.header.frame_id = "/drivers/serial_info";
    sentence.header.stamp = ros::Time::now();
  }
  else{
    ROS_WARN_STREAM("Serial not opened.");
    sp.close();
    ROS_WARN_STREAM("Serial is closed.");
  }
}

std::string& SerialCom::trim(std::string &s){
	if (!s.empty()) {
		s = s.erase(0, s.find_first_not_of(" "));
		s = s.erase(s.find_last_not_of(" ") + 1);
	}
	else {
		return s;
	}
	// blank inside string 
	if (!s.empty()) {
		std::string::size_type i = 0;
		while ( (i = s.find(' ')) != std::string::npos ) {
			s.erase(i, 1);
		}
	}
	else {
		return s;
	}
	return s;
}

// TODO:whether add function to shut the port down
}
