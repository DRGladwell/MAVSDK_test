# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build

# Include any dependencies generated for this target.
include CMakeFiles/modify_plan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/modify_plan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/modify_plan.dir/flags.make

CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.o: CMakeFiles/modify_plan.dir/flags.make
CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.o: ../modify_mission_plan.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.o -c /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/modify_mission_plan.cpp

CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/modify_mission_plan.cpp > CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.i

CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/modify_mission_plan.cpp -o CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.s

# Object files for target modify_plan
modify_plan_OBJECTS = \
"CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.o"

# External object files for target modify_plan
modify_plan_EXTERNAL_OBJECTS =

modify_plan: CMakeFiles/modify_plan.dir/modify_mission_plan.cpp.o
modify_plan: CMakeFiles/modify_plan.dir/build.make
modify_plan: /usr/lib/libmavsdk_action.so.0.37.0
modify_plan: /usr/lib/libmavsdk_mission.so.0.37.0
modify_plan: /usr/lib/libmavsdk_telemetry.so.0.37.0
modify_plan: /usr/lib/libmavsdk.so.0.37.0
modify_plan: CMakeFiles/modify_plan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable modify_plan"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/modify_plan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/modify_plan.dir/build: modify_plan

.PHONY : CMakeFiles/modify_plan.dir/build

CMakeFiles/modify_plan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/modify_plan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/modify_plan.dir/clean

CMakeFiles/modify_plan.dir/depend:
	cd /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build /home/david/visual_studio_projects/UAV_MAVSDK_WORKSPACE_CPP/build/CMakeFiles/modify_plan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/modify_plan.dir/depend
