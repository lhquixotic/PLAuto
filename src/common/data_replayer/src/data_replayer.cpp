#include <ros/ros.h>
#include "data_replayer.hpp"
#include <sstream>

namespace ns_data_replayer {
// Constructor
DataReplayer::DataReplayer(ros::NodeHandle &nh) : nh_(nh) {
  line_num = -1;
  dis = 0;
  send_frame_id = 0;
  begin_time = 0;
  replay_percent = 1;
};

// Getters
common_msgs::VirtualVehicleState DataReplayer::getVirtualVehicleState() { 

    // Print replay rate
    if (replay_percent == floor(10.0 * send_frame_id / line_num)){
    std::string s = "[=";
    for (int i = 0; i < 10; i++){
      if( i < replay_percent){
        if( i == replay_percent - 1){
          s =  s + ">";
        }
        else{
          s = s + "=";
        }
      }
      else{
        s = s + "*";
      }
    }
    s = s + "]";
    ROS_INFO_STREAM("[Data Replayer] Replay rate: " << s << " " << 100.0 * send_frame_id/line_num << "%%.");
    replay_percent += 1;
  }

  // Return virtual vehicle state 
  virtual_vehicle_state.header.stamp = ros::Time::now();
  if(send_frame_id == virtual_vehicle_state_logger.size() - 1){
    ROS_WARN("Data replay end.");
    return virtual_vehicle_state;
  }
  virtual_vehicle_state = virtual_vehicle_state_logger[send_frame_id];
  if (send_frame_id == 0){
    begin_time = virtual_vehicle_state.header.stamp.toSec();
  }
  double run_duration = ros::Time::now().toSec() - begin_time;
  send_frame_id += 1;

  return virtual_vehicle_state; 
}

// Setters
void DataReplayer::setParameters(Para msg) {
  para = msg;
}


// Methods
void DataReplayer::loadLogFile(std::string filename){
  log_file.open(filename.c_str(),std::ios::in);
  ROS_INFO("open file [%s]",filename.c_str());
  char linestr[500] = {0};
  log_file.getline(linestr, 500);
  /*
       0- 4: frame,time,x,y,heading,
       5- 9: v_x,v_y,yaw_rate,steer_angle,pedal_acc,
      10-11: pedal_brake,lon_acc
  */
  while (log_file.getline(linestr, 500)){
    line_num += 1;
    if (line_num == 0){
        continue;
    }
    std::stringstream ss(linestr);
    std::string csvdata[12];
    for (int i = 0; i < 8; i++) {
        char tempdata[500] = {0};
        ss.getline(tempdata, 500, ',');
        csvdata[i] = std::string(tempdata);
    }   
    double x,y,heading,v_x,v_y,yaw_rate,steer_angle,pedal_acc,pedal_brake,lon_acc;
    x = atof(csvdata[2].data());
    y = atof(csvdata[3].data());
    heading = atof(csvdata[4].data());
    v_x = atof(csvdata[5].data());
    v_y = atof(csvdata[6].data());
    yaw_rate = atof(csvdata[7].data());
    steer_angle = atof(csvdata[8].data());
    pedal_acc = atof(csvdata[9].data());
    pedal_brake = atof(csvdata[10].data());
    lon_acc = atof(csvdata[11].data());

    geometry_msgs::Point p;
    p.x = x;
    p.y = y;
    p.z = 0;
    if (dis == 0 && !dis_flag){
      dis_flag = true;
    }else{
      dis += getPlaneDistance(p,last_loc);
    }
    last_loc = p;

    geometry_msgs::Twist t;
    t.linear.x = v_x;
    t.linear.y = v_y;
    t.angular.z = yaw_rate;

    common_msgs::VirtualVehicleState s;
    s.utmpose.pose.pose.position = p;
    s.utmpose.twist.twist = t;
    
    common_msgs::ChassisState c;
    c.real_steer_angle = steer_angle;
    c.real_acc_pedal = pedal_acc;
    c.real_brake_pedal = pedal_brake;

    s.chassis_state = c;

    s.distance = dis + para.init_distance;

    virtual_vehicle_state_logger.push_back(s);
  }
  log_file.close();
  ROS_INFO("Total frame number of the data: %d.",line_num);
}

void DataReplayer::runAlgorithm() {

}

}
