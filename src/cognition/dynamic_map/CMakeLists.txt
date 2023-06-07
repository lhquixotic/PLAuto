cmake_minimum_required(VERSION 2.8.3)
project(objects_locator)

find_package(catkin REQUIRED)
catkin_package()

catkin_python_setup()

catkin_install_python(PROGRAMS
  nodes/objects_locator
  nodes/put_buffer
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
