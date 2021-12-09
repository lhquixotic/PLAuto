#include <ros/ros.h>
#include "cansend.hpp"
#include <sstream>
ID_0x04EF8480 *id_0x04EF8480;
ID_0x0C040B2A *id_0x0C040B2A;
Steer_Cmd_Msg *steer_cmd_msg;

namespace ns_cansend {
// Constructor
Cansend::Cansend(ros::NodeHandle &nh) : nh_(nh) {
  id_0x04EF8480=new ID_0x04EF8480();
  id_0x04EF8480->SetconDegCmd(0.0);
  id_0x04EF8480->SetcomControlCmd(0.0);
  id_0x04EF8480->SetconRtCmd(0.0);

  id_0x0C040B2A=new ID_0x0C040B2A();
  id_0x0C040B2A->SetconAccReq(0.0);
  id_0x0C040B2A->SetconSta(0.0);
  id_0x0C040B2A->SetcontrolScheme(0.0);

  steer_cmd_msg = new Steer_Cmd_Msg();
  steer_cmd_msg -> Setsteer_control_mode(0);
  steer_cmd_msg -> Settarget_steer_angle_value(0);
  steer_cmd_msg -> Setrolling_counter(1);
  rolling_counter = 0;
};

Cansend::~Cansend(){
  delete id_0x04EF8480;
  delete id_0x0C040B2A;
  delete steer_cmd_msg;
}

// Getters
can_msgs::Frame Cansend::getFrame(protocol *frame) {
  can_msgs::Frame sendframe;
  sendframe.id = frame->id();
  sendframe.dlc = frame->dlc();
  sendframe.is_extended = frame->is_extended();
  sendframe.is_rtr = frame->is_rtr();
  frame->Update(sendframe.data.c_array());  
  return sendframe;
}
can_msgs::Frames Cansend::getFrames(){
  can_msgs::Frames sendframes;
  sendframes.frames.push_back(getFrame(steer_cmd_msg));
  sendframes.frames.push_back(getFrame(id_0x04EF8480));
  // sendframes.frames.push_back(getFrame(id_0x0C040B2A));
  return sendframes;
}

// Setters
// void Cansend::setChassisControl(common_msgs::ChassisControl msg) {
//   chassis_control_cmd = msg;
// }

void Cansend::runAlgorithm() {
  if (rolling_counter >= 16){
    rolling_counter = 0;
  }
 
  rolling_counter = rolling_counter + 1;

  steer_cmd_msg ->Setchecksum(rolling_counter);
  steer_cmd_msg -> Settarget_steer_angle_value(rolling_counter);
  // id_0x04EF8480->SetconDegCmd(chassis_control_cmd.steer_angle);
  // id_0x04EF8480->SetcomControlCmd(chassis_control_cmd.steer_enable);
  // //id_0x04EF8480->SetcomControlCmd(1.0);
  // id_0x04EF8480->SetconRtCmd(chassis_control_cmd.steer_angle_velocity);

  // id_0x0C040B2A->SetconAccReq(chassis_control_cmd.acc_request);
  // id_0x0C040B2A->SetconSta(chassis_control_cmd.acc_loop_number);
  // //id_0x0C040B2A->SetcontrolScheme(chassis_control_cmd.acc_control_mode);
  // id_0x0C040B2A->SetcontrolScheme(1.0);
  // id_0x0C040B2A->SetAccPedOpenReq(chassis_control_cmd.acc_pedal_open_request);
  // //id_0x0C040B2A->SetBrkPedOpenReq(chassis_control_cmd.brk_pedal_open_request);
  // id_0x0C040B2A->SetBrkPedOpenReq(0);
}

}
