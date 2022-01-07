#ifndef SERIAL_COM_HANDLE_HPP
#define SERIAL_COM_HANDLE_HPP

#include "serial_com.hpp"

namespace ns_serial_com {

class SerialComHandle {

 public:
  // Constructor
  SerialComHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();


 private:
  ros::NodeHandle nodeHandle_;
  ros::Publisher serialInfoPublisher_;

  std::string serial_info_topic_name_;

  int node_rate_;

  SerialCom serial_com_;
  Para serial_para_;

};
}

#endif //SERIAL_COM_HANDLE_HPP
