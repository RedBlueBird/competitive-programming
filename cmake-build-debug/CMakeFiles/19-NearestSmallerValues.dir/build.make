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
include CMakeFiles/19-NearestSmallerValues.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/19-NearestSmallerValues.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/19-NearestSmallerValues.dir/flags.make

CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.obj: CMakeFiles/19-NearestSmallerValues.dir/flags.make
CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.obj: ../CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\19-NearestSmallerValues.dir\CSES\2-SortingAndSearching\19-NearestSmallerValues.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\CSES\2-SortingAndSearching\19-NearestSmallerValues.cpp

CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\CSES\2-SortingAndSearching\19-NearestSmallerValues.cpp > CMakeFiles\19-NearestSmallerValues.dir\CSES\2-SortingAndSearching\19-NearestSmallerValues.cpp.i

CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\CSES\2-SortingAndSearching\19-NearestSmallerValues.cpp -o CMakeFiles\19-NearestSmallerValues.dir\CSES\2-SortingAndSearching\19-NearestSmallerValues.cpp.s

# Object files for target 19-NearestSmallerValues
19__NearestSmallerValues_OBJECTS = \
"CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.obj"

# External object files for target 19-NearestSmallerValues
19__NearestSmallerValues_EXTERNAL_OBJECTS =

19-NearestSmallerValues.exe: CMakeFiles/19-NearestSmallerValues.dir/CSES/2-SortingAndSearching/19-NearestSmallerValues.cpp.obj
19-NearestSmallerValues.exe: CMakeFiles/19-NearestSmallerValues.dir/build.make
19-NearestSmallerValues.exe: CMakeFiles/19-NearestSmallerValues.dir/linklibs.rsp
19-NearestSmallerValues.exe: CMakeFiles/19-NearestSmallerValues.dir/objects1.rsp
19-NearestSmallerValues.exe: CMakeFiles/19-NearestSmallerValues.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 19-NearestSmallerValues.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\19-NearestSmallerValues.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/19-NearestSmallerValues.dir/build: 19-NearestSmallerValues.exe

.PHONY : CMakeFiles/19-NearestSmallerValues.dir/build

CMakeFiles/19-NearestSmallerValues.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\19-NearestSmallerValues.dir\cmake_clean.cmake
.PHONY : CMakeFiles/19-NearestSmallerValues.dir/clean

CMakeFiles/19-NearestSmallerValues.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\19-NearestSmallerValues.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/19-NearestSmallerValues.dir/depend

