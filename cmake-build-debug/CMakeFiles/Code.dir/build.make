# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/lucas/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lucas/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4284.156/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lucas/Nextcloud/Programming/BackToTheFuture/Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Code.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Code.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Code.dir/flags.make

CMakeFiles/Code.dir/src/main.cpp.o: CMakeFiles/Code.dir/flags.make
CMakeFiles/Code.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Code.dir/src/main.cpp.o"
	/home/lucas/.platformio/packages/toolchain-atmelavr/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Code.dir/src/main.cpp.o -c /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/src/main.cpp

CMakeFiles/Code.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Code.dir/src/main.cpp.i"
	/home/lucas/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/src/main.cpp > CMakeFiles/Code.dir/src/main.cpp.i

CMakeFiles/Code.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Code.dir/src/main.cpp.s"
	/home/lucas/.platformio/packages/toolchain-atmelavr/bin/avr-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/src/main.cpp -o CMakeFiles/Code.dir/src/main.cpp.s

# Object files for target Code
Code_OBJECTS = \
"CMakeFiles/Code.dir/src/main.cpp.o"

# External object files for target Code
Code_EXTERNAL_OBJECTS =

Code: CMakeFiles/Code.dir/src/main.cpp.o
Code: CMakeFiles/Code.dir/build.make
Code: CMakeFiles/Code.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Code"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Code.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Code.dir/build: Code

.PHONY : CMakeFiles/Code.dir/build

CMakeFiles/Code.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Code.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Code.dir/clean

CMakeFiles/Code.dir/depend:
	cd /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lucas/Nextcloud/Programming/BackToTheFuture/Code /home/lucas/Nextcloud/Programming/BackToTheFuture/Code /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug /home/lucas/Nextcloud/Programming/BackToTheFuture/Code/cmake-build-debug/CMakeFiles/Code.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Code.dir/depend

