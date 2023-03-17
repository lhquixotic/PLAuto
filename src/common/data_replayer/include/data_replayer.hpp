#ifndef DATA_REPLAYER_HPP
#define DATA_REPLAYER_HPP

#include "common_msgs/VirtualVehicleState.h"
#include "common_msgs/Trigger.h"
#include "common_msgs/VirtualVehicleState.h"
#include "std_msgs/String.h"
#include <libwaypoint_follower/libwaypoint_follower.h>

namespace ns_data_replayer {
struct Para{
  std::string log_filename;
  double init_distance;
};
class DataReplayer {
  

 public:
  // Constructor
  DataReplayer(ros::NodeHandle &nh);

  // Getters
  common_msgs::VirtualVehicleState getVirtualVehicleState(); 

  // Setters
  void setParameters(Para msg);

  //Methods
  void runAlgorithm();
  void loadLogFile(std::string filename); 

 private:

  ros::NodeHandle &nh_;

  common_msgs::VirtualVehicleState virtual_vehicle_state;

  Para para;

  std::fstream log_file;
  int line_num;
  int send_frame_id;
  int replay_percent;

  geometry_msgs::Point last_loc;
  double dis;
  bool dis_flag;
  double begin_time;


  std::vector<common_msgs::VirtualVehicleState> virtual_vehicle_state_logger;
};
}

#endif //DATA_REPLAYER_HPP
