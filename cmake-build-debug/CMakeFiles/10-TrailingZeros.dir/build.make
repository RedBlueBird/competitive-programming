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
include CMakeFiles/10-TrailingZeros.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/10-TrailingZeros.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/10-TrailingZeros.dir/flags.make

CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.obj: CMakeFiles/10-TrailingZeros.dir/flags.make
CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.obj: ../CSES/1-IntroductoryProblems/10-TrailingZeros.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\10-TrailingZeros.dir\CSES\1-IntroductoryProblems\10-TrailingZeros.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\CSES\1-IntroductoryProblems\10-TrailingZeros.cpp

CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\CSES\1-IntroductoryProblems\10-TrailingZeros.cpp > CMakeFiles\10-TrailingZeros.dir\CSES\1-IntroductoryProblems\10-TrailingZeros.cpp.i

CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\CSES\1-IntroductoryProblems\10-TrailingZeros.cpp -o CMakeFiles\10-TrailingZeros.dir\CSES\1-IntroductoryProblems\10-TrailingZeros.cpp.s

# Object files for target 10-TrailingZeros
10__TrailingZeros_OBJECTS = \
"CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.obj"

# External object files for target 10-TrailingZeros
10__TrailingZeros_EXTERNAL_OBJECTS =

10-TrailingZeros.exe: CMakeFiles/10-TrailingZeros.dir/CSES/1-IntroductoryProblems/10-TrailingZeros.cpp.obj
10-TrailingZeros.exe: CMakeFiles/10-TrailingZeros.dir/build.make
10-TrailingZeros.exe: CMakeFiles/10-TrailingZeros.dir/linklibs.rsp
10-TrailingZeros.exe: CMakeFiles/10-TrailingZeros.dir/objects1.rsp
10-TrailingZeros.exe: CMakeFiles/10-TrailingZeros.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 10-TrailingZeros.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\10-TrailingZeros.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/10-TrailingZeros.dir/build: 10-TrailingZeros.exe

.PHONY : CMakeFiles/10-TrailingZeros.dir/build

CMakeFiles/10-TrailingZeros.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\10-TrailingZeros.dir\cmake_clean.cmake
.PHONY : CMakeFiles/10-TrailingZeros.dir/clean

CMakeFiles/10-TrailingZeros.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\10-TrailingZeros.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/10-TrailingZeros.dir/depend

