#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include "fsd_common_msgs/ConeDetections.h"
#include "std_msgs/String.h"

namespace ns_template {
struct Para{

};
class Template {
  

 public:
  // Constructor
  Template(ros::NodeHandle &nh);

  // Getters
  fsd_common_msgs::ConeDetections getConeDetections(); //FIXME: get value for send

  // Setters
  void setConeDetections(fsd_common_msgs::ConeDetections cones); //FIXME: set value from received msgs
  void setParameters(Para msg);

  void runAlgorithm(); //FIXME: main function to run

 private:

  ros::NodeHandle &nh_;

  fsd_common_msgs::ConeDetections cone_current;

  Para para;
};
}

#endif //TEMPLATE_HPP
