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
include CMakeFiles/AmusingJoke.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AmusingJoke.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AmusingJoke.dir/flags.make

CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.obj: CMakeFiles/AmusingJoke.dir/flags.make
CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.obj: ../A2OJ/1300/AmusingJoke.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\AmusingJoke.dir\A2OJ\1300\AmusingJoke.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\A2OJ\1300\AmusingJoke.cpp

CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\A2OJ\1300\AmusingJoke.cpp > CMakeFiles\AmusingJoke.dir\A2OJ\1300\AmusingJoke.cpp.i

CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\A2OJ\1300\AmusingJoke.cpp -o CMakeFiles\AmusingJoke.dir\A2OJ\1300\AmusingJoke.cpp.s

# Object files for target AmusingJoke
AmusingJoke_OBJECTS = \
"CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.obj"

# External object files for target AmusingJoke
AmusingJoke_EXTERNAL_OBJECTS =

AmusingJoke.exe: CMakeFiles/AmusingJoke.dir/A2OJ/1300/AmusingJoke.cpp.obj
AmusingJoke.exe: CMakeFiles/AmusingJoke.dir/build.make
AmusingJoke.exe: CMakeFiles/AmusingJoke.dir/linklibs.rsp
AmusingJoke.exe: CMakeFiles/AmusingJoke.dir/objects1.rsp
AmusingJoke.exe: CMakeFiles/AmusingJoke.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AmusingJoke.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AmusingJoke.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AmusingJoke.dir/build: AmusingJoke.exe

.PHONY : CMakeFiles/AmusingJoke.dir/build

CMakeFiles/AmusingJoke.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\AmusingJoke.dir\cmake_clean.cmake
.PHONY : CMakeFiles/AmusingJoke.dir/clean

CMakeFiles/AmusingJoke.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\AmusingJoke.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AmusingJoke.dir/depend
