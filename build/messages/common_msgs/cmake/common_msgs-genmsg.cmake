# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "common_msgs: 9 messages, 0 services")

set(MSG_I_FLAGS "-Icommon_msgs:/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Inav_msgs:/opt/ros/noetic/share/nav_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(common_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" "geometry_msgs/Vector3:common_msgs/ChassisState:std_msgs/Header:common_msgs/VehicleDynamicState:geometry_msgs/Twist:geometry_msgs/Point:geometry_msgs/TwistWithCovariance:geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/PoseWithCovariance:nav_msgs/Odometry"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" "sensor_msgs/NavSatFix:std_msgs/Header:geometry_msgs/Twist:sensor_msgs/NavSatStatus:geometry_msgs/Vector3"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" "geometry_msgs/Vector3:common_msgs/ChassisState:std_msgs/Header:common_msgs/VehicleDynamicState:geometry_msgs/Twist:geometry_msgs/Point:geometry_msgs/TwistWithCovariance:geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/PoseWithCovariance:nav_msgs/Odometry:common_msgs/VehicleState"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" "geometry_msgs/Vector3:common_msgs/ChassisState:std_msgs/Header:common_msgs/VehicleDynamicState:common_msgs/PlatoonState:geometry_msgs/Twist:geometry_msgs/Point:geometry_msgs/TwistWithCovariance:geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/PoseWithCovariance:nav_msgs/Odometry:common_msgs/VehicleState"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" NAME_WE)
add_custom_target(_common_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "common_msgs" "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" "std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)
_generate_msg_cpp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(common_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(common_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(common_msgs_generate_messages common_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_cpp _common_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_msgs_gencpp)
add_dependencies(common_msgs_gencpp common_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)
_generate_msg_eus(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(common_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(common_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(common_msgs_generate_messages common_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_eus _common_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_msgs_geneus)
add_dependencies(common_msgs_geneus common_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)
_generate_msg_lisp(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(common_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(common_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(common_msgs_generate_messages common_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_lisp _common_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_msgs_genlisp)
add_dependencies(common_msgs_genlisp common_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)
_generate_msg_nodejs(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(common_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(common_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(common_msgs_generate_messages common_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_nodejs _common_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_msgs_gennodejs)
add_dependencies(common_msgs_gennodejs common_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/noetic/share/nav_msgs/cmake/../msg/Odometry.msg;/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)
_generate_msg_py(common_msgs
  "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(common_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(common_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(common_msgs_generate_messages common_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleDynamicState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/VehicleState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ChassisState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PlatoonState.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/V2V.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/PolarBoundary.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/StopDecision.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/common_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(common_msgs_generate_messages_py _common_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(common_msgs_genpy)
add_dependencies(common_msgs_genpy common_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS common_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/common_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(common_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(common_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(common_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(common_msgs_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/common_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(common_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(common_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(common_msgs_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(common_msgs_generate_messages_eus nav_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/common_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(common_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(common_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(common_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(common_msgs_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/common_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(common_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(common_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(common_msgs_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(common_msgs_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/common_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(common_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(common_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(common_msgs_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(common_msgs_generate_messages_py nav_msgs_generate_messages_py)
endif()
