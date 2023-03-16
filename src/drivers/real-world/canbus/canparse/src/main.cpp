#include <ros/ros.h>
#include "canparse_handle.hpp"

typedef ns_canparse::CanparseHandle CanparseHandle;

int main(int argc, char **argv) {
  ros::init(argc, argv, "canparse");
  ros::NodeHandle nodeHandle("~");
  CanparseHandle myCanparseHandle(nodeHandle);
  ros::Rate loop_rate(myCanparseHandle.getNodeRate());
  while (ros::ok()) {

    myCanparseHandle.run();

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  return 0;
}

