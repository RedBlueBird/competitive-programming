# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\xiaon\Documents\USACO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\xiaon\Documents\USACO\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RestStops.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RestStops.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RestStops.dir/flags.make

CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.obj: CMakeFiles/RestStops.dir/flags.make
CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.obj: ../2018_Feb/Silver/RestStops.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RestStops.dir\2018_Feb\Silver\RestStops.cpp.obj -c C:\Users\xiaon\Documents\USACO\2018_Feb\Silver\RestStops.cpp

CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\USACO\2018_Feb\Silver\RestStops.cpp > CMakeFiles\RestStops.dir\2018_Feb\Silver\RestStops.cpp.i

CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\USACO\2018_Feb\Silver\RestStops.cpp -o CMakeFiles\RestStops.dir\2018_Feb\Silver\RestStops.cpp.s

# Object files for target RestStops
RestStops_OBJECTS = \
"CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.obj"

# External object files for target RestStops
RestStops_EXTERNAL_OBJECTS =

RestStops.exe: CMakeFiles/RestStops.dir/2018_Feb/Silver/RestStops.cpp.obj
RestStops.exe: CMakeFiles/RestStops.dir/build.make
RestStops.exe: CMakeFiles/RestStops.dir/linklibs.rsp
RestStops.exe: CMakeFiles/RestStops.dir/objects1.rsp
RestStops.exe: CMakeFiles/RestStops.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RestStops.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RestStops.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RestStops.dir/build: RestStops.exe

.PHONY : CMakeFiles/RestStops.dir/build

CMakeFiles/RestStops.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RestStops.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RestStops.dir/clean

CMakeFiles/RestStops.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\USACO C:\Users\xiaon\Documents\USACO C:\Users\xiaon\Documents\USACO\cmake-build-debug C:\Users\xiaon\Documents\USACO\cmake-build-debug C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles\RestStops.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RestStops.dir/depend
