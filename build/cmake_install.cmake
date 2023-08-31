# Install script for directory: /home/lhq/Projects/PLAuto/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lhq/Projects/PLAuto/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/lhq/Projects/PLAuto/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/lhq/Projects/PLAuto/install" TYPE PROGRAM FILES "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/lhq/Projects/PLAuto/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/lhq/Projects/PLAuto/install" TYPE PROGRAM FILES "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/lhq/Projects/PLAuto/install/setup.bash;/home/lhq/Projects/PLAuto/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/lhq/Projects/PLAuto/install" TYPE FILE FILES
    "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/setup.bash"
    "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/lhq/Projects/PLAuto/install/setup.sh;/home/lhq/Projects/PLAuto/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/lhq/Projects/PLAuto/install" TYPE FILE FILES
    "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/setup.sh"
    "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/lhq/Projects/PLAuto/install/setup.zsh;/home/lhq/Projects/PLAuto/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/lhq/Projects/PLAuto/install" TYPE FILE FILES
    "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/setup.zsh"
    "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/lhq/Projects/PLAuto/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/lhq/Projects/PLAuto/install" TYPE FILE FILES "/home/lhq/Projects/PLAuto/build/catkin_generated/installspace/.rosinstall")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lhq/Projects/PLAuto/build/gtest/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/common/autoware_libs/autoware_build_flags/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ad_demo/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_common/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/cognition/dynamic_map/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/common/utils/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/navigation/pose_reporter/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/messages/autoware_config_msgs/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_msgs/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ackermann_msgs/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_scenario_runner_types/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_waypoint_types/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/messages/common_msgs/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/navigation/protocol/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/navigation/map_provider/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/planning/decision/lane_models/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/planning/protocol/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/messages/autoware_system_msgs/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/localization_adapter/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/ros_compatibility/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ackermann_control/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ad_agent/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_manual_control/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_bridge/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_scenario_runner/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_twist_to_control/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_walker_agent/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_waypoint_publisher/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/common/autoware_libs/ros_observer/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/rqt_carla_control/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/messages/autoware_msgs/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_adapter/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/decision_making/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/perception/protocol/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/cognition/protocol/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/common/autoware_libs/amathutils_lib/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/common/autoware_libs/libwaypoint_follower/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/control/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/pcl_recorder/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/common/autoware_libs/autoware_health_checker/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/rviz_carla_plugin/cmake_install.cmake")
  include("/home/lhq/Projects/PLAuto/build/planning/waypoint_reconstructor/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/lhq/Projects/PLAuto/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
