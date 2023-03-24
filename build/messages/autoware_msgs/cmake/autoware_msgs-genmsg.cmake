# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "autoware_msgs: 53 messages, 1 services")

set(MSG_I_FLAGS "-Iautoware_msgs:/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Ijsk_recognition_msgs:/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Ipcl_msgs:/opt/ros/noetic/share/pcl_msgs/cmake/../msg;-Ijsk_footstep_msgs:/opt/ros/noetic/share/jsk_footstep_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(autoware_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" "geometry_msgs/Point:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" "jsk_recognition_msgs/BoundingBox:geometry_msgs/Pose:geometry_msgs/Point32:std_msgs/MultiArrayLayout:geometry_msgs/Quaternion:geometry_msgs/Point:std_msgs/Float32MultiArray:geometry_msgs/PolygonStamped:geometry_msgs/Vector3:geometry_msgs/Polygon:sensor_msgs/PointCloud2:std_msgs/Header:geometry_msgs/PointStamped:sensor_msgs/PointField:std_msgs/MultiArrayDimension"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" "jsk_recognition_msgs/BoundingBox:geometry_msgs/Pose:geometry_msgs/Point32:std_msgs/MultiArrayLayout:autoware_msgs/CloudCluster:geometry_msgs/Quaternion:geometry_msgs/Point:std_msgs/Float32MultiArray:geometry_msgs/PolygonStamped:geometry_msgs/Vector3:geometry_msgs/Polygon:sensor_msgs/PointCloud2:std_msgs/Header:geometry_msgs/PointStamped:sensor_msgs/PointField:std_msgs/MultiArrayDimension"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" "autoware_msgs/ValueSet"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" "std_msgs/Header:autoware_msgs/ControlCommand"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" "autoware_msgs/Waypoint:geometry_msgs/PolygonStamped:autoware_msgs/DTLane:autoware_msgs/LaneArray:geometry_msgs/TwistStamped:geometry_msgs/Polygon:std_msgs/Header:geometry_msgs/Point32:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Twist:geometry_msgs/Vector3:sensor_msgs/PointCloud2:autoware_msgs/Lane:geometry_msgs/Pose:std_msgs/ColorRGBA:geometry_msgs/PoseStamped:sensor_msgs/Image:sensor_msgs/PointField:autoware_msgs/WaypointState"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" "autoware_msgs/Waypoint:geometry_msgs/PolygonStamped:autoware_msgs/DTLane:autoware_msgs/LaneArray:geometry_msgs/TwistStamped:geometry_msgs/Polygon:std_msgs/Header:autoware_msgs/WaypointState:geometry_msgs/Point32:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Vector3:sensor_msgs/PointCloud2:autoware_msgs/Lane:geometry_msgs/Pose:std_msgs/ColorRGBA:geometry_msgs/PoseStamped:autoware_msgs/DetectedObject:sensor_msgs/Image:sensor_msgs/PointField:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" "std_msgs/Header:autoware_msgs/ImageRect"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" "autoware_msgs/ImageRectRanged:std_msgs/Header:autoware_msgs/ImageRect"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" "autoware_msgs/ImageRectRanged:std_msgs/Header:autoware_msgs/ImageRect"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" "autoware_msgs/ImageRect"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" "geometry_msgs/Pose:geometry_msgs/PoseStamped:autoware_msgs/WaypointState:autoware_msgs/Waypoint:geometry_msgs/Point:geometry_msgs/Quaternion:geometry_msgs/TwistStamped:geometry_msgs/Vector3:std_msgs/Header:autoware_msgs/DTLane:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" "geometry_msgs/Pose:geometry_msgs/PoseStamped:autoware_msgs/WaypointState:autoware_msgs/Waypoint:geometry_msgs/Point:geometry_msgs/Quaternion:geometry_msgs/TwistStamped:geometry_msgs/Vector3:std_msgs/Header:autoware_msgs/Lane:autoware_msgs/DTLane:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" "geometry_msgs/Point:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" "geometry_msgs/PoseArray:geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/Point:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" "autoware_msgs/ControlCommand:autoware_msgs/BrakeCmd:geometry_msgs/TwistStamped:geometry_msgs/Vector3:autoware_msgs/Gear:std_msgs/Header:autoware_msgs/LampCmd:autoware_msgs/AccelCmd:autoware_msgs/SteerCmd:autoware_msgs/VehicleCmd:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" "autoware_msgs/ExtractedPosition:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" "autoware_msgs/TrafficLightResult:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" "autoware_msgs/ColorSet:autoware_msgs/ValueSet:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" "autoware_msgs/ControlCommand:autoware_msgs/BrakeCmd:geometry_msgs/TwistStamped:geometry_msgs/Vector3:autoware_msgs/Gear:std_msgs/Header:autoware_msgs/LampCmd:autoware_msgs/AccelCmd:autoware_msgs/SteerCmd:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" "autoware_msgs/Gear:std_msgs/Header"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" "geometry_msgs/Point:autoware_msgs/GeometricRectangle"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" "geometry_msgs/Point:autoware_msgs/GeometricRectangle:std_msgs/Header:autoware_msgs/VscanTracked"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" "geometry_msgs/Pose:geometry_msgs/PoseStamped:autoware_msgs/WaypointState:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/TwistStamped:geometry_msgs/Vector3:std_msgs/Header:autoware_msgs/DTLane:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" ""
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" "sensor_msgs/NavSatStatus:geometry_msgs/Vector3:std_msgs/Header:sensor_msgs/NavSatFix:geometry_msgs/Twist"
)

