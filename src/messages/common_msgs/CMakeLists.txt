cmake_minimum_required(VERSION 3.0.2)
project(common_msgs)

find_package(catkin REQUIRED)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(catkin REQUIRED
  COMPONENTS
    message_generation
    std_msgs
    geometry_msgs
    sensor_msgs
    nav_msgs
)

add_message_files(DIRECTORY msg
  FILES
    VehicleDynamicState.msg
    VehicleState.msg
    GpsInfo.msg
    ChassisState.msg
    PlatoonState.msg
    V2V.msg
    PolarBoundary.msg
    StopDecision.msg
    ControlCommand.msg
    MapState.msg
    Lane.msg
    LanePoint.msg
    LaneState.msg
    MultiLaneMapState.msg
    JunctionMapState.msg
    RigidBodyState.msg
    RigidBodyStateStamped.msg
    RoadObstacle.msg
    ObjectClass.msg
    ObjectSignals.msg
    DetectionBox.msg
    DetectionBoxArray.msg
    DimensionWithCovariance.msg
    DTLane.msg
    FrenetSerretState2D.msg
    TrackingBox.msg
    TrackingBoxArray.msg
    Waypoint.msg
    WaypointState.msg
    BoundingBox.msg
    Map.msg
)

generate_messages(
  DEPENDENCIES
    std_msgs
    geometry_msgs
    sensor_msgs
    nav_msgs
)

catkin_package(
  CATKIN_DEPENDS
    message_runtime
    std_msgs
)
