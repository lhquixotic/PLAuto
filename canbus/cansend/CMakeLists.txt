cmake_minimum_required(VERSION 2.8.3)
project(cansend)

add_compile_options(-std=c++11)

set(PROJECT_DEPS
  roscpp
  std_msgs
  autoware_msgs
  )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  can_msgs
  autoware_msgs
  )

catkin_package(
  INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS
  DEPENDS
)

include_directories(
  include
  include/protocol
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
)
add_subdirectory(include/protocol)
# Each node in the package must be declared like this
add_executable(${PROJECT_NAME}
  src/cansend_handle.cpp
  src/cansend.cpp
  src/main.cpp
  )
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  )
target_link_libraries(${PROJECT_NAME}
  sendprotocol
  )
