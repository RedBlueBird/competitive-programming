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
CMAKE_SOURCE_DIR = C:\Users\xiaon\Documents\competitive-programming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1-ComfortableCows.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1-ComfortableCows.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1-ComfortableCows.dir/flags.make

CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.obj: CMakeFiles/1-ComfortableCows.dir/flags.make
CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.obj: ../USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\1-ComfortableCows.dir\USACO\2020-2021\3-Feb\Silver\1-ComfortableCows.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\USACO\2020-2021\3-Feb\Silver\1-ComfortableCows.cpp

CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\USACO\2020-2021\3-Feb\Silver\1-ComfortableCows.cpp > CMakeFiles\1-ComfortableCows.dir\USACO\2020-2021\3-Feb\Silver\1-ComfortableCows.cpp.i

CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\USACO\2020-2021\3-Feb\Silver\1-ComfortableCows.cpp -o CMakeFiles\1-ComfortableCows.dir\USACO\2020-2021\3-Feb\Silver\1-ComfortableCows.cpp.s

# Object files for target 1-ComfortableCows
1__ComfortableCows_OBJECTS = \
"CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.obj"

# External object files for target 1-ComfortableCows
1__ComfortableCows_EXTERNAL_OBJECTS =

1-ComfortableCows.exe: CMakeFiles/1-ComfortableCows.dir/USACO/2020-2021/3-Feb/Silver/1-ComfortableCows.cpp.obj
1-ComfortableCows.exe: CMakeFiles/1-ComfortableCows.dir/build.make
1-ComfortableCows.exe: CMakeFiles/1-ComfortableCows.dir/linklibs.rsp
1-ComfortableCows.exe: CMakeFiles/1-ComfortableCows.dir/objects1.rsp
1-ComfortableCows.exe: CMakeFiles/1-ComfortableCows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1-ComfortableCows.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1-ComfortableCows.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1-ComfortableCows.dir/build: 1-ComfortableCows.exe

.PHONY : CMakeFiles/1-ComfortableCows.dir/build

CMakeFiles/1-ComfortableCows.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1-ComfortableCows.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1-ComfortableCows.dir/clean

CMakeFiles/1-ComfortableCows.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\1-ComfortableCows.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1-ComfortableCows.dir/depend

