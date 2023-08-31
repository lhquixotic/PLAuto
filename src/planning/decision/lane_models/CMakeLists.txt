cmake_minimum_required(VERSION 3.0.2)
project(plauto_decision_lane_models)

find_package(catkin REQUIRED) #autoware_msgs
catkin_package()

catkin_python_setup()

catkin_install_python(PROGRAMS nodes/fsm_lane_utility
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
