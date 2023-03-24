execute_process(COMMAND "/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_bridge/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_ros_bridge/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
