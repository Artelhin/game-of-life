# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/artelhin/Apps/CMake/cmake-3.15.3-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/artelhin/Apps/CMake/cmake-3.15.3-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/artelhin/msu/projects/game-of-life

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/artelhin/msu/projects/game-of-life/build

# Include any dependencies generated for this target.
include CMakeFiles/GoL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GoL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GoL.dir/flags.make

CMakeFiles/GoL.dir/src/main.cpp.o: CMakeFiles/GoL.dir/flags.make
CMakeFiles/GoL.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artelhin/msu/projects/game-of-life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GoL.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoL.dir/src/main.cpp.o -c /home/artelhin/msu/projects/game-of-life/src/main.cpp

CMakeFiles/GoL.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoL.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artelhin/msu/projects/game-of-life/src/main.cpp > CMakeFiles/GoL.dir/src/main.cpp.i

CMakeFiles/GoL.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoL.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artelhin/msu/projects/game-of-life/src/main.cpp -o CMakeFiles/GoL.dir/src/main.cpp.s

CMakeFiles/GoL.dir/src/utils.cpp.o: CMakeFiles/GoL.dir/flags.make
CMakeFiles/GoL.dir/src/utils.cpp.o: ../src/utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artelhin/msu/projects/game-of-life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/GoL.dir/src/utils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoL.dir/src/utils.cpp.o -c /home/artelhin/msu/projects/game-of-life/src/utils.cpp

CMakeFiles/GoL.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoL.dir/src/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artelhin/msu/projects/game-of-life/src/utils.cpp > CMakeFiles/GoL.dir/src/utils.cpp.i

CMakeFiles/GoL.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoL.dir/src/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artelhin/msu/projects/game-of-life/src/utils.cpp -o CMakeFiles/GoL.dir/src/utils.cpp.s

CMakeFiles/GoL.dir/src/grid.cpp.o: CMakeFiles/GoL.dir/flags.make
CMakeFiles/GoL.dir/src/grid.cpp.o: ../src/grid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artelhin/msu/projects/game-of-life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/GoL.dir/src/grid.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoL.dir/src/grid.cpp.o -c /home/artelhin/msu/projects/game-of-life/src/grid.cpp

CMakeFiles/GoL.dir/src/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoL.dir/src/grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artelhin/msu/projects/game-of-life/src/grid.cpp > CMakeFiles/GoL.dir/src/grid.cpp.i

CMakeFiles/GoL.dir/src/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoL.dir/src/grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artelhin/msu/projects/game-of-life/src/grid.cpp -o CMakeFiles/GoL.dir/src/grid.cpp.s

CMakeFiles/GoL.dir/src/graphics.cpp.o: CMakeFiles/GoL.dir/flags.make
CMakeFiles/GoL.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artelhin/msu/projects/game-of-life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/GoL.dir/src/graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GoL.dir/src/graphics.cpp.o -c /home/artelhin/msu/projects/game-of-life/src/graphics.cpp

CMakeFiles/GoL.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoL.dir/src/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/artelhin/msu/projects/game-of-life/src/graphics.cpp > CMakeFiles/GoL.dir/src/graphics.cpp.i

CMakeFiles/GoL.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoL.dir/src/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/artelhin/msu/projects/game-of-life/src/graphics.cpp -o CMakeFiles/GoL.dir/src/graphics.cpp.s

CMakeFiles/GoL.dir/src/glad.c.o: CMakeFiles/GoL.dir/flags.make
CMakeFiles/GoL.dir/src/glad.c.o: ../src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/artelhin/msu/projects/game-of-life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/GoL.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GoL.dir/src/glad.c.o   -c /home/artelhin/msu/projects/game-of-life/src/glad.c

CMakeFiles/GoL.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GoL.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/artelhin/msu/projects/game-of-life/src/glad.c > CMakeFiles/GoL.dir/src/glad.c.i

CMakeFiles/GoL.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GoL.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/artelhin/msu/projects/game-of-life/src/glad.c -o CMakeFiles/GoL.dir/src/glad.c.s

# Object files for target GoL
GoL_OBJECTS = \
"CMakeFiles/GoL.dir/src/main.cpp.o" \
"CMakeFiles/GoL.dir/src/utils.cpp.o" \
"CMakeFiles/GoL.dir/src/grid.cpp.o" \
"CMakeFiles/GoL.dir/src/graphics.cpp.o" \
"CMakeFiles/GoL.dir/src/glad.c.o"

# External object files for target GoL
GoL_EXTERNAL_OBJECTS =

GoL: CMakeFiles/GoL.dir/src/main.cpp.o
GoL: CMakeFiles/GoL.dir/src/utils.cpp.o
GoL: CMakeFiles/GoL.dir/src/grid.cpp.o
GoL: CMakeFiles/GoL.dir/src/graphics.cpp.o
GoL: CMakeFiles/GoL.dir/src/glad.c.o
GoL: CMakeFiles/GoL.dir/build.make
GoL: /usr/lib/libGL.so
GoL: /usr/lib/libglfw.so.3.3
GoL: CMakeFiles/GoL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/artelhin/msu/projects/game-of-life/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable GoL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GoL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GoL.dir/build: GoL

.PHONY : CMakeFiles/GoL.dir/build

CMakeFiles/GoL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GoL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GoL.dir/clean

CMakeFiles/GoL.dir/depend:
	cd /home/artelhin/msu/projects/game-of-life/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/artelhin/msu/projects/game-of-life /home/artelhin/msu/projects/game-of-life /home/artelhin/msu/projects/game-of-life/build /home/artelhin/msu/projects/game-of-life/build /home/artelhin/msu/projects/game-of-life/build/CMakeFiles/GoL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GoL.dir/depend

