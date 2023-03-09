#include <ros/ros.h>
#include "template.hpp"
#include <sstream>

namespace ns_template {
// Constructor
Template::Template(ros::NodeHandle &nh) : nh_(nh) {

};//FIXME:load config params.

// Getters
fsd_common_msgs::ConeDetections Template::getConeDetections() { return cone_current; }
//FIXME: get value from config files.

// Setters
void Template::setConeDetections(fsd_common_msgs::ConeDetections cones) {
  cone_current = cones;
}// FIXME:set value from subscriber.

void Template::runAlgorithm() {

}//FIXME:add code you want to execute.

}
