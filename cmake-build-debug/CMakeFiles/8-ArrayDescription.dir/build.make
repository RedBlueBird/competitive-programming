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
include CMakeFiles/8-ArrayDescription.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/8-ArrayDescription.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/8-ArrayDescription.dir/flags.make

CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.obj: CMakeFiles/8-ArrayDescription.dir/flags.make
CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.obj: ../CSES/3-DynamicProgramming/8-ArrayDescription.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\8-ArrayDescription.dir\CSES\3-DynamicProgramming\8-ArrayDescription.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\CSES\3-DynamicProgramming\8-ArrayDescription.cpp

CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\CSES\3-DynamicProgramming\8-ArrayDescription.cpp > CMakeFiles\8-ArrayDescription.dir\CSES\3-DynamicProgramming\8-ArrayDescription.cpp.i

CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\CSES\3-DynamicProgramming\8-ArrayDescription.cpp -o CMakeFiles\8-ArrayDescription.dir\CSES\3-DynamicProgramming\8-ArrayDescription.cpp.s

# Object files for target 8-ArrayDescription
8__ArrayDescription_OBJECTS = \
"CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.obj"

# External object files for target 8-ArrayDescription
8__ArrayDescription_EXTERNAL_OBJECTS =

8-ArrayDescription.exe: CMakeFiles/8-ArrayDescription.dir/CSES/3-DynamicProgramming/8-ArrayDescription.cpp.obj
8-ArrayDescription.exe: CMakeFiles/8-ArrayDescription.dir/build.make
8-ArrayDescription.exe: CMakeFiles/8-ArrayDescription.dir/linklibs.rsp
8-ArrayDescription.exe: CMakeFiles/8-ArrayDescription.dir/objects1.rsp
8-ArrayDescription.exe: CMakeFiles/8-ArrayDescription.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 8-ArrayDescription.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\8-ArrayDescription.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/8-ArrayDescription.dir/build: 8-ArrayDescription.exe

.PHONY : CMakeFiles/8-ArrayDescription.dir/build

CMakeFiles/8-ArrayDescription.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\8-ArrayDescription.dir\cmake_clean.cmake
.PHONY : CMakeFiles/8-ArrayDescription.dir/clean

CMakeFiles/8-ArrayDescription.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\8-ArrayDescription.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/8-ArrayDescription.dir/depend

