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
include CMakeFiles/BreedCounting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BreedCounting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BreedCounting.dir/flags.make

CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.obj: CMakeFiles/BreedCounting.dir/flags.make
CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.obj: ../2015_Dec/Silver/3-BreedCounting.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BreedCounting.dir\2015_Dec\Silver\3-BreedCounting.cpp.obj -c C:\Users\xiaon\Documents\USACO\2015_Dec\Silver\3-BreedCounting.cpp

CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\USACO\2015_Dec\Silver\3-BreedCounting.cpp > CMakeFiles\BreedCounting.dir\2015_Dec\Silver\3-BreedCounting.cpp.i

CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\USACO\2015_Dec\Silver\3-BreedCounting.cpp -o CMakeFiles\BreedCounting.dir\2015_Dec\Silver\3-BreedCounting.cpp.s

# Object files for target BreedCounting
BreedCounting_OBJECTS = \
"CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.obj"

# External object files for target BreedCounting
BreedCounting_EXTERNAL_OBJECTS =

BreedCounting.exe: CMakeFiles/BreedCounting.dir/2015_Dec/Silver/3-BreedCounting.cpp.obj
BreedCounting.exe: CMakeFiles/BreedCounting.dir/build.make
BreedCounting.exe: CMakeFiles/BreedCounting.dir/linklibs.rsp
BreedCounting.exe: CMakeFiles/BreedCounting.dir/objects1.rsp
BreedCounting.exe: CMakeFiles/BreedCounting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BreedCounting.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BreedCounting.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BreedCounting.dir/build: BreedCounting.exe

.PHONY : CMakeFiles/BreedCounting.dir/build

CMakeFiles/BreedCounting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BreedCounting.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BreedCounting.dir/clean

CMakeFiles/BreedCounting.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\USACO C:\Users\xiaon\Documents\USACO C:\Users\xiaon\Documents\USACO\cmake-build-debug C:\Users\xiaon\Documents\USACO\cmake-build-debug C:\Users\xiaon\Documents\USACO\cmake-build-debug\CMakeFiles\BreedCounting.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BreedCounting.dir/depend

