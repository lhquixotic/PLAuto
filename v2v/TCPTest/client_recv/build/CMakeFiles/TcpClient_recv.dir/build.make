# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sunzengpeng/Downloads/TCPTest/client_recv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunzengpeng/Downloads/TCPTest/client_recv/build

# Include any dependencies generated for this target.
include CMakeFiles/TcpClient_recv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TcpClient_recv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TcpClient_recv.dir/flags.make

CMakeFiles/TcpClient_recv.dir/client_recv.cpp.o: CMakeFiles/TcpClient_recv.dir/flags.make
CMakeFiles/TcpClient_recv.dir/client_recv.cpp.o: ../client_recv.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunzengpeng/Downloads/TCPTest/client_recv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TcpClient_recv.dir/client_recv.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TcpClient_recv.dir/client_recv.cpp.o -c /home/sunzengpeng/Downloads/TCPTest/client_recv/client_recv.cpp

CMakeFiles/TcpClient_recv.dir/client_recv.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpClient_recv.dir/client_recv.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sunzengpeng/Downloads/TCPTest/client_recv/client_recv.cpp > CMakeFiles/TcpClient_recv.dir/client_recv.cpp.i

CMakeFiles/TcpClient_recv.dir/client_recv.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpClient_recv.dir/client_recv.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sunzengpeng/Downloads/TCPTest/client_recv/client_recv.cpp -o CMakeFiles/TcpClient_recv.dir/client_recv.cpp.s

# Object files for target TcpClient_recv
TcpClient_recv_OBJECTS = \
"CMakeFiles/TcpClient_recv.dir/client_recv.cpp.o"

# External object files for target TcpClient_recv
TcpClient_recv_EXTERNAL_OBJECTS =

TcpClient_recv: CMakeFiles/TcpClient_recv.dir/client_recv.cpp.o
TcpClient_recv: CMakeFiles/TcpClient_recv.dir/build.make
TcpClient_recv: CMakeFiles/TcpClient_recv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunzengpeng/Downloads/TCPTest/client_recv/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TcpClient_recv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TcpClient_recv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TcpClient_recv.dir/build: TcpClient_recv

.PHONY : CMakeFiles/TcpClient_recv.dir/build

CMakeFiles/TcpClient_recv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TcpClient_recv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TcpClient_recv.dir/clean

CMakeFiles/TcpClient_recv.dir/depend:
	cd /home/sunzengpeng/Downloads/TCPTest/client_recv/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunzengpeng/Downloads/TCPTest/client_recv /home/sunzengpeng/Downloads/TCPTest/client_recv /home/sunzengpeng/Downloads/TCPTest/client_recv/build /home/sunzengpeng/Downloads/TCPTest/client_recv/build /home/sunzengpeng/Downloads/TCPTest/client_recv/build/CMakeFiles/TcpClient_recv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TcpClient_recv.dir/depend

