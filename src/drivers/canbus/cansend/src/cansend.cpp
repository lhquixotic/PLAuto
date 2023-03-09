#include <ros/ros.h>
#include "cansend.hpp"
#include <sstream>

ADCU_SteerCmd * steer_cmd;
ADCU_BodyCmd * body_cmd;
ADCU_BrakeCmd * brake_cmd;
ADCU_ParkCmd * park_cmd;
ADCU_DriveCmd0 * throt_cmd;
ADCU_PowerCmd * power_cmd;


namespace ns_cansend {
// Constructor
Cansend::Cansend(ros::NodeHandle &nh) : nh_(nh) {
  steer_cmd = new ADCU_SteerCmd();
  steer_cmd -> SetADCU_StrCmd_RollCnt(0);
  steer_cmd -> SetADCU_Str_Active(0);
  steer_cmd -> SetADCU_Str_CtrlMode(0);
  steer_cmd -> SetADCU_Str_TgtAngle(0);
  steer_cmd -> SetADCU_Str_TgtAngleSpd(0);
  steer_cmd -> SetADCU_Str_TgtCurvature(0);
  steer_cmd -> SetADCU_StrCmd_Checksum(0);

  body_cmd = new ADCU_BodyCmd();
  body_cmd -> SetADCU_BackLamp_Cmd(0);
  body_cmd -> SetADCU_BrkLamp_Cmd(0);
  body_cmd -> SetADCU_Buzzer_Cmd(0);
  body_cmd -> SetADCU_DblFlashLamp_Cmd(0);
  body_cmd -> SetADCU_FogLamp_Cmd(0);
  body_cmd -> SetADCU_HeadLamp_Cmd(0);
  body_cmd -> SetADCU_Horn_Cmd(0);
  body_cmd -> SetADCU_LampCmd_Active(0);
  body_cmd -> SetADCU_LampCmd_RollCnt(0);
  body_cmd -> SetADCU_RunLamp_Cmd(0);
  body_cmd -> SetADCU_TurnLLamp_Cmd(0);
  body_cmd -> SetADCU_TurnRLamp_Cmd(0);
  body_cmd -> SetADCU_WidthLamp_Cmd(0);  
  body_cmd -> SetADCU_LampCmd_Checksum(0);

  brake_cmd = new ADCU_BrakeCmd();
  brake_cmd -> SetADCU_BrkCmd_RollCnt(0);
  brake_cmd -> SetADCU_Brk_Active(0);
  brake_cmd -> SetADCU_Brk_CtrlMode(0);
  brake_cmd -> SetADCU_Brk_TgtAccSpd(0);
  brake_cmd -> SetADCU_Brk_TgtPedpos(0);
  brake_cmd -> SetADCU_Brk_TgtPress(0);
  brake_cmd -> SetADCU_BrkCmd_Checksum(0);

  park_cmd = new ADCU_ParkCmd();
  park_cmd -> SetADCU_PrkCmd_RollCnt(0);
  park_cmd -> SetADCU_Prk_Active(0);
  park_cmd -> SetADCU_Prk_Enable(0);
  park_cmd -> SetADCU_PrkCmd_Checksum(0);

  throt_cmd = new ADCU_DriveCmd0();
  throt_cmd -> SetADCU_DrvCmd_RollCnt(0);
  throt_cmd -> SetADCU_Drv_Active(0);
  throt_cmd -> SetADCU_Drv_CtrlMode(0);
  throt_cmd -> SetADCU_Drv_TgtGear(0);
  throt_cmd -> SetADCU_Drv_TgtPedpos(0);
  throt_cmd -> SetADCU_Drv_TgtVehAccSpd(0);
  throt_cmd -> SetADCU_Drv_TgtVehSpd0(0);
  throt_cmd -> SetADCU_Drv_VehSpdLimit(0);
  throt_cmd -> SetADCU_DrvCmd_Checksum(0);

  power_cmd = new ADCU_PowerCmd();
  power_cmd -> SetADCU_PwrCmd_RollCnt(0);
  power_cmd -> SetADCU_PwrCmd_Checksum(0);

  rolling_counter = 0;
  send_count = 0;
};

Cansend::~Cansend(){
  delete steer_cmd;
  delete body_cmd;
  delete brake_cmd;
  delete park_cmd;
  delete throt_cmd;
  delete power_cmd;
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
  sendframes.frames.push_back(getFrame(steer_cmd));
  sendframes.frames.push_back(getFrame(body_cmd));
  sendframes.frames.push_back(getFrame(brake_cmd));
  sendframes.frames.push_back(getFrame(park_cmd));
  sendframes.frames.push_back(getFrame(throt_cmd));
  sendframes.frames.push_back(getFrame(power_cmd));
  return sendframes;
}

void Cansend::setParameters(const Para & msg){
  para  = msg;
}

void Cansend::setControlCmd(const autoware_msgs::ControlCommandStamped & msg){
  control_cmd = msg;
}
void Cansend::setChassisStatus(const common_msgs::ChassisStatus & msg){
  chassis_status = msg;
  run_mode = chassis_status.vehicle_run_mode;
}

void Cansend::runAlgorithm() {
  if (run_mode == 0){// Standby mode
    // Activiate automatic mode 
    if (send_count > 200){
      steer_cmd -> SetADCU_Str_Active(1);
      body_cmd -> SetADCU_LampCmd_Active(1);
      brake_cmd -> SetADCU_Brk_Active(1);
      park_cmd -> SetADCU_Prk_Active(1);
      throt_cmd -> SetADCU_Drv_Active(1);
    }
  }else if (run_mode == 2){ // remote mode
    // Restore manual control
    steer_cmd -> SetADCU_Str_Active(0);
    body_cmd -> SetADCU_LampCmd_Active(0);
    brake_cmd -> SetADCU_Brk_Active(0);
    park_cmd -> SetADCU_Prk_Active(0);
    throt_cmd -> SetADCU_Drv_Active(0);
    send_count = 0;
  }else if (run_mode == 3){ // automatic mode
    // In automatic mode
    // Refresh control value
    if (para.send_mode == 0){ // send mode
      steer_cmd -> SetADCU_Str_TgtAngle(para.steer_angle);
      throt_cmd -> SetADCU_Drv_TgtVehSpd0(para.drive_target_speed);
    }else{
      steer_cmd -> SetADCU_Str_TgtAngle(control_cmd.cmd.steering_angle);
      throt_cmd ->SetADCU_Drv_TgtVehSpd0(control_cmd.cmd.linear_velocity);
    }
    throt_cmd ->SetADCU_Drv_CtrlMode(1); //speed
    throt_cmd -> SetADCU_Drv_TgtGear(para.drive_target_gear);
    throt_cmd -> SetADCU_Drv_VehSpdLimit(para.drive_limit_speed);
    
    ROS_INFO_STREAM("target_steer_angle: "<<para.steer_angle);
  }else if (run_mode == 4){ // Emergency mode
    // Emergency handling

  }
  
  // Set rolling counter
  if (rolling_counter >= 16){
    rolling_counter = 0;
  }
  rolling_counter = rolling_counter + 1;
  steer_cmd -> SetADCU_StrCmd_RollCnt(rolling_counter);
  body_cmd -> SetADCU_LampCmd_RollCnt(rolling_counter);
  brake_cmd -> SetADCU_BrkCmd_RollCnt(rolling_counter);
  power_cmd -> SetADCU_PwrCmd_RollCnt(rolling_counter);
  park_cmd -> SetADCU_PrkCmd_RollCnt(rolling_counter);
  throt_cmd -> SetADCU_DrvCmd_RollCnt(rolling_counter);
  send_count += 1;  

  // Set checksum
  steer_cmd -> SetADCU_StrCmd_Checksum(0);
  body_cmd -> SetADCU_LampCmd_Checksum(0);
  brake_cmd -> SetADCU_BrkCmd_Checksum(0);
  park_cmd -> SetADCU_PrkCmd_Checksum(0);
  throt_cmd -> SetADCU_DrvCmd_Checksum(0);
  power_cmd -> SetADCU_PwrCmd_Checksum(0);
}

}
