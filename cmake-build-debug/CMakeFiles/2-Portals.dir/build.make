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
include CMakeFiles/2-Portals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/2-Portals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2-Portals.dir/flags.make

CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.obj: CMakeFiles/2-Portals.dir/flags.make
CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.obj: ../USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\2-Portals.dir\USACO\2020-2021\4-UsOpen\Gold\2-Portals.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\USACO\2020-2021\4-UsOpen\Gold\2-Portals.cpp

CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\USACO\2020-2021\4-UsOpen\Gold\2-Portals.cpp > CMakeFiles\2-Portals.dir\USACO\2020-2021\4-UsOpen\Gold\2-Portals.cpp.i

CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\USACO\2020-2021\4-UsOpen\Gold\2-Portals.cpp -o CMakeFiles\2-Portals.dir\USACO\2020-2021\4-UsOpen\Gold\2-Portals.cpp.s

# Object files for target 2-Portals
2__Portals_OBJECTS = \
"CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.obj"

# External object files for target 2-Portals
2__Portals_EXTERNAL_OBJECTS =

2-Portals.exe: CMakeFiles/2-Portals.dir/USACO/2020-2021/4-UsOpen/Gold/2-Portals.cpp.obj
2-Portals.exe: CMakeFiles/2-Portals.dir/build.make
2-Portals.exe: CMakeFiles/2-Portals.dir/linklibs.rsp
2-Portals.exe: CMakeFiles/2-Portals.dir/objects1.rsp
2-Portals.exe: CMakeFiles/2-Portals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2-Portals.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\2-Portals.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2-Portals.dir/build: 2-Portals.exe

.PHONY : CMakeFiles/2-Portals.dir/build

CMakeFiles/2-Portals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\2-Portals.dir\cmake_clean.cmake
.PHONY : CMakeFiles/2-Portals.dir/clean

CMakeFiles/2-Portals.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\2-Portals.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2-Portals.dir/depend

