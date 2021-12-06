#include <ros/ros.h>
#include "topic_to_can_handle.hpp"

typedef ns_topic_to_can::TopicToCanHandle TopicToCanHandle;

int main(int argc, char **argv) {
  ros::init(argc, argv, "topic_to_can");
  ros::NodeHandle nodeHandle("~");
  TopicToCanHandle myTopicToCanHandle(nodeHandle);
  ros::Rate loop_rate(myTopicToCanHandle.getNodeRate());
  while (ros::ok()) {

    myTopicToCanHandle.run();

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  return 0;
}

