cmake_minimum_required(VERSION 3.0.2)
project(plauto_cognition_msgs)

find_package(catkin REQUIRED genmsg std_msgs # essential dependency  
    geometry_msgs plauto_perception_msgs plauto_nav_msgs common_msgs nav_msgs
)

catkin_python_setup()

add_message_files(DIRECTORY msg FILES
    JunctionMapState.msg
    LaneState.msg
    MultiLaneMapState.msg
    MapState.msg
    RoadObstacle.msg
    DrivingSpace.msg
    DynamicBoundary.msg
    DynamicBoundaryPoint.msg
)

generate_messages(DEPENDENCIES std_msgs geometry_msgs plauto_perception_msgs plauto_nav_msgs common_msgs nav_msgs)
catkin_package(CATKIN_DEPENDS std_msgs geometry_msgs plauto_perception_msgs plauto_nav_msgs common_msgs nav_msgs)
