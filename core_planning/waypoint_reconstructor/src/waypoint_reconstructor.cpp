/*
    Formula Student Driverless Project (FSD-Project).
    Copyright (c) 2019:
     - chentairan <killasipilin@gmail.com>

    FSD-Project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FSD-Project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FSD-Project.  If not, see <https://www.gnu.org/licenses/>.
*/

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
    return lane_;
}
geometry_msgs::PoseStamped Waypoint_Reconstructor::getCurrentPose(){
    geometry_msgs::PoseStamped ps;
    ps.pose=current_pose;
    ps.header.frame_id="world";
    ps.header.stamp=ros::Time::now();
    ps.header.seq = 1;
    return ps;
}

// Setters
void Waypoint_Reconstructor::setSelfPose(const nav_msgs::OdometryConstPtr &msg){
    current_pose = msg->pose.pose;
}
void Waypoint_Reconstructor::setV2V(const common_msgs::V2VConstPtr &msg){
    v2v_=*msg;
    current_leader_point= utm::lla2utm(v2v_.fix);
    current_leader_point.x -= origin.x;
    current_leader_point.y -= origin.y;
    current_leader_point.z -= origin.z;
}
void Waypoint_Reconstructor::setGpsOrigin(const utm::Gps_point &msg){
    origin = msg;
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
    lane_.waypoints.clear();
    for(int i=0;i<leader_path.size();i++){
        autoware_msgs::Waypoint wp;
        wp.pose.pose.position=leader_path[i];
        lane_.waypoints.push_back(wp);
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
