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
CMAKE_SOURCE_DIR = /mnt/hgfs/code/工程/电梯

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/hgfs/code/工程/电梯/build

# Include any dependencies generated for this target.
include CMakeFiles/target.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/target.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/target.dir/flags.make

CMakeFiles/target.dir/src/elevator.o: CMakeFiles/target.dir/flags.make
CMakeFiles/target.dir/src/elevator.o: ../src/elevator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/code/工程/电梯/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/target.dir/src/elevator.o"
	arm-linux-gnueabi-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/target.dir/src/elevator.o -c /mnt/hgfs/code/工程/电梯/src/elevator.cpp

CMakeFiles/target.dir/src/elevator.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/target.dir/src/elevator.i"
	arm-linux-gnueabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/code/工程/电梯/src/elevator.cpp > CMakeFiles/target.dir/src/elevator.i

CMakeFiles/target.dir/src/elevator.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/target.dir/src/elevator.s"
	arm-linux-gnueabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/code/工程/电梯/src/elevator.cpp -o CMakeFiles/target.dir/src/elevator.s

CMakeFiles/target.dir/src/lcd.o: CMakeFiles/target.dir/flags.make
CMakeFiles/target.dir/src/lcd.o: ../src/lcd.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/code/工程/电梯/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/target.dir/src/lcd.o"
	arm-linux-gnueabi-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/target.dir/src/lcd.o -c /mnt/hgfs/code/工程/电梯/src/lcd.cpp

CMakeFiles/target.dir/src/lcd.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/target.dir/src/lcd.i"
	arm-linux-gnueabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/code/工程/电梯/src/lcd.cpp > CMakeFiles/target.dir/src/lcd.i

CMakeFiles/target.dir/src/lcd.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/target.dir/src/lcd.s"
	arm-linux-gnueabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/code/工程/电梯/src/lcd.cpp -o CMakeFiles/target.dir/src/lcd.s

CMakeFiles/target.dir/src/main.o: CMakeFiles/target.dir/flags.make
CMakeFiles/target.dir/src/main.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/hgfs/code/工程/电梯/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/target.dir/src/main.o"
	arm-linux-gnueabi-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/target.dir/src/main.o -c /mnt/hgfs/code/工程/电梯/src/main.cpp

CMakeFiles/target.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/target.dir/src/main.i"
	arm-linux-gnueabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/hgfs/code/工程/电梯/src/main.cpp > CMakeFiles/target.dir/src/main.i

CMakeFiles/target.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/target.dir/src/main.s"
	arm-linux-gnueabi-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/hgfs/code/工程/电梯/src/main.cpp -o CMakeFiles/target.dir/src/main.s

# Object files for target target
target_OBJECTS = \
"CMakeFiles/target.dir/src/elevator.o" \
"CMakeFiles/target.dir/src/lcd.o" \
"CMakeFiles/target.dir/src/main.o"

# External object files for target target
target_EXTERNAL_OBJECTS =

target: CMakeFiles/target.dir/src/elevator.o
target: CMakeFiles/target.dir/src/lcd.o
target: CMakeFiles/target.dir/src/main.o
target: CMakeFiles/target.dir/build.make
target: CMakeFiles/target.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/hgfs/code/工程/电梯/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable target"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/target.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/target.dir/build: target

.PHONY : CMakeFiles/target.dir/build

CMakeFiles/target.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/target.dir/cmake_clean.cmake
.PHONY : CMakeFiles/target.dir/clean

CMakeFiles/target.dir/depend:
	cd /mnt/hgfs/code/工程/电梯/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/hgfs/code/工程/电梯 /mnt/hgfs/code/工程/电梯 /mnt/hgfs/code/工程/电梯/build /mnt/hgfs/code/工程/电梯/build /mnt/hgfs/code/工程/电梯/build/CMakeFiles/target.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/target.dir/depend

