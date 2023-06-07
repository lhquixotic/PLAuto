cmake_minimum_required(VERSION 2.8.3)
project(plauto_nav_msgs)

find_package(catkin REQUIRED genmsg std_msgs # essential dependency
    geometry_msgs
)

catkin_python_setup()

add_message_files(DIRECTORY msg FILES
    AuxiliaryReport.msg
    ChassisReport.msg
    ControlReport.msg
    FrenetSerretState.msg
    FrenetSerretState2D.msg
    ResourceReport.msg
    RigidBodyState.msg
    RigidBodyStateStamped.msg
    Lane.msg
    LaneBoundary.msg
    LanePoint.msg
    LaneSituation.msg
    Map.msg
    MapString.msg
    ReroutingRequest.msg
)

generate_messages(DEPENDENCIES std_msgs geometry_msgs)
catkin_package(CATKIN_DEPENDS std_msgs geometry_msgs)
