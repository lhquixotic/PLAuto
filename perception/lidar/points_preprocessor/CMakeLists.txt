cmake_minimum_required(VERSION 2.8.3)
project(points_preprocessor)


# find_package(build_flags REQUIRED)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        sensor_msgs
        pcl_ros
        pcl_conversions
        tf
        )

catkin_package(CATKIN_DEPENDS
        roscpp
        std_msgs
        sensor_msgs
        pcl_ros
        pcl_conversions
        tf
        )

find_package(PCL 1.7 REQUIRED)

# Resolve system dependency on yaml-cpp, which apparently does not
# provide a CMake find_package() module.
find_package(PkgConfig REQUIRED)
pkg_check_modules(YAML_CPP REQUIRED yaml-cpp)
find_path(YAML_CPP_INCLUDE_DIR NAMES yaml_cpp.h PATHS ${YAML_CPP_INCLUDE_DIRS})
find_library(YAML_CPP_LIBRARY NAMES YAML_CPP PATHS ${YAML_CPP_LIBRARY_DIRS})
link_directories(${YAML_CPP_LIBRARY_DIRS})

###########
## Build ##
###########

include_directories(
        ${catkin_INCLUDE_DIRS}
        include
)

SET(CMAKE_CXX_FLAGS "-O2 -g -Wall ${CMAKE_CXX_FLAGS}")

link_directories(${PCL_LIBRARY_DIRS})

# Points Concat filter
add_executable(points_concat_filter
        nodes/points_concat_filter/points_concat_filter.cpp
        )

target_include_directories(points_concat_filter PRIVATE
        ${PCL_INCLUDE_DIRS}
        )

target_link_libraries(points_concat_filter
        ${catkin_LIBRARIES}
        ${PCL_LIBRARIES}
        ${YAML_CPP_LIBRARIES}
        )

add_dependencies(points_concat_filter ${catkin_EXPORTED_TARGETS})






