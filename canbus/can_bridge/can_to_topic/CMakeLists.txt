cmake_minimum_required(VERSION 2.8.3)
project(can_to_topic)

add_compile_options(-std=c++11)

set(PROJECT_DEPS
  roscpp
  std_msgs
  can_msgs
  )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  can_msgs
  )

catkin_package(
  INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS
  DEPENDS
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
)

link_directories(
  ${catkin_LIB_DIRS} lib
)


# Each node in the package must be declared like this
add_executable(${PROJECT_NAME}
  src/can_to_topic_handle.cpp
  src/can_to_topic.cpp
  src/main.cpp
  src/likecan.cpp
  )

add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES} libCanCmd.so
  )

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES} libCanCmd.so
  )