# ifndef DECISION_MAKING_HPP
# define DECISION_MAKING_HPP

#include "common_msgs/PolarBoundary.h"
#include "common_msgs/StopDecision.h"

namespace ns_decision_making {
    
class DecisionMaking{
public:
    // Constructor
    DecisionMaking(ros::NodeHandle &nh);

    // Getters
    common_msgs::StopDecision getStopDecision();

    //Setters
    void setPolarBoundary(const common_msgs::PolarBoundary &msg); // get polar boundary from subscriber

    //Methods
    void runAlgorithm();
    bool polarBoundaryFlag = false;

    // parameters
    int stop_flag = 0;
    int lower_angle = 175; 
    int upper_angle = 185; // angle bound of obstacles
    float stop_threshold = 5; // distance between ego and obstacles

    bool havePolarBoundary = false;

private:
    ros::NodeHandle &nh_;
    common_msgs::PolarBoundary polar_boundary;
    common_msgs::StopDecision stop_decision;

    std::vector<float> bound_distance;
};
}

#endif // DECISION_MAKING_HPP