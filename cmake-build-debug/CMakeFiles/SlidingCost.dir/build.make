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
include CMakeFiles/SlidingCost.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SlidingCost.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SlidingCost.dir/flags.make

CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.obj: CMakeFiles/SlidingCost.dir/flags.make
CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.obj: ../CSES/2-SortingAndSearching/SlidingCost.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SlidingCost.dir\CSES\2-SortingAndSearching\SlidingCost.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\CSES\2-SortingAndSearching\SlidingCost.cpp

CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\CSES\2-SortingAndSearching\SlidingCost.cpp > CMakeFiles\SlidingCost.dir\CSES\2-SortingAndSearching\SlidingCost.cpp.i

CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\CSES\2-SortingAndSearching\SlidingCost.cpp -o CMakeFiles\SlidingCost.dir\CSES\2-SortingAndSearching\SlidingCost.cpp.s

# Object files for target SlidingCost
SlidingCost_OBJECTS = \
"CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.obj"

# External object files for target SlidingCost
SlidingCost_EXTERNAL_OBJECTS =

SlidingCost.exe: CMakeFiles/SlidingCost.dir/CSES/2-SortingAndSearching/SlidingCost.cpp.obj
SlidingCost.exe: CMakeFiles/SlidingCost.dir/build.make
SlidingCost.exe: CMakeFiles/SlidingCost.dir/linklibs.rsp
SlidingCost.exe: CMakeFiles/SlidingCost.dir/objects1.rsp
SlidingCost.exe: CMakeFiles/SlidingCost.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SlidingCost.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SlidingCost.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SlidingCost.dir/build: SlidingCost.exe

.PHONY : CMakeFiles/SlidingCost.dir/build

CMakeFiles/SlidingCost.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SlidingCost.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SlidingCost.dir/clean

CMakeFiles/SlidingCost.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\SlidingCost.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SlidingCost.dir/depend

