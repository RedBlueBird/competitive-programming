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
include CMakeFiles/B-AlmostRectangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B-AlmostRectangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B-AlmostRectangle.dir/flags.make

CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.obj: CMakeFiles/B-AlmostRectangle.dir/flags.make
CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.obj: ../Codeforces/Division-3/713/B-AlmostRectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B-AlmostRectangle.dir\Codeforces\Division-3\713\B-AlmostRectangle.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\Codeforces\Division-3\713\B-AlmostRectangle.cpp

CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\Codeforces\Division-3\713\B-AlmostRectangle.cpp > CMakeFiles\B-AlmostRectangle.dir\Codeforces\Division-3\713\B-AlmostRectangle.cpp.i

CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\Codeforces\Division-3\713\B-AlmostRectangle.cpp -o CMakeFiles\B-AlmostRectangle.dir\Codeforces\Division-3\713\B-AlmostRectangle.cpp.s

# Object files for target B-AlmostRectangle
B__AlmostRectangle_OBJECTS = \
"CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.obj"

# External object files for target B-AlmostRectangle
B__AlmostRectangle_EXTERNAL_OBJECTS =

B-AlmostRectangle.exe: CMakeFiles/B-AlmostRectangle.dir/Codeforces/Division-3/713/B-AlmostRectangle.cpp.obj
B-AlmostRectangle.exe: CMakeFiles/B-AlmostRectangle.dir/build.make
B-AlmostRectangle.exe: CMakeFiles/B-AlmostRectangle.dir/linklibs.rsp
B-AlmostRectangle.exe: CMakeFiles/B-AlmostRectangle.dir/objects1.rsp
B-AlmostRectangle.exe: CMakeFiles/B-AlmostRectangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B-AlmostRectangle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B-AlmostRectangle.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B-AlmostRectangle.dir/build: B-AlmostRectangle.exe

.PHONY : CMakeFiles/B-AlmostRectangle.dir/build

CMakeFiles/B-AlmostRectangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B-AlmostRectangle.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B-AlmostRectangle.dir/clean

CMakeFiles/B-AlmostRectangle.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\B-AlmostRectangle.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B-AlmostRectangle.dir/depend

