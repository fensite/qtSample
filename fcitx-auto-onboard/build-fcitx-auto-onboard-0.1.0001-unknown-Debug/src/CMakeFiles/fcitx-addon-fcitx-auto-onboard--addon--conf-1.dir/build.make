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

# Utility rule file for fcitx-addon-fcitx-auto-onboard--addon--conf-1.

# Include the progress variables for this target.
include src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/progress.make

src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1: src/fcitx-auto-onboard.conf


src/fcitx-auto-onboard.conf: /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src/fcitx-auto-onboard.conf.in
src/fcitx-auto-onboard.conf: /usr/share/cmake/fcitx/fcitx-merge-config.sh
src/fcitx-auto-onboard.conf: /usr/share/cmake/fcitx/fcitx-cmake-helper.sh
src/fcitx-auto-onboard.conf: /usr/lib/x86_64-linux-gnu/fcitx/libexec/fcitx-po-parser
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating fcitx-auto-onboard.conf"
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001 && /usr/bin/cmake -E make_directory /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001 && env _FCITX_MACRO_CMAKE_DIR=/usr/share/cmake/fcitx _FCITX_PO_PARSER_EXECUTABLE=/usr/lib/x86_64-linux-gnu/fcitx/libexec/fcitx-po-parser FCITX_HELPER_CMAKE_CMD=/usr/bin/cmake FCITX_CMAKE_CACHE_BASE=/home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/fcitx_cmake_cache /usr/share/cmake/fcitx/fcitx-cmake-helper.sh --apply-po-merge /usr/share/cmake/fcitx/fcitx-merge-config.sh /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src/fcitx-auto-onboard.conf.in /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src/fcitx-auto-onboard.conf

fcitx-addon-fcitx-auto-onboard--addon--conf-1: src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1
fcitx-addon-fcitx-auto-onboard--addon--conf-1: src/fcitx-auto-onboard.conf
fcitx-addon-fcitx-auto-onboard--addon--conf-1: src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/build.make

.PHONY : fcitx-addon-fcitx-auto-onboard--addon--conf-1

# Rule to build all files generated by this target.
src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/build: fcitx-addon-fcitx-auto-onboard--addon--conf-1

.PHONY : src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/build

src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/clean:
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src && $(CMAKE_COMMAND) -P CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/clean

src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/depend:
	cd /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001 /home/zhaikn/kylin/samples/fcitx-auto-onboard/fcitx-auto-onboard-0.1.0001/src /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src /home/zhaikn/kylin/samples/fcitx-auto-onboard/build-fcitx-auto-onboard-0.1.0001-unknown-Debug/src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/fcitx-addon-fcitx-auto-onboard--addon--conf-1.dir/depend