get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" NAME_WE)
add_custom_target(_autoware_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "autoware_msgs" "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" "sensor_msgs/Image:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)

### Generating Services
_generate_srv_cpp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
)

### Generating Module File
_generate_module_cpp(autoware_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(autoware_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(autoware_msgs_generate_messages autoware_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_cpp _autoware_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_msgs_gencpp)
add_dependencies(autoware_msgs_gencpp autoware_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)
_generate_msg_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)

### Generating Services
_generate_srv_eus(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
)

### Generating Module File
_generate_module_eus(autoware_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(autoware_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(autoware_msgs_generate_messages autoware_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_eus _autoware_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_msgs_geneus)
add_dependencies(autoware_msgs_geneus autoware_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)
_generate_msg_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)

### Generating Services
_generate_srv_lisp(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
)

### Generating Module File
_generate_module_lisp(autoware_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(autoware_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(autoware_msgs_generate_messages autoware_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_lisp _autoware_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_msgs_genlisp)
add_dependencies(autoware_msgs_genlisp autoware_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)
_generate_msg_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)

### Generating Services
_generate_srv_nodejs(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
)

### Generating Module File
_generate_module_nodejs(autoware_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(autoware_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(autoware_msgs_generate_messages autoware_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_nodejs _autoware_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_msgs_gennodejs)
add_dependencies(autoware_msgs_gennodejs autoware_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/jsk_recognition_msgs/cmake/../msg/BoundingBox.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayLayout.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Float32MultiArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PointStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/MultiArrayDimension.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PolygonStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Polygon.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point32.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/ColorRGBA.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseArray.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg"
  "${MSG_I_FLAGS}"
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/TwistStamped.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)
_generate_msg_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/sensor_msgs/cmake/../msg/NavSatFix.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Twist.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)

### Generating Services
_generate_srv_py(autoware_msgs
  "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
)

### Generating Module File
_generate_module_py(autoware_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(autoware_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(autoware_msgs_generate_messages autoware_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AccelCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/AdjustXY.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/BrakeCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Centroids.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudCluster.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/CloudClusterArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ColorSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommand.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ControlCommandStamped.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DTLane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObject.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/DetectedObjectArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ExtractedPosition.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Gear.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GeometricRectangle.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ICPStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageLaneObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObj.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageObjects.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRect.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ImageRectRanged.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/IndicatorCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LampCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Lane.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/LaneArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/NDTStat.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjLabel.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ObjPose.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/PointsImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ProjectionMatrix.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/RemoteCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ScanImage.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Signals.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/State.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/StateCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SteerCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeDiff.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/SyncTimeMonitor.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLight.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TrafficLightResultArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/TunedResult.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/ValueSet.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleCmd.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleLocation.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VehicleStatus.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTracked.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/VscanTrackedArray.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/WaypointState.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/msg/GpsInfo.msg" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/lhq/Projects/PLAuto/src/messages/autoware_msgs/srv/RecognizeLightState.srv" NAME_WE)
add_dependencies(autoware_msgs_generate_messages_py _autoware_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(autoware_msgs_genpy)
add_dependencies(autoware_msgs_genpy autoware_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS autoware_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/autoware_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(autoware_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET jsk_recognition_msgs_generate_messages_cpp)
  add_dependencies(autoware_msgs_generate_messages_cpp jsk_recognition_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(autoware_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(autoware_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/autoware_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(autoware_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET jsk_recognition_msgs_generate_messages_eus)
  add_dependencies(autoware_msgs_generate_messages_eus jsk_recognition_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(autoware_msgs_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(autoware_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/autoware_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(autoware_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET jsk_recognition_msgs_generate_messages_lisp)
  add_dependencies(autoware_msgs_generate_messages_lisp jsk_recognition_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(autoware_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(autoware_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/autoware_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(autoware_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET jsk_recognition_msgs_generate_messages_nodejs)
  add_dependencies(autoware_msgs_generate_messages_nodejs jsk_recognition_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(autoware_msgs_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(autoware_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/autoware_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(autoware_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET jsk_recognition_msgs_generate_messages_py)
  add_dependencies(autoware_msgs_generate_messages_py jsk_recognition_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(autoware_msgs_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(autoware_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
