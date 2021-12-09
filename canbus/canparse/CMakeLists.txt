cmake_minimum_required(VERSION 2.8.3)
project(canparse)

add_compile_options(-std=c++11)

set(PROJECT_DEPS
  roscpp
  std_msgs
  common_msgs
  can_msgs
  )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  common_msgs
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
  include/protocol
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
)
add_subdirectory(./include/protocol) 
AUX_SOURCE_DIRECTORY(./src  DIR_SRCS)
# Each node in the package must be declared like this
add_executable(${PROJECT_NAME}
   ${DIR_SRCS}
  )
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})

target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  )
target_link_libraries(${PROJECT_NAME}
  receiveprotocol
  )
  
