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

# Utility rule file for fcitx-modules.target.

# Include the progress variables for this target.
include CMakeFiles/fcitx-modules.target.dir/progress.make

fcitx-modules.target: CMakeFiles/fcitx-modules.target.dir/build.make

.PHONY : fcitx-modules.target

# Rule to build all files generated by this target.
CMakeFiles/fcitx-modules.target.dir/build: fcitx-modules.target

.PHONY : CMakeFiles/fcitx-modules.target.dir/build

CMakeFiles/fcitx-modules.target.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fcitx-modules.target.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fcitx-modules.target.dir/clean

CMakeFiles/fcitx-modules.target.dir/depend:
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001 /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001 /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/CMakeFiles/fcitx-modules.target.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fcitx-modules.target.dir/depend
