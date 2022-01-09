#include <ros/ros.h>
#include <sstream>
#include "waypoint_reconstructor.hpp"

const int POINTNUMBER=200;
const double EFFECTIVE_DIS=0.2;
namespace ns_waypoint_reconstructor {
// Constructor
Waypoint_Reconstructor::Waypoint_Reconstructor(ros::NodeHandle &nh) : nh_(nh) {
    initFlag = false;
};

// Getters
bool Waypoint_Reconstructor::isInited(){
    return initFlag;
}
autoware_msgs::Lane Waypoint_Reconstructor::getFinalWaypoints(){
    return lane;
}
geometry_msgs::PoseStamped Waypoint_Reconstructor::getCurrentPose(){
    geometry_msgs::PoseStamped ps;
    ps.pose=current_pose;
    ps.header.frame_id="world";
    ps.header.stamp=ros::Time::now();
    ps.header.seq = 1;
    return ps;
}
nav_msgs::Odometry Waypoint_Reconstructor::getLeaderPose(){
    return leader_pose;
}
nav_msgs::Path Waypoint_Reconstructor::getFinalWaypointsVis(){
    leader_path_vis.poses.clear();
    leader_path_vis.header.frame_id = "world";
    leader_path_vis.header.stamp = ros::Time::now();
    for(int i=0;i<leader_path.size();i++){
        geometry_msgs::PoseStamped pose;
        pose.pose.position = leader_path[i];
        leader_path_vis.poses.push_back(pose);
    }
    return leader_path_vis;
}

// Setters
void Waypoint_Reconstructor::setSelfPose(const nav_msgs::OdometryConstPtr &msg){
    current_pose = msg->pose.pose;
    current_follower_point = current_pose.position;
}
void Waypoint_Reconstructor::setV2V(const common_msgs::V2VConstPtr &msg){
    v2v_info=*msg;
    leader_pose = v2v_info.odom;
    current_leader_point = leader_pose.pose.pose.position;
    ROS_INFO("current leader point x:%f, y:%f, z:%f.",current_leader_point.x,current_leader_point.y,current_leader_point.z);
}

void Waypoint_Reconstructor::initWaypoints() {
    double initx,inity,initz,endx,endy,endz;
    initx=current_follower_point.x;
    inity=current_follower_point.y;
    initz=current_follower_point.z;
    endx=current_leader_point.x;
    endy=current_leader_point.y;
    endz=current_leader_point.z;
    leader_path.clear();
    for(int i=1;i<=POINTNUMBER;i++){
        geometry_msgs::Point tmppoint;
        tmppoint.x=initx+(double)i/POINTNUMBER*(endx-initx);
        tmppoint.y=inity+(double)i/POINTNUMBER*(endy-inity);
        tmppoint.z=initz+(double)i/POINTNUMBER*(endz-initz);
        leader_path.push_back(tmppoint);
    }
    initFlag=true;
}
void Waypoint_Reconstructor::updateWaypoints() {
    geometry_msgs::Point last_leader_point=leader_path.back();
    if( getPlaneDistance(last_leader_point,current_leader_point)> EFFECTIVE_DIS){
        if(!leader_path.empty())  
            leader_path.pop_front();
        leader_path.push_back(current_leader_point);
    }
}
void Waypoint_Reconstructor::updateLane(){
    lane.waypoints.clear();
    for(int i=0;i<leader_path.size();i++){
        autoware_msgs::Waypoint wp;
        wp.pose.pose.position=leader_path[i];
        lane.waypoints.push_back(wp);
    }
}
void Waypoint_Reconstructor::runAlgorithm() {
    if(!initFlag) {
        initWaypoints();
    }else{
        updateWaypoints();
    }
    updateLane();
}
double Waypoint_Reconstructor::getPlaneDistance(geometry_msgs::Point a,geometry_msgs::Point b){
    double dis=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    return dis;
}

}
