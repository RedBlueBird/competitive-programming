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
include CMakeFiles/1-SleepyCowHerding.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1-SleepyCowHerding.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1-SleepyCowHerding.dir/flags.make

CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.obj: CMakeFiles/1-SleepyCowHerding.dir/flags.make
CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.obj: ../2019_Feb/Silver/1-SleepyCowHerding.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\1-SleepyCowHerding.dir\2019_Feb\Silver\1-SleepyCowHerding.cpp.obj -c C:\Users\xiaon\Documents\USACO\2019_Feb\Silver\1-SleepyCowHerding.cpp

CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\USACO\2019_Feb\Silver\1-SleepyCowHerding.cpp > CMakeFiles\1-SleepyCowHerding.dir\2019_Feb\Silver\1-SleepyCowHerding.cpp.i

CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\USACO\2019_Feb\Silver\1-SleepyCowHerding.cpp -o CMakeFiles\1-SleepyCowHerding.dir\2019_Feb\Silver\1-SleepyCowHerding.cpp.s

# Object files for target 1-SleepyCowHerding
1__SleepyCowHerding_OBJECTS = \
"CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.obj"

# External object files for target 1-SleepyCowHerding
1__SleepyCowHerding_EXTERNAL_OBJECTS =

1-SleepyCowHerding.exe: CMakeFiles/1-SleepyCowHerding.dir/2019_Feb/Silver/1-SleepyCowHerding.cpp.obj
1-SleepyCowHerding.exe: CMakeFiles/1-SleepyCowHerding.dir/build.make
1-SleepyCowHerding.exe: CMakeFiles/1-SleepyCowHerding.dir/linklibs.rsp
1-SleepyCowHerding.exe: CMakeFiles/1-SleepyCowHerding.dir/objects1.rsp
1-SleepyCowHerding.exe: CMakeFiles/1-SleepyCowHerding.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1-SleepyCowHerding.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1-SleepyCowHerding.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1-SleepyCowHerding.dir/build: 1-SleepyCowHerding.exe

.PHONY : CMakeFiles/1-SleepyCowHerding.dir/build

CMakeFiles/1-SleepyCowHerding.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1-SleepyCowHerding.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1-SleepyCowHerding.dir/clean

CMakeFiles/1-SleepyCowHerding.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\USACO C:\Users\xiaon\Documents\USACO C:\Users\xiaon\Documents\USACO\cmake-build-debug C:\Users\xiaon\Documents\USACO\cmake-build-debug C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles\1-SleepyCowHerding.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1-SleepyCowHerding.dir/depend

