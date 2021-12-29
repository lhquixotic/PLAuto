#ifndef OBU_SEND_HANDLE_HPP
#define OBU_SEND_HANDLE_HPP

#include "obu_send.hpp"

extern int SockFd;
extern struct sockaddr_in AddrServ;
extern int Len;

namespace ns_obu_send {

void multiCallback(const common_msgs::ChassisStatus::ConstPtr& chassis, 
  const common_msgs::GpsInfo::ConstPtr& gpsinfo, 
  const common_msgs::VehicleDynamicState::ConstPtr& vehicle);

class ObuSendHandle {

 public:
  // Constructor
  ObuSendHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;

  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();

  int sock_fd_;
  int len_;
  struct sockaddr_in addr_serv_; 

  std::string chassis_status_topic_name_;
  std::string gps_info_topic_name_;
  std::string vehicle_dynamic_state_topic_name_;

  // ros::Subscriber chassisStatusSubscriber_;
  // ros::Subscriber vehicleDynamicStateSubscriber_;
  // ros::Subscriber gpsInfoSubscriber_;

 private:
  ros::NodeHandle nodeHandle_;

  int node_rate_;

  ObuSend obu_send_;

};
}

#endif //OBU_SEND_HANDLE_HPP
