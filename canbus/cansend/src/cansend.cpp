#include <ros/ros.h>
#include "cansend.hpp"
#include <sstream>

Steer_Cmd_Msg *steer_cmd_msg;
Body_Cmd_Msg *body_cmd_msg;
Brake_Cmd_Msg *brake_cmd_msg;
Park_Cmd_Msg *park_cmd_msg;
Throt_Cmd_Msg *throt_cmd_msg;


namespace ns_cansend {
// Constructor
Cansend::Cansend(ros::NodeHandle &nh) : nh_(nh) {

  steer_cmd_msg = new Steer_Cmd_Msg();
  steer_cmd_msg -> Setsteer_control_mode(0);
  steer_cmd_msg -> Settarget_steer_angle_value(0);
  steer_cmd_msg -> Setrolling_counter(0);
  steer_cmd_msg -> Setcontrol_active(0);
  steer_cmd_msg -> Setchecksum(0);
  steer_cmd_msg -> Settarget_steer_curvature(0);

  body_cmd_msg = new Body_Cmd_Msg();
  body_cmd_msg -> Setbackup_light_enable(0);
  body_cmd_msg -> Setbuzzer_enable(0);
  body_cmd_msg -> Setchecksum(0);
  body_cmd_msg -> Setcontrol_active(0);
  body_cmd_msg ->Setdaytime_lights_enable(0);
  body_cmd_msg -> Sethazard_enable(0);
  body_cmd_msg -> Setheadlight_enable(0);
  body_cmd_msg -> Setklaxon_enable(0);
  body_cmd_msg -> Setrolling_counter(0);
  body_cmd_msg -> Setturnlight_left_enable(0);
  body_cmd_msg -> Setturnlight_right_enable(0);

  brake_cmd_msg = new Brake_Cmd_Msg();
  brake_cmd_msg -> Setbrk_control_mode(0);
  brake_cmd_msg -> Setchecksum(0);
  brake_cmd_msg -> Setcontrol_active(0);
  brake_cmd_msg -> Setrolling_counter(0);
  brake_cmd_msg ->Settarget_brk_pedal_pos(0);
  brake_cmd_msg -> Settarget_brk_pressure(0);

  park_cmd_msg = new Park_Cmd_Msg();
  park_cmd_msg -> Setchecksum(0);
  park_cmd_msg -> Setcontrol_active(0);
  park_cmd_msg -> Setpark_control_enable(0);
  park_cmd_msg -> Setrolling_counter(0);

  throt_cmd_msg = new Throt_Cmd_Msg();
  throt_cmd_msg ->Setchecksum(0);
  throt_cmd_msg ->Setcontrol_active(0);
  throt_cmd_msg -> Setrolling_counter(0);
  throt_cmd_msg -> Settarget_gear(0);
  throt_cmd_msg -> Settarget_throttle(0);
  throt_cmd_msg -> Settarget_vehicle_speed(0);
  throt_cmd_msg -> Setthrot_control_mode(0);
  throt_cmd_msg -> Setvehicle_speed_max(0);

  rolling_counter = 0;
  send_count = 0;
};

Cansend::~Cansend(){
  delete steer_cmd_msg;
  delete body_cmd_msg;
  delete brake_cmd_msg;
  delete park_cmd_msg;
  delete throt_cmd_msg;
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
  sendframes.frames.push_back(getFrame(body_cmd_msg));
  sendframes.frames.push_back(getFrame(brake_cmd_msg));
  sendframes.frames.push_back(getFrame(park_cmd_msg));
  sendframes.frames.push_back(getFrame(throt_cmd_msg));
  return sendframes;
}


void Cansend::runAlgorithm() {

  // Set rolling counter
  if (rolling_counter >= 16){
    rolling_counter = 0;
  }
  rolling_counter = rolling_counter + 1;
  steer_cmd_msg -> Setrolling_counter(rolling_counter);
  body_cmd_msg -> Setrolling_counter(rolling_counter);
  brake_cmd_msg -> Setrolling_counter(rolling_counter);
  park_cmd_msg -> Setrolling_counter(rolling_counter);
  throt_cmd_msg -> Setrolling_counter(rolling_counter);

  // Activiate autonomous driving mode
  send_count += 1;
  if (send_count > 500){
    steer_cmd_msg -> Setcontrol_active(1);
    body_cmd_msg -> Setcontrol_active(1);
    brake_cmd_msg -> Setcontrol_active(1);
    park_cmd_msg -> Setcontrol_active(1);
    throt_cmd_msg -> Setcontrol_active(1);
  }

  // Refresh control value
  steer_cmd_msg -> Settarget_steer_angle_value(10);

  // Set checksum
  steer_cmd_msg -> Setchecksum(0);
  body_cmd_msg -> Setchecksum(0);
  brake_cmd_msg -> Setchecksum(0);
  park_cmd_msg -> Setchecksum(0);
  throt_cmd_msg -> Setchecksum(0);
}

}
