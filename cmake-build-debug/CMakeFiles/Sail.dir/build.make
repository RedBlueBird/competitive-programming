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
include CMakeFiles/Sail.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Sail.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Sail.dir/flags.make

CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.obj: CMakeFiles/Sail.dir/flags.make
CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.obj: ../A2OJ/1300/Sail.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Sail.dir\A2OJ\1300\Sail.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\A2OJ\1300\Sail.cpp

CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\A2OJ\1300\Sail.cpp > CMakeFiles\Sail.dir\A2OJ\1300\Sail.cpp.i

CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\A2OJ\1300\Sail.cpp -o CMakeFiles\Sail.dir\A2OJ\1300\Sail.cpp.s

# Object files for target Sail
Sail_OBJECTS = \
"CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.obj"

# External object files for target Sail
Sail_EXTERNAL_OBJECTS =

Sail.exe: CMakeFiles/Sail.dir/A2OJ/1300/Sail.cpp.obj
Sail.exe: CMakeFiles/Sail.dir/build.make
Sail.exe: CMakeFiles/Sail.dir/linklibs.rsp
Sail.exe: CMakeFiles/Sail.dir/objects1.rsp
Sail.exe: CMakeFiles/Sail.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Sail.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Sail.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Sail.dir/build: Sail.exe

.PHONY : CMakeFiles/Sail.dir/build

CMakeFiles/Sail.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Sail.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Sail.dir/clean

CMakeFiles/Sail.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\Sail.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Sail.dir/depend

