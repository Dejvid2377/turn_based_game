# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/dawid/Pulpit/turn_based_game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dawid/Pulpit/turn_based_game/build

# Include any dependencies generated for this target.
include CMakeFiles/player1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/player1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/player1.dir/flags.make

CMakeFiles/player1.dir/src/player_program.cpp.o: CMakeFiles/player1.dir/flags.make
CMakeFiles/player1.dir/src/player_program.cpp.o: ../src/player_program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/player1.dir/src/player_program.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/player1.dir/src/player_program.cpp.o -c /home/dawid/Pulpit/turn_based_game/src/player_program.cpp

CMakeFiles/player1.dir/src/player_program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/player1.dir/src/player_program.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawid/Pulpit/turn_based_game/src/player_program.cpp > CMakeFiles/player1.dir/src/player_program.cpp.i

CMakeFiles/player1.dir/src/player_program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/player1.dir/src/player_program.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawid/Pulpit/turn_based_game/src/player_program.cpp -o CMakeFiles/player1.dir/src/player_program.cpp.s

# Object files for target player1
player1_OBJECTS = \
"CMakeFiles/player1.dir/src/player_program.cpp.o"

# External object files for target player1
player1_EXTERNAL_OBJECTS =

player1: CMakeFiles/player1.dir/src/player_program.cpp.o
player1: CMakeFiles/player1.dir/build.make
player1: libgame_lib.a
player1: CMakeFiles/player1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable player1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/player1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/player1.dir/build: player1

.PHONY : CMakeFiles/player1.dir/build

CMakeFiles/player1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/player1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/player1.dir/clean

CMakeFiles/player1.dir/depend:
	cd /home/dawid/Pulpit/turn_based_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dawid/Pulpit/turn_based_game /home/dawid/Pulpit/turn_based_game /home/dawid/Pulpit/turn_based_game/build /home/dawid/Pulpit/turn_based_game/build /home/dawid/Pulpit/turn_based_game/build/CMakeFiles/player1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/player1.dir/depend

