#include <ros/ros.h>
#include "gps_handle.hpp"

typedef ns_gps::GPSHandle GPSHandle;

int main(int argc, char **argv) {
  ros::init(argc, argv, "gps");
  ros::NodeHandle nodeHandle("~");
  GPSHandle myGPSHandle(nodeHandle);
  ros::Rate loop_rate(myGPSHandle.getNodeRate());
  while (ros::ok()) {

    myGPSHandle.run();

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  return 0;
}

