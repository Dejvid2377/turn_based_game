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
include CMakeFiles/game_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game_lib.dir/flags.make

CMakeFiles/game_lib.dir/src/unit.cpp.o: CMakeFiles/game_lib.dir/flags.make
CMakeFiles/game_lib.dir/src/unit.cpp.o: ../src/unit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game_lib.dir/src/unit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_lib.dir/src/unit.cpp.o -c /home/dawid/Pulpit/turn_based_game/src/unit.cpp

CMakeFiles/game_lib.dir/src/unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_lib.dir/src/unit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawid/Pulpit/turn_based_game/src/unit.cpp > CMakeFiles/game_lib.dir/src/unit.cpp.i

CMakeFiles/game_lib.dir/src/unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_lib.dir/src/unit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawid/Pulpit/turn_based_game/src/unit.cpp -o CMakeFiles/game_lib.dir/src/unit.cpp.s

CMakeFiles/game_lib.dir/src/unitModel.cpp.o: CMakeFiles/game_lib.dir/flags.make
CMakeFiles/game_lib.dir/src/unitModel.cpp.o: ../src/unitModel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game_lib.dir/src/unitModel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_lib.dir/src/unitModel.cpp.o -c /home/dawid/Pulpit/turn_based_game/src/unitModel.cpp

CMakeFiles/game_lib.dir/src/unitModel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_lib.dir/src/unitModel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawid/Pulpit/turn_based_game/src/unitModel.cpp > CMakeFiles/game_lib.dir/src/unitModel.cpp.i

CMakeFiles/game_lib.dir/src/unitModel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_lib.dir/src/unitModel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawid/Pulpit/turn_based_game/src/unitModel.cpp -o CMakeFiles/game_lib.dir/src/unitModel.cpp.s

CMakeFiles/game_lib.dir/src/unitBase.cpp.o: CMakeFiles/game_lib.dir/flags.make
CMakeFiles/game_lib.dir/src/unitBase.cpp.o: ../src/unitBase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game_lib.dir/src/unitBase.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_lib.dir/src/unitBase.cpp.o -c /home/dawid/Pulpit/turn_based_game/src/unitBase.cpp

CMakeFiles/game_lib.dir/src/unitBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_lib.dir/src/unitBase.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawid/Pulpit/turn_based_game/src/unitBase.cpp > CMakeFiles/game_lib.dir/src/unitBase.cpp.i

CMakeFiles/game_lib.dir/src/unitBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_lib.dir/src/unitBase.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawid/Pulpit/turn_based_game/src/unitBase.cpp -o CMakeFiles/game_lib.dir/src/unitBase.cpp.s

CMakeFiles/game_lib.dir/src/game.cpp.o: CMakeFiles/game_lib.dir/flags.make
CMakeFiles/game_lib.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game_lib.dir/src/game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_lib.dir/src/game.cpp.o -c /home/dawid/Pulpit/turn_based_game/src/game.cpp

CMakeFiles/game_lib.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_lib.dir/src/game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawid/Pulpit/turn_based_game/src/game.cpp > CMakeFiles/game_lib.dir/src/game.cpp.i

CMakeFiles/game_lib.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_lib.dir/src/game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawid/Pulpit/turn_based_game/src/game.cpp -o CMakeFiles/game_lib.dir/src/game.cpp.s

CMakeFiles/game_lib.dir/src/player.cpp.o: CMakeFiles/game_lib.dir/flags.make
CMakeFiles/game_lib.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game_lib.dir/src/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game_lib.dir/src/player.cpp.o -c /home/dawid/Pulpit/turn_based_game/src/player.cpp

CMakeFiles/game_lib.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game_lib.dir/src/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dawid/Pulpit/turn_based_game/src/player.cpp > CMakeFiles/game_lib.dir/src/player.cpp.i

CMakeFiles/game_lib.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game_lib.dir/src/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dawid/Pulpit/turn_based_game/src/player.cpp -o CMakeFiles/game_lib.dir/src/player.cpp.s

# Object files for target game_lib
game_lib_OBJECTS = \
"CMakeFiles/game_lib.dir/src/unit.cpp.o" \
"CMakeFiles/game_lib.dir/src/unitModel.cpp.o" \
"CMakeFiles/game_lib.dir/src/unitBase.cpp.o" \
"CMakeFiles/game_lib.dir/src/game.cpp.o" \
"CMakeFiles/game_lib.dir/src/player.cpp.o"

# External object files for target game_lib
game_lib_EXTERNAL_OBJECTS =

libgame_lib.a: CMakeFiles/game_lib.dir/src/unit.cpp.o
libgame_lib.a: CMakeFiles/game_lib.dir/src/unitModel.cpp.o
libgame_lib.a: CMakeFiles/game_lib.dir/src/unitBase.cpp.o
libgame_lib.a: CMakeFiles/game_lib.dir/src/game.cpp.o
libgame_lib.a: CMakeFiles/game_lib.dir/src/player.cpp.o
libgame_lib.a: CMakeFiles/game_lib.dir/build.make
libgame_lib.a: CMakeFiles/game_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dawid/Pulpit/turn_based_game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libgame_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/game_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game_lib.dir/build: libgame_lib.a

.PHONY : CMakeFiles/game_lib.dir/build

CMakeFiles/game_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game_lib.dir/clean

CMakeFiles/game_lib.dir/depend:
	cd /home/dawid/Pulpit/turn_based_game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dawid/Pulpit/turn_based_game /home/dawid/Pulpit/turn_based_game /home/dawid/Pulpit/turn_based_game/build /home/dawid/Pulpit/turn_based_game/build /home/dawid/Pulpit/turn_based_game/build/CMakeFiles/game_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game_lib.dir/depend

