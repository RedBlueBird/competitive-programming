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
include CMakeFiles/1-Moocast.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1-Moocast.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1-Moocast.dir/flags.make

CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.obj: CMakeFiles/1-Moocast.dir/flags.make
CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.obj: ../USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\1-Moocast.dir\USACO\2016-2017\1-Dec\Gold\1-Moocast.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\USACO\2016-2017\1-Dec\Gold\1-Moocast.cpp

CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\USACO\2016-2017\1-Dec\Gold\1-Moocast.cpp > CMakeFiles\1-Moocast.dir\USACO\2016-2017\1-Dec\Gold\1-Moocast.cpp.i

CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\USACO\2016-2017\1-Dec\Gold\1-Moocast.cpp -o CMakeFiles\1-Moocast.dir\USACO\2016-2017\1-Dec\Gold\1-Moocast.cpp.s

# Object files for target 1-Moocast
1__Moocast_OBJECTS = \
"CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.obj"

# External object files for target 1-Moocast
1__Moocast_EXTERNAL_OBJECTS =

1-Moocast.exe: CMakeFiles/1-Moocast.dir/USACO/2016-2017/1-Dec/Gold/1-Moocast.cpp.obj
1-Moocast.exe: CMakeFiles/1-Moocast.dir/build.make
1-Moocast.exe: CMakeFiles/1-Moocast.dir/linklibs.rsp
1-Moocast.exe: CMakeFiles/1-Moocast.dir/objects1.rsp
1-Moocast.exe: CMakeFiles/1-Moocast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1-Moocast.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1-Moocast.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1-Moocast.dir/build: 1-Moocast.exe

.PHONY : CMakeFiles/1-Moocast.dir/build

CMakeFiles/1-Moocast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1-Moocast.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1-Moocast.dir/clean

CMakeFiles/1-Moocast.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\1-Moocast.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1-Moocast.dir/depend

