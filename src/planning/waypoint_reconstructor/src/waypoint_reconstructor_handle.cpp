#include <ros/ros.h>
#include "waypoint_reconstructor_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_waypoint_reconstructor {

// Constructor
Waypoint_ReconstructorHandle::Waypoint_ReconstructorHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    private_nh_("~"),
    waypoint_reconstructor_(nodeHandle) {
  ROS_INFO("Constructing Handle");
  v2vFlag=poseFlag=false;
  loadParameters();
  subscribeToTopics();
  publishToTopics();
}

// Getters
int Waypoint_ReconstructorHandle::getNodeRate() const { return node_rate_; }

// Methods
void Waypoint_ReconstructorHandle::loadParameters() {
  ROS_INFO("loading handle parameters");
  if (!private_nh_.param<std::string>("localization_utm_topic_name",current_pose_topic_name_,"/localization/utmpose")) {
    ROS_WARN_STREAM("Did not load localization_utm_topic_name. Standard value is: " << current_pose_topic_name_);
  }
  if (!private_nh_.param<std::string>("platoon_state_topic_name",platoon_state_topic_name_,"/carla/scenario_generation/platoon_state")) {
    ROS_WARN_STREAM("Did not load platoon_state_topic_name_. Standard value is: " << platoon_state_topic_name_);
  }
  else{
    ROS_INFO_STREAM("Load platoon_state topic name as " << platoon_state_topic_name_);
  }
  if (!private_nh_.param<std::string>("final_waypoints_topic_name",final_waypoint_topic_name_,"final_waypoints")) {
    ROS_WARN_STREAM("Did not load final_waypoints_topic_name. Standard value is: " << final_waypoint_topic_name_);
  }
  if (!private_nh_.param<std::string>("final_waypoints_visual_topic_name",final_waypoint_visual_topic_name_,"final_waypoints_vis")) {
    ROS_WARN_STREAM("Did not load final_waypoints_topic_name. Standard value is: " << final_waypoint_visual_topic_name_);
  }
  if (!private_nh_.param<std::string>("leader_pose_topic_name",leader_pose_topic_name_,"leader_pose")) {
    ROS_WARN_STREAM("Did not load leader_pose_topic_name. Standard value is: " << leader_pose_topic_name_);
  }
  if (!private_nh_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
  // private_nh_.param<double>("Gps_origin/x",origin_.x,274083.3651381);
  // private_nh_.param<double>("Gps_origin/y",origin_.y,4006502.509805);
  // private_nh_.param<double>("Gps_origin/z",origin_.z,74.80);
  // ROS_INFO_STREAM("Gps origin: x: "<<origin_.x<<", y: " << origin_.y<<", z: "<< origin_.z);
  // waypoint_reconstructor_.setGpsOrigin(origin_);
}

void Waypoint_ReconstructorHandle::subscribeToTopics() {
  ROS_INFO("subscribe to topics");
  sub1_ = nodeHandle_.subscribe(current_pose_topic_name_, 10, &Waypoint_ReconstructorHandle::poseCallback, this);
  sub2_ = nodeHandle_.subscribe(platoon_state_topic_name_, 10, &Waypoint_ReconstructorHandle::PlatoonStateCallback, this);
}

void Waypoint_ReconstructorHandle::publishToTopics() {
  ROS_INFO("publish to topics");
  pub1_ = nodeHandle_.advertise<autoware_msgs::Lane>(final_waypoint_topic_name_, 10);
  // pub2_ = nodeHandle_.advertise<geometry_msgs::PoseStamped>(pose_topic_name_, 10);
  pub3_ = nodeHandle_.advertise<nav_msgs::Path>(final_waypoint_visual_topic_name_,10);
  pub4_ = nodeHandle_.advertise<nav_msgs::Odometry>(leader_pose_topic_name_,10);
}

void Waypoint_ReconstructorHandle::run() {
  //check read ready
  if(!v2vFlag || !poseFlag){
      ROS_WARN("Necessary topics are not subscribed yet ... ");
      ROS_WARN("v2v:%d  pose:%d",v2vFlag,poseFlag);
      return;
  }
  //
  waypoint_reconstructor_.runAlgorithm();
  sendMsg();
  v2vFlag=poseFlag=false;
}

void Waypoint_ReconstructorHandle::sendMsg() {
  if(waypoint_reconstructor_.isInited()){
     pub1_.publish(waypoint_reconstructor_.getFinalWaypoints());
  }
  // pub2_.publish(waypoint_reconstructor_.getCurrentPose());
  pub3_.publish(waypoint_reconstructor_.getFinalWaypointsVis());
  pub4_.publish(waypoint_reconstructor_.getLeaderPose());
  
}

void Waypoint_ReconstructorHandle::poseCallback(const nav_msgs::OdometryConstPtr &msg) {
  waypoint_reconstructor_.setSelfPose(msg);
  poseFlag=true;
}

void Waypoint_ReconstructorHandle::PlatoonStateCallback(const common_msgs::PlatoonStateConstPtr &msg) {
  waypoint_reconstructor_.setPlatoonState(msg);
  v2vFlag=true;
}

}