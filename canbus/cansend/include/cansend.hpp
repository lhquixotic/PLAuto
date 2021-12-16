#ifndef CANSEND_HPP
#define CANSEND_HPP

#include "std_msgs/String.h"
#include "can_msgs/Frame.h"
#include "can_msgs/Frames.h"

#include "Steer_Cmd_Msg.h"
#include "Body_Cmd_Msg.h"
#include "Brake_Cmd_Msg.h"
#include "Park_Cmd_Msg.h"
#include "Throt_Cmd_Msg.h"

extern Steer_Cmd_Msg * steer_cmd_msg;
extern Body_Cmd_Msg * body_cmd_msg;
extern Brake_Cmd_Msg * brake_cmd_msg;
extern Park_Cmd_Msg * park_cmd_msg;
extern Throt_Cmd_Msg * throt_cmd_msg;

namespace ns_cansend {

class Cansend {

 public:
  // Constructor
  Cansend(ros::NodeHandle &nh);
  ~Cansend();

  // Getters
  can_msgs::Frame getFrame(protocol *frame);
  can_msgs::Frames getFrames();  
  // Setters
  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;
  double rolling_counter;
  int send_count;
 

  // common_msgs::ChassisControl chassis_control_cmd;

};
}

#endif //CANSEND_HPP
