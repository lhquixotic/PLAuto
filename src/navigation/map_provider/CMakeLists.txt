cmake_minimum_required(VERSION 3.0.2)
project(map_provider)

find_package(catkin REQUIRED)
catkin_package()

catkin_python_setup()

catkin_install_python(PROGRAMS nodes/local_map_generator
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
