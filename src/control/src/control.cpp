#include <ros/ros.h>
#include "control.hpp"
#include <sstream>

namespace ns_control
{
  // Constructor
  Control::Control(ros::NodeHandle &nh) : nh_(nh),
                                          pid_controller(1.0, 0.0, 0.0),
                                          pp_controller(1.20){};

  // Getters
  common_msgs::ControlCommand Control::getControlCommand() { 

    // ccs.header.frame_id = "vehicle";
    // ccs.header.stamp = ros::Time::now();
    control_cmd.header.frame_id = "ego_vehicle";
    control_cmd.header.stamp = ros::Time::now();
    return control_cmd; 
    }
  geometry_msgs::PointStamped Control::getLookaheadPoint() { 
    lookahead_point.header.frame_id = "world";
    lookahead_point.header.stamp = ros::Time::now();
    return lookahead_point; 
  }

  // Setters
  void Control::setFinalWaypoints(const autoware_msgs::Lane &msg){
    final_waypoints = msg;
    current_waypoints = final_waypoints.waypoints;
  }
  void Control::setEgoState(const common_msgs::VehicleState &msg){
    ego_state = msg;
    // ROS_INFO_STREAM("[Control]current velocity: " << vehicle_state.twist.linear.x);
  }
  void Control::setPlatoonState(const common_msgs::PlatoonState &msg){
    platoon_state = msg;
    leader_pose = platoon_state.vehicles[0].odom.pose.pose;
  }
  void Control::setUtmPose(const nav_msgs::Odometry &msg){
    utm_pose = msg; 
    current_pose = utm_pose.pose.pose;
  }

  void Control::setPidParameters(const Pid_para &msg){
    pid_para = msg;
    pid_controller.kp = pid_para.kp;
    pid_controller.ki = pid_para.ki;
    pid_controller.kd = pid_para.kd;
  }
  void Control::setPurePursuitParameters(const Pure_pursuit_para &msg){
    pp_para = msg;
  }
  void Control::setControlParameters(const Para &msg){
    control_para = msg;
  }

  int Control::findLookAheadWaypoint(float lookAheadDistance){
    int waypoints_size = current_waypoints.size();
    if (waypoints_size == 0){
      next_waypoint_number_ = -1;
      return -1;
    }
    // find nearest point
    nearest_idx = 0;
    double nearest_distance = getPlaneDistance(current_waypoints.at(0).pose.pose.position,current_pose.position);
    for (int i = 0; i < waypoints_size; i++){
      // if search waypoint is the last
      if(i == (waypoints_size - 1)){
        ROS_INFO("search waypoint is the last");
        // break;
      }
      double dis = getPlaneDistance(current_waypoints.at(i).pose.pose.position,current_pose.position);
      if (dis < nearest_distance){
        nearest_idx = i;
        nearest_distance = dis;
      }
    }

    // look for the next waypoint
    for (int j = nearest_idx; j < waypoints_size; j++){
      // if search waypoint is the last
      if (j == (waypoints_size - 1)){
        ROS_INFO("search waypoints is the last");
        return j;
      }
      // if there exists an effective waypoint
      if (getPlaneDistance(
        current_waypoints.at(j).pose.pose.position, current_pose.position
      ) > lookAheadDistance){
        lookahead_point.point = current_waypoints.at(j).pose.pose.position;
        return j;
      }
    }
    // float dist_sum = 0;
    // int i;
    // ROS_INFO_STREAM("[Control::findLookAheadWaypoint] local path waypoints size: "<<current_waypoints.waypoints.size());
    // for (i = 1; i < current_waypoints.waypoints.size(); i++){ 
    //   geometry_msgs::Point wp = current_waypoints.waypoints[i].pose.pose.position;      // waypoint position
    //   //geometry_msgs::Point wp_ = current_waypoints.waypoints[i - 1].pose.pose.position; // last waypoint position
    //   //float dist = sqrt((wp.x - wp_.x) * (wp.x - wp_.x) + (wp.y - wp_.y) * (wp.y - wp_.y));
    //   //dist_sum += dist;
    //   dist_sum = sqrt((wp.x*wp.x)+(wp.y*wp.y));
    //   if (dist_sum > lookAheadDistance){
    //     ROS_INFO_STREAM("[Control::findLookAheadWaypoint] dist_sum: " << dist_sum);
    //     return i;
    //   }
    // }
    // ROS_WARN(" Lookahead waypoint is not in the range of local path. ");
    // return i;
  }


