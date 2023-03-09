#ifndef DECISION_MAKING_HANDLE_HPP
#define DECISION_MAKING_HANDLE_HPP

#include "decision_making.hpp"

namespace ns_decision_making{

class DecisionMakingHandle{

public:
    // constructor
    DecisionMakingHandle(ros::NodeHandle &nodeHandle);

    //Getters
    int getNodeRate() const;

    // Methods
    void loadParameters();
    void subscribeToTopics();
    void publishToTopics();
    void run();
    void sendMsg();

private:
    ros::NodeHandle nodeHandle_;
    ros::Subscriber PolarBoundarySubscriber_;

    ros::Publisher StopFlagPublisher_;

    void PolarBoundaryCallback(const common_msgs::PolarBoundary &msg);

    std::string polar_boundary_topic_name_;
    
    std::string stop_flag_topic_name_;

    int node_rate_;

    DecisionMaking decision_making_;

};
}

#endif // DECISION_MAKING_HANDLE_HPP