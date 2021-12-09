#include <ros/ros.h>
#include "canparse.hpp"
#include <sstream>
namespace ns_canparse {
// Constructor
Canparse::Canparse(ros::NodeHandle &nh) : nh_(nh) {

};

// Getters
common_msgs::ChassisState Canparse::getChassisState(){return chassis_state;}

// Setters
void Canparse::Parse(can_msgs::Frame f) {
  ROS_INFO("frame id: %X",f.id);
  switch (f.id)
  {
  case 0x650:
    id_0x00000650.Update(f.data.c_array() );
    ROS_INFO("650Message: uwbDis: %f ; uwbFW %f ; uwbSta %f ; uwbZT %f ;", 
        id_0x00000650.uwbDis(), id_0x00000650.uwbFW(), id_0x00000650.uwbSta(),id_0x00000650.uwbZT());
    break;

  case 0x5A:
    id_0x0000005A.Update(f.data.c_array());
    ROS_INFO("5AMessage:flwPitchRt: %f ; flwYawRt: %f;",
        id_0x0000005A.flwPitchRt(),id_0x0000005A.flwYawRt());
    break;

  case  0x18F01D48:
    id_0x18F01D48.Update(f.data.c_array());
    ROS_INFO("18F01D48Message:flwSteeringWheelAngel:%f;flwWheelSpd:%f;flwstdinfo:%f;SensorFailureSignal(0:vaild 1:invaild):%f;VoltageWarningSignal(0:nowarning 1:warning<=6v 2:warning>=16v 3:invaild):%f;CornerSpeedSymbol(0:plus 1:minus):%f;SASCalibrationStatus(0:notcalibrated 1:calibrated):%f;CornerSpeedSignal(0:invaild 1:vaild):%f;SteeringAngelSignal(0:invaild 1:vaild):%f;",
        id_0x18F01D48.flwSteeringWheelAngel(),id_0x18F01D48.flwWheelSpd(),id_0x18F01D48.flwstdinfo(),id_0x18F01D48.stateinfo1(),id_0x18F01D48.stateinfo23(),
        id_0x18F01D48.stateinfo4(),id_0x18F01D48.stateinfo5(),id_0x18F01D48.stateinfo6(),id_0x18F01D48.stateinfo7());
    break;

  case 0x18F02501:
    id_0x18F02501.Update(f.data.c_array());
    ROS_INFO("18F02501Message:flwAcc:%f;flwBrkPress:%f;flwPedBrk:%f;flwSpd:%f;",
        id_0x18F02501.flwAcc(),id_0x18F02501.flwBrkPress(),id_0x18F02501.flwPedBrk(),id_0x18F02501.flwSpd());
    break;

  case 0x18F02502:
    id_0x18F02502.Update(f.data.c_array() );
    ROS_INFO("18F02502Message:flwPdlAcc:%f ; flwPedBrk: %f ;",
    id_0x18F02502.flwPdlAcc(),id_0x18F02502.flwPedBrk());
    break;

  case 0x18F02505:
    id_0x18F02505.Update(f.data.c_array() );
    ROS_INFO("18F02505Message:flwPdlAccfreq: %f ; flwPdlAccobj: %f ;flwPedBrkfreq: %f ; flwPedBrkobj: %f ;",
    id_0x18F02505.flwPdlAccfreq(),id_0x18F02505.flwPdlAccobj(),id_0x18F02505.flwPedBrkfreq(),id_0x18F02505.flwPedBrkobj());
    break;

  case 0x18FF4BD1:
    id_0x18FF4BD1.Update(f.data.c_array() );
    ROS_INFO("18FF4BD1Message:flwStrAgl: %f ; flwStrErrCls: %f ;flwStrErrCod: %f ;",
    id_0x18FF4BD1.flwStrAgl(),id_0x18FF4BD1.flwStrErrCls(),id_0x18FF4BD1.flwStrErrCod());
    break;

  case 0x59:
    id_0x00000059.Update(f.data.c_array() );
    ROS_INFO("59Message: flwLonAcc: %f ; flwRollRt: %f ; flwTranAcc: %f ; flwVerAcc: %f ; ",
    id_0x00000059.flwLonAcc(),id_0x00000059.flwRollRt(),id_0x00000059.flwTranAcc(),id_0x00000059.flwVerAcc());
    break;

  case  0x151:
    id_0x00000151.Update(f.data.c_array() );
    ROS_INFO("151Message:FootControlSysInfo(0:justCompleteThePowerOn 1:SelfLearning 2:readyState 3:BrakeState 4:AccState 5:StopState):%f ;",
    id_0x00000151.FootControlSysInfo() );
    break;

  default:
    break;
  }
}

void Canparse::runAlgorithm() {
  chassis_state.header.frame_id = "base_link";
  chassis_state.header.stamp = ros::Time::now();
  //id_0x18F02501.UpdateflwSpd();
  chassis_state.vehicle_speed = id_0x18F02501.flwSpd();
}

}