  void Control::runAlgorithm(){

    ROS_DEBUG("[Control]In run() ... ");
    if (egoStateFlag && finalWaypointsFlag && utmPoseFlag){
      double v_x = utm_pose.twist.twist.linear.x;
      ROS_DEBUG("[Control] Necessary signals are received...");
      
      // Lateral control
      if (control_para.lateral_control_switch){
        double lookahead_distance;
        if (pp_para.mode == "fixed"){
          lookahead_distance = pp_para.lookahead_distance;
        }else{
          if (pp_para.mode == "variable"){
            lookahead_distance = pp_para.lookahead_distance;
            //TODO: modify the way to calculate lookahead_distance
          }else{
            ROS_ERROR("[Pure Pursuit control] No such mode!");
          }
        }
        
        int lookahead_waypoint_idx = findLookAheadWaypoint(lookahead_distance);
        ROS_INFO_STREAM("[Control] lookahead waypoint idx: " << lookahead_waypoint_idx);
        autoware_msgs::Waypoint lookahead_point = final_waypoints.waypoints[lookahead_waypoint_idx];
        ROS_INFO_STREAM("[Control] lookahead waypoint: x: " << lookahead_point.pose.pose.position.x
                        << ", y: " << lookahead_point.pose.pose.position.y);

        control_cmd.steer = pp_controller.outputSteeringWheelAngle(lookahead_point.pose.pose.position,current_pose);
        ROS_INFO_STREAM("[Contorl] control_cmd steer angle: " << control_cmd.steer);
      }else{
        control_cmd.steer = 0;
        ROS_INFO_STREAM("[Contorl] Lateral control disabled");
      }
     
      // Longitudinal Control
      if (control_para.longitudinal_control_switch){
        if (control_para.longitudinal_mode == 1){// constant speed control
          // torque mode
          // control_cmd.torque = pid_controller.outputSignal(control_para.desired_speed, v_x);
          // speed control mode
          // control_cmd.linear_velocity = control_para.desired_speed;
          // acceleration control mode
          control_cmd.accel = pid_controller.outputSignal(v_x,control_para.desired_speed);
        }
        else{ if (control_para.longitudinal_mode == 3){//keeping desired distance
            if (v2vInfoFlag){
              // speed control mode
              // control_cmd.linear_velocity = platoon_state.vehicles[0].dynamics.lon_speed + pid_controller.outputSignal(control_para.desired_distance,
              //    getPlaneDistance(current_pose.position,leader_pose.position));// feedforward + feedback
              
              // accel control mode
              float current_distance = getPlaneDistance(current_pose.position,leader_pose.position);
              control_cmd.accel = pid_controller.outputSignal(control_para.desired_distance,
                                                              current_distance);
              ROS_INFO_STREAM("[Control] Current ego position is: "<< current_pose.position.x <<","<< current_pose.position.y <<
                              ", leader position is: " << leader_pose.position.x <<","<< leader_pose.position.y <<
                              ", current distance is: " << current_distance);
            }else{ ROS_WARN("NO V2V info!");}
          }
          else {
            if (control_para.longitudinal_mode == 4){ //traj mode
              float desired_speed;
              if(nearest_idx <= 10){
                desired_speed = current_waypoints.at(next_waypoint_number_).twist.twist.linear.x;
              }else{
		            if(nearest_idx <current_waypoints.size()-1){
                  desired_speed = current_waypoints.at(nearest_idx).twist.twist.linear.x;
                }else{
                  desired_speed = 0;
                  control_cmd.steer =0;
                }
	            }
              control_cmd.accel = pid_controller.outputSignal(v_x,desired_speed);
	            ROS_INFO_STREAM("[Control] Longitudinal desired Speed: "<< desired_speed);
            }

          } 
        }
      }else{
        
        ROS_INFO_STREAM("[Contorl] Longitudinal control disabled");
      }
    }else{
      ROS_WARN("[Control] Waiting for signals: ego_state: %d, final_waypoints: %d, utm_pose: %d", egoStateFlag,
                finalWaypointsFlag,utmPoseFlag);
    }

  }

}
