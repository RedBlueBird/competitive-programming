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
include CMakeFiles/PointLocationTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PointLocationTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PointLocationTest.dir/flags.make

CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.obj: CMakeFiles/PointLocationTest.dir/flags.make
CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.obj: ../CSES/9-Geometry/PointLocationTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PointLocationTest.dir\CSES\9-Geometry\PointLocationTest.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\CSES\9-Geometry\PointLocationTest.cpp

CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\CSES\9-Geometry\PointLocationTest.cpp > CMakeFiles\PointLocationTest.dir\CSES\9-Geometry\PointLocationTest.cpp.i

CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\CSES\9-Geometry\PointLocationTest.cpp -o CMakeFiles\PointLocationTest.dir\CSES\9-Geometry\PointLocationTest.cpp.s

# Object files for target PointLocationTest
PointLocationTest_OBJECTS = \
"CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.obj"

# External object files for target PointLocationTest
PointLocationTest_EXTERNAL_OBJECTS =

PointLocationTest.exe: CMakeFiles/PointLocationTest.dir/CSES/9-Geometry/PointLocationTest.cpp.obj
PointLocationTest.exe: CMakeFiles/PointLocationTest.dir/build.make
PointLocationTest.exe: CMakeFiles/PointLocationTest.dir/linklibs.rsp
PointLocationTest.exe: CMakeFiles/PointLocationTest.dir/objects1.rsp
PointLocationTest.exe: CMakeFiles/PointLocationTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PointLocationTest.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PointLocationTest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PointLocationTest.dir/build: PointLocationTest.exe

.PHONY : CMakeFiles/PointLocationTest.dir/build

CMakeFiles/PointLocationTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PointLocationTest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PointLocationTest.dir/clean

CMakeFiles/PointLocationTest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\PointLocationTest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PointLocationTest.dir/depend

