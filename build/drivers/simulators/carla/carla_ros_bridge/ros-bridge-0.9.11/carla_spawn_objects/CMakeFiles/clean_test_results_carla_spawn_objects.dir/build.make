# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python3.8/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.8/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lhq/Projects/PLAuto/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lhq/Projects/PLAuto/build

# Utility rule file for clean_test_results_carla_spawn_objects.

# Include any custom commands dependencies for this target.
include drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/compiler_depend.make

# Include the progress variables for this target.
include drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/progress.make

drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects:
	cd /home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects && /usr/bin/python3 /opt/ros/noetic/share/catkin/cmake/test/remove_test_results.py /home/lhq/Projects/PLAuto/build/test_results/carla_spawn_objects

clean_test_results_carla_spawn_objects: drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects
clean_test_results_carla_spawn_objects: drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/build.make
.PHONY : clean_test_results_carla_spawn_objects

# Rule to build all files generated by this target.
drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/build: clean_test_results_carla_spawn_objects
.PHONY : drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/build

drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/clean:
	cd /home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects && $(CMAKE_COMMAND) -P CMakeFiles/clean_test_results_carla_spawn_objects.dir/cmake_clean.cmake
.PHONY : drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/clean

drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/depend:
	cd /home/lhq/Projects/PLAuto/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lhq/Projects/PLAuto/src /home/lhq/Projects/PLAuto/src/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects /home/lhq/Projects/PLAuto/build /home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects /home/lhq/Projects/PLAuto/build/drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : drivers/simulators/carla/carla_ros_bridge/ros-bridge-0.9.11/carla_spawn_objects/CMakeFiles/clean_test_results_carla_spawn_objects.dir/depend

