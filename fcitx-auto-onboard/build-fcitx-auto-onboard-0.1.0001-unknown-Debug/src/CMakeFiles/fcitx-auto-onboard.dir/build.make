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
CMAKE_SOURCE_DIR = /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug

# Include any dependencies generated for this target.
include src/CMakeFiles/fcitx-auto-onboard.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/fcitx-auto-onboard.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/fcitx-auto-onboard.dir/flags.make

src/CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.o: src/CMakeFiles/fcitx-auto-onboard.dir/flags.make
src/CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.o: /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src/auto-onboard.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.o"
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.o   -c /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src/auto-onboard.c

src/CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.i"
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src/auto-onboard.c > CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.i

src/CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.s"
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src/auto-onboard.c -o CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.s

# Object files for target fcitx-auto-onboard
fcitx__auto__onboard_OBJECTS = \
"CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.o"

# External object files for target fcitx-auto-onboard
fcitx__auto__onboard_EXTERNAL_OBJECTS =

src/fcitx-auto-onboard.so: src/CMakeFiles/fcitx-auto-onboard.dir/auto-onboard.c.o
src/fcitx-auto-onboard.so: src/CMakeFiles/fcitx-auto-onboard.dir/build.make
src/fcitx-auto-onboard.so: src/CMakeFiles/fcitx-auto-onboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared module fcitx-auto-onboard.so"
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fcitx-auto-onboard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/fcitx-auto-onboard.dir/build: src/fcitx-auto-onboard.so

.PHONY : src/CMakeFiles/fcitx-auto-onboard.dir/build

src/CMakeFiles/fcitx-auto-onboard.dir/clean:
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src && $(CMAKE_COMMAND) -P CMakeFiles/fcitx-auto-onboard.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/fcitx-auto-onboard.dir/clean

src/CMakeFiles/fcitx-auto-onboard.dir/depend:
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001 /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src/CMakeFiles/fcitx-auto-onboard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/fcitx-auto-onboard.dir/depend
