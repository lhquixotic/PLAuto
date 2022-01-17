#include <ros/ros.h>
#include "decision_making_handle.hpp"
#include "register.h"
#include <chrono>

namespace ns_decision_making {

//Constructor
DecisionMakingHandle::DecisionMakingHandle(ros::NodeHandle &nodeHandle):
    nodeHandle_(nodeHandle),
    decision_making_(nodeHandle){
    ROS_INFO ("Constructing Handle");
    loadParameters();
    subscribeToTopics();
    publishToTopics();
}

// Getters
int DecisionMakingHandle::getNodeRate() const { return node_rate_; }

// Methods
void DecisionMakingHandle::loadParameters(){
    ROS_INFO ("Loading Handle Parameters");
    if(!nodeHandle_.param<std::string>("polar_boundary_topic_name",
                                        polar_boundary_topic_name_,
                                        "/polar_boundary")){
        ROS_WARN_STREAM(
        "Did not load polar_boundary_topic_name. Standard value is: " << polar_boundary_topic_name_);    
                                        }
    
    if(!nodeHandle_.param<std::string>("stop_flag_topic_name",
                                        stop_flag_topic_name_,
                                        "/stop_flag")){
        ROS_WARN_STREAM(
            "Did not load stop_flag_topic_name. Standard value is: " << stop_flag_topic_name_);
                                        }

    if (!nodeHandle_.param("node_rate", node_rate_, 5)) {
        ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
    }
    
}

void DecisionMakingHandle::subscribeToTopics(){
    ROS_INFO("Subscribe to topics");
    PolarBoundarySubscriber_=
        nodeHandle_.subscribe(polar_boundary_topic_name_, 10, &DecisionMakingHandle::PolarBoundaryCallback, this);
    // ROS_INFO("Finish subscribeToTopics");
}

void DecisionMakingHandle::publishToTopics(){
    ROS_INFO("Publish to topics");
    StopFlagPublisher_ = nodeHandle_.advertise<common_msgs::StopDecision>(stop_flag_topic_name_, 1);
}

void DecisionMakingHandle::run() {
    decision_making_.runAlgorithm();
    sendMsg();
}

void DecisionMakingHandle::sendMsg(){
    StopFlagPublisher_.publish(decision_making_.getStopDecision());
}

//Callbacks
void DecisionMakingHandle::PolarBoundaryCallback(const common_msgs::PolarBoundary &msg){
    // ROS_WARN("PolarBoundary callback calling...");
    decision_making_.setPolarBoundary(msg);
    decision_making_.polarBoundaryFlag = true;
}
}