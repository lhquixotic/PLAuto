# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "autoware_system_msgs: 5 messages, 0 services")

set(MSG_I_FLAGS "-Iautoware_system_msgs:/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg;-Irosgraph_msgs:/opt/ros/noetic/share/rosgraph_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(autoware_system_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" NAME_WE)
add_custom_target(_autoware_system_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_system_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" NAME_WE)
add_custom_target(_autoware_system_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_system_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" "autoware_system_msgs/DiagnosticStatus:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" NAME_WE)
add_custom_target(_autoware_system_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_system_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" "autoware_system_msgs/DiagnosticStatus:std_msgs/Header:autoware_system_msgs/DiagnosticStatusArray"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" NAME_WE)
add_custom_target(_autoware_system_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_system_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" "autoware_system_msgs/DiagnosticStatus:std_msgs/Header:autoware_system_msgs/DiagnosticStatusArray"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" NAME_WE)
add_custom_target(_autoware_system_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_system_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" "std_msgs/Header:rosgraph_msgs/TopicStatistics:autoware_system_msgs/NodeStatus:autoware_system_msgs/DiagnosticStatusArray:autoware_system_msgs/DiagnosticStatus:autoware_system_msgs/HardwareStatus"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_cpp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_cpp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_cpp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_cpp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/rosgraph_msgs/cmake/../msg/TopicStatistics.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(autoware_system_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(autoware_system_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(autoware_system_msgs_generate_messages autoware_system_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_cpp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_cpp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_cpp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_cpp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_cpp _autoware_system_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_system_msgs_gencpp)
add_dependencies(autoware_system_msgs_gencpp autoware_system_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_system_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_eus(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_eus(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_eus(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_eus(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/rosgraph_msgs/cmake/../msg/TopicStatistics.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(autoware_system_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(autoware_system_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(autoware_system_msgs_generate_messages autoware_system_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_eus _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_eus _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_eus _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_eus _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_eus _autoware_system_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_system_msgs_geneus)
add_dependencies(autoware_system_msgs_geneus autoware_system_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_system_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_lisp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_lisp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_lisp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_lisp(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/rosgraph_msgs/cmake/../msg/TopicStatistics.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(autoware_system_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(autoware_system_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(autoware_system_msgs_generate_messages autoware_system_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_lisp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_lisp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_lisp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_lisp _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_lisp _autoware_system_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_system_msgs_genlisp)
add_dependencies(autoware_system_msgs_genlisp autoware_system_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_system_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_nodejs(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_nodejs(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_nodejs(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_nodejs(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/rosgraph_msgs/cmake/../msg/TopicStatistics.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(autoware_system_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(autoware_system_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(autoware_system_msgs_generate_messages autoware_system_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_nodejs _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_nodejs _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_nodejs _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_nodejs _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_nodejs _autoware_system_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_system_msgs_gennodejs)
add_dependencies(autoware_system_msgs_gennodejs autoware_system_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_system_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_py(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_py(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_py(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
)
_generate_msg_py(autoware_system_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/rosgraph_msgs/cmake/../msg/TopicStatistics.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(autoware_system_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(autoware_system_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(autoware_system_msgs_generate_messages autoware_system_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_py _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/DiagnosticStatusArray.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_py _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/HardwareStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_py _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/NodeStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_py _autoware_system_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_system_msgs/msg/SystemStatus.msg" NAME_WE)
add_dependencies(autoware_system_msgs_generate_messages_py _autoware_system_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_system_msgs_genpy)
add_dependencies(autoware_system_msgs_genpy autoware_system_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_system_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_system_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET rosgraph_msgs_generate_messages_cpp)
  add_dependencies(autoware_system_msgs_generate_messages_cpp rosgraph_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(autoware_system_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_system_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET rosgraph_msgs_generate_messages_eus)
  add_dependencies(autoware_system_msgs_generate_messages_eus rosgraph_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(autoware_system_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_system_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET rosgraph_msgs_generate_messages_lisp)
  add_dependencies(autoware_system_msgs_generate_messages_lisp rosgraph_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(autoware_system_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_system_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET rosgraph_msgs_generate_messages_nodejs)
  add_dependencies(autoware_system_msgs_generate_messages_nodejs rosgraph_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(autoware_system_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_system_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET rosgraph_msgs_generate_messages_py)
  add_dependencies(autoware_system_msgs_generate_messages_py rosgraph_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(autoware_system_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
