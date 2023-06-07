cmake_minimum_required(VERSION 3.0.2)
project(carla_adapter)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  common_msgs
  nav_msgs
  autoware_msgs
  plauto_common
)

catkin_package(CATKIN_DEPENDS rospy)

catkin_python_setup()

catkin_install_python(PROGRAMS 
  src/convert_topic
  src/scenario_generation 
  src/carla_map_generator
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

# catkin_install_python(PROGRAMS
#   src/convert_topic
#   src/scenario_generation
#   src/carla_map_generator
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
