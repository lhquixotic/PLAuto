cmake_minimum_required(VERSION 2.8.3)
project(cluster_detector)

add_compile_options(-std=c++11)

set(CMAKE_BUILD_TYPE "Release"
    common_msgs)
# set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )



find_package(catkin REQUIRED COMPONENTS
    roscpp
    common_msgs)
# find_package(roscpp)

find_package(PCL 1.7 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)





catkin_package(
    INCLUDE_DIRS include
    CATKIN_DEPENDS roscpp 
)


include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    # ${roscpp_INCLUDE_DIRS}
    
)
link_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${PCL_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    # ${roscpp_INCLUDE_DIRS}
    
    )

add_executable(cluster_detector_node 
    src/cluster_detector.cc
    src/ros_detector.cc
    src/cluster_detector_node.cc)


target_link_libraries(cluster_detector_node
    ${catkin_LIBRARIES}
    ${PCL_LIBRARIES}
    ${OpenCV_LIBRARIES}
    # ${roscpp_LIBRARIRS}
    
)
