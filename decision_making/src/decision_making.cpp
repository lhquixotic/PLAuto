#include <ros/ros.h>
#include "decision_making.hpp"
#include <sstream>

namespace ns_decision_making{
    // Constructor
    DecisionMaking::DecisionMaking(ros::NodeHandle &nh) : nh_(nh){};

    //Getters
    common_msgs::StopDecision DecisionMaking::getStopDecision(){
        // ROS_INFO_STREAM("[Decision making] in getStopDecision()...");
        stop_decision.veh_stop_flag = stop_flag;
        stop_decision.header.frame_id = "decision";
        stop_decision.header.stamp = ros::Time::now();
        return stop_decision;
    }

    //Setters
    void DecisionMaking::setPolarBoundary(const common_msgs::PolarBoundary &msg){
        // ROS_INFO_STREAM("[Decision making] in setPolarBoundary()...");
        polar_boundary = msg;
        bound_distance = polar_boundary.distance;
        havePolarBoundary = true;
    }

    void DecisionMaking::runAlgorithm(){
        // ROS_INFO("[Decision making] in run()...");
        if (havePolarBoundary){
            // ROS_INFO("Have PolarBoundary!");
            for (int j=lower_angle;j<upper_angle;j++){
                if(bound_distance[j]<stop_threshold){
                    stop_flag = 1; //stop
                    ROS_WARN("Obstacles detected, stopping.");
                    break;
                }
                else{
                    stop_flag = 0; //go
                    //ROS_WARN("No obstacles detected, going.");
                }
            }
            havePolarBoundary = false;
        }

    }

}