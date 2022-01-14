#include <ros/ros.h>
#include "decision_making_handle.hpp"

typedef ns_decision_making::DecisionMakingHandle DecisionMakingHandle;

int main(int argc, char **argv){
    ros::init(argc, argv, "decision_making");
    ros::NodeHandle nodeHandle("~");
    DecisionMakingHandle myDecisionMakingHandle(nodeHandle);
    ros::Rate loop_rate(myDecisionMakingHandle.getNodeRate());
    while (ros::ok()) {
        myDecisionMakingHandle.run();
        ros::spinOnce();

        loop_rate.sleep();
    }
    return 0;
}