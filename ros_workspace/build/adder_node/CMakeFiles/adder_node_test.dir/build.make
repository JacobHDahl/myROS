# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jacob/src/myROS/ros_workspace/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jacob/src/myROS/ros_workspace/build

# Include any dependencies generated for this target.
include adder_node/CMakeFiles/adder_node_test.dir/depend.make

# Include the progress variables for this target.
include adder_node/CMakeFiles/adder_node_test.dir/progress.make

# Include the compile flags for this target's objects.
include adder_node/CMakeFiles/adder_node_test.dir/flags.make

adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o: adder_node/CMakeFiles/adder_node_test.dir/flags.make
adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o: /home/jacob/src/myROS/ros_workspace/src/adder_node/test/adder_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jacob/src/myROS/ros_workspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o"
	cd /home/jacob/src/myROS/ros_workspace/build/adder_node && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o -c /home/jacob/src/myROS/ros_workspace/src/adder_node/test/adder_test.cpp

adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/adder_node_test.dir/test/adder_test.cpp.i"
	cd /home/jacob/src/myROS/ros_workspace/build/adder_node && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jacob/src/myROS/ros_workspace/src/adder_node/test/adder_test.cpp > CMakeFiles/adder_node_test.dir/test/adder_test.cpp.i

adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/adder_node_test.dir/test/adder_test.cpp.s"
	cd /home/jacob/src/myROS/ros_workspace/build/adder_node && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jacob/src/myROS/ros_workspace/src/adder_node/test/adder_test.cpp -o CMakeFiles/adder_node_test.dir/test/adder_test.cpp.s

adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.requires:

.PHONY : adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.requires

adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.provides: adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.requires
	$(MAKE) -f adder_node/CMakeFiles/adder_node_test.dir/build.make adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.provides.build
.PHONY : adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.provides

adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.provides.build: adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o


# Object files for target adder_node_test
adder_node_test_OBJECTS = \
"CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o"

# External object files for target adder_node_test
adder_node_test_EXTERNAL_OBJECTS =

/home/jacob/src/myROS/ros_workspace/devel/lib/adder_node/adder_node_test: adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o
/home/jacob/src/myROS/ros_workspace/devel/lib/adder_node/adder_node_test: adder_node/CMakeFiles/adder_node_test.dir/build.make
/home/jacob/src/myROS/ros_workspace/devel/lib/adder_node/adder_node_test: adder_node/CMakeFiles/adder_node_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jacob/src/myROS/ros_workspace/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/jacob/src/myROS/ros_workspace/devel/lib/adder_node/adder_node_test"
	cd /home/jacob/src/myROS/ros_workspace/build/adder_node && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adder_node_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
adder_node/CMakeFiles/adder_node_test.dir/build: /home/jacob/src/myROS/ros_workspace/devel/lib/adder_node/adder_node_test

.PHONY : adder_node/CMakeFiles/adder_node_test.dir/build

adder_node/CMakeFiles/adder_node_test.dir/requires: adder_node/CMakeFiles/adder_node_test.dir/test/adder_test.cpp.o.requires

.PHONY : adder_node/CMakeFiles/adder_node_test.dir/requires

adder_node/CMakeFiles/adder_node_test.dir/clean:
	cd /home/jacob/src/myROS/ros_workspace/build/adder_node && $(CMAKE_COMMAND) -P CMakeFiles/adder_node_test.dir/cmake_clean.cmake
.PHONY : adder_node/CMakeFiles/adder_node_test.dir/clean

adder_node/CMakeFiles/adder_node_test.dir/depend:
	cd /home/jacob/src/myROS/ros_workspace/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jacob/src/myROS/ros_workspace/src /home/jacob/src/myROS/ros_workspace/src/adder_node /home/jacob/src/myROS/ros_workspace/build /home/jacob/src/myROS/ros_workspace/build/adder_node /home/jacob/src/myROS/ros_workspace/build/adder_node/CMakeFiles/adder_node_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : adder_node/CMakeFiles/adder_node_test.dir/depend

