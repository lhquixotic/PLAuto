#include <ros/ros.h>
#include "data_logger.hpp"
#include <sstream>

namespace ns_data_logger {
// Constructor
DataLogger::DataLogger(ros::NodeHandle &nh) : nh_(nh) {

};

// Setters
void DataLogger::setLocalization(nav_msgs::Odometry msg) {
  cur_pose = msg;
}

void DataLogger::setChassisState(common_msgs::ChassisState msg){
  chassis_state = msg;
}

void DataLogger::setControlCommand(common_msgs::ChassisControl msg){
  control_cmd = msg;
}

void DataLogger::setParameters(Para msg){
  para = msg;
}

void DataLogger::openRecordFile(){
  record_file.open(para.log_filename, std::ios::out);
  std::string header;
  // if(para.record_mode == 0){
  //   // record for path tracking
  //   header = "frame,time,x,y,heading,v_x,v_y,yaw_rate";
  // }
  // else{
  //   header = "frame,time,x,y,heading,v_x,v_y,yaw_rate,a_x,distance,pedal_acc,pedal_brake";
  // }
  header = "frame,time,x,y,heading,v_x,v_y,yaw_rate,steer_angle,pedal_acc,pedal_brake,lon_acc";
  record_file << header << std::endl;
  frame = 0;
  begin_time = ros::Time::now().toSec();
  last_time = begin_time;
  ROS_INFO("[Data Logger] Record file created, begin_time: %f.",begin_time);
  open_file_flag = true;
}

void DataLogger::write2File() {
  using namespace std;  

  string frame_s = to_string(frame);
  ros::Time timestamp = cur_pose.header.stamp;
  string time = to_string(timestamp.toSec());
  string x = to_string(cur_pose.pose.pose.position.x);
  string y = to_string(cur_pose.pose.pose.position.y);
  
  tf::Quaternion quat;
  tf::quaternionMsgToTF(cur_pose.pose.pose.orientation, quat);
  double roll, pitch, yaw;
  tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);

  string heading = to_string(yaw);
  string v_x = to_string(cur_pose.twist.twist.linear.x);
  string v_y = to_string(cur_pose.twist.twist.linear.y);
  string yaw_rate = to_string(cur_pose.twist.twist.angular.z);

  string steer_angle = to_string(chassis_state.real_steer_angle);
  string pedal_acc = to_string(chassis_state.real_acc_pedal);
  string pedal_brake = to_string(chassis_state.real_brake_pedal);
  string lon_acc  = to_string(chassis_state.vehicle_lon_acceleration);
  
  // if (para.record_mode == 0){// record for path tracking 
  record_file << frame_s + "," + time + "," + x + "," + y + "," 
        + heading + "," + v_x  + "," + v_y  + "," + yaw_rate + ","
        + steer_angle + "," + pedal_acc + "," + pedal_brake + ","
        + lon_acc << endl;
  // }
  // else{ // record for virtual platoon test
  //   record_file << frame + "," + time + "," + x + "," + y + "," 
  //     + heading + "," + v_x  + "," + v_y  + "," + yaw_rate << endl;
  // }
  frame += 1;
  if (frame%50 == 0){
    double T = ros::Time::now().toSec() - last_time;
    double duration = ros::Time::now().toSec() - begin_time;
    ROS_INFO("[Data Logger] Record frame number: %d, spent time: %f, frequence: %f.", frame, duration, 50.0/T);
    last_time = ros::Time::now().toSec();
  }
  }

void DataLogger::runAlgorithm() {
  if (!open_file_flag){
      openRecordFile();
  }
  else{  
      write2File();
  }
}

}
