#ifndef GPS_HANDLE_HPP
#define GPS_HANDLE_HPP


#include "gps.hpp"

namespace ns_gps {

class GPSHandle {

 public:
  // Constructor
  GPSHandle(ros::NodeHandle &nodeHandle);

  // Getters
  int getNodeRate() const;
 
  // Methods
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
  // void sendVisualization();

 private:
  ros::NodeHandle nodeHandle_;
  ros::Subscriber serialInfoSubscriber_;
  ros::Publisher gpsStatePublisher_;

  void serialInfoCallback(const nmea_msgs::Sentence &msg);

  std::string serial_info_topic_name_; 
  std::string gps_state_topic_name_;

  int node_rate_;

  GPS gps_;
  Para gps_para_;

};
}

#endif //GPS_HANDLE_HPP
