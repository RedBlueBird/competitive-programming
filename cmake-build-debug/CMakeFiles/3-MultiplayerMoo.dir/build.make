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
include CMakeFiles/3-MultiplayerMoo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3-MultiplayerMoo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3-MultiplayerMoo.dir/flags.make

CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.obj: CMakeFiles/3-MultiplayerMoo.dir/flags.make
CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.obj: ../USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\3-MultiplayerMoo.dir\USACO\2017-2018\4-UsOpen\Silver\3-MultiplayerMoo.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\USACO\2017-2018\4-UsOpen\Silver\3-MultiplayerMoo.cpp

CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\USACO\2017-2018\4-UsOpen\Silver\3-MultiplayerMoo.cpp > CMakeFiles\3-MultiplayerMoo.dir\USACO\2017-2018\4-UsOpen\Silver\3-MultiplayerMoo.cpp.i

CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\USACO\2017-2018\4-UsOpen\Silver\3-MultiplayerMoo.cpp -o CMakeFiles\3-MultiplayerMoo.dir\USACO\2017-2018\4-UsOpen\Silver\3-MultiplayerMoo.cpp.s

# Object files for target 3-MultiplayerMoo
3__MultiplayerMoo_OBJECTS = \
"CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.obj"

# External object files for target 3-MultiplayerMoo
3__MultiplayerMoo_EXTERNAL_OBJECTS =

3-MultiplayerMoo.exe: CMakeFiles/3-MultiplayerMoo.dir/USACO/2017-2018/4-UsOpen/Silver/3-MultiplayerMoo.cpp.obj
3-MultiplayerMoo.exe: CMakeFiles/3-MultiplayerMoo.dir/build.make
3-MultiplayerMoo.exe: CMakeFiles/3-MultiplayerMoo.dir/linklibs.rsp
3-MultiplayerMoo.exe: CMakeFiles/3-MultiplayerMoo.dir/objects1.rsp
3-MultiplayerMoo.exe: CMakeFiles/3-MultiplayerMoo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3-MultiplayerMoo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\3-MultiplayerMoo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3-MultiplayerMoo.dir/build: 3-MultiplayerMoo.exe

.PHONY : CMakeFiles/3-MultiplayerMoo.dir/build

CMakeFiles/3-MultiplayerMoo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\3-MultiplayerMoo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/3-MultiplayerMoo.dir/clean

CMakeFiles/3-MultiplayerMoo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\3-MultiplayerMoo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3-MultiplayerMoo.dir/depend

