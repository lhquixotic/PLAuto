cmake_minimum_required(VERSION 2.8.3)
project(pose_reporter)

find_package(catkin REQUIRED)
catkin_package()

# catkin_python_setup()

catkin_install_python(PROGRAMS
  nodes/pose_reporter
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
