#ifndef SERIAL_COM_HPP
#define SERIAL_COM_HPP

#include "std_msgs/String.h"
#include "nmea_msgs/Sentence.h"
#include "serial/serial.h"

namespace ns_serial_com {

struct Para{
  int baud;
  std::string port;
};

class SerialCom {

 public:
  // Constructor
  SerialCom(ros::NodeHandle &nh);

  // Getters
  nmea_msgs::Sentence getSerialInfo();

  // Setters
  void setSerialParameters(const Para &msg);

  // Methods
  void runAlgorithm();
  void initializeSerial();

 private:

  ros::NodeHandle &nh_;
  Para serial_para;
  serial::Serial sp;
  nmea_msgs::Sentence sentence;
  std::string &trim(std::string &s);
};
}

#endif //SERIAL_COM_HPP
