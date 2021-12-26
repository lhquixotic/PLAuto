#ifndef CANSEND_HPP
#define CANSEND_HPP

#include "std_msgs/String.h"
#include "can_msgs/Frame.h"
#include "can_msgs/Frames.h"
#include "autoware_msgs/ControlCommand.h"
#include "common_msgs/ChassisStatus.h"

#include "ADCU_BodyCmd.h"
#include "ADCU_BrakeCmd.h"
#include "ADCU_DriveCmd0.h"
#include "ADCU_ParkCmd.h"
#include "ADCU_PowerCmd.h"
#include "ADCU_SteerCmd.h"

extern ADCU_SteerCmd * steer_cmd;
extern ADCU_BodyCmd * body_cmd;
extern ADCU_BrakeCmd * brake_cmd;
extern ADCU_ParkCmd * park_cmd;
extern  ADCU_DriveCmd0 * throt_cmd;
extern ADCU_PowerCmd * power_cmd;

namespace ns_cansend {
struct Para{
  int send_mode;
  double steer_angle;
  double steer_scale;
  double drive_target_speed;
  double drive_target_gear;
  double drive_limit_speed;
};

class Cansend {

 public:
  // Constructor
  Cansend(ros::NodeHandle &nh);
  ~Cansend();

  // Getters
  can_msgs::Frame getFrame(protocol *frame);
  can_msgs::Frames getFrames();  


  // Setters
  void setParameters(const Para &msg);
  void setControlCmd(const autoware_msgs::ControlCommand &msg);
  void setChassisStatus(const common_msgs::ChassisStatus & msg);

  // Methods
  void runAlgorithm();

 private:

  ros::NodeHandle &nh_;
  int rolling_counter;
  int send_count;

  Para para;
  autoware_msgs::ControlCommand control_cmd;
  common_msgs::ChassisStatus chassis_status;
  int run_mode;
 

  // common_msgs::ChassisControl chassis_control_cmd;

};
}

#endif //CANSEND_HPP
