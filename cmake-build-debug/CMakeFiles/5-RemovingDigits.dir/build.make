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
include CMakeFiles/5-RemovingDigits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5-RemovingDigits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5-RemovingDigits.dir/flags.make

CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.obj: CMakeFiles/5-RemovingDigits.dir/flags.make
CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.obj: ../CSES/3-DynamicProgramming/5-RemovingDigits.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\5-RemovingDigits.dir\CSES\3-DynamicProgramming\5-RemovingDigits.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\CSES\3-DynamicProgramming\5-RemovingDigits.cpp

CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\CSES\3-DynamicProgramming\5-RemovingDigits.cpp > CMakeFiles\5-RemovingDigits.dir\CSES\3-DynamicProgramming\5-RemovingDigits.cpp.i

CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\CSES\3-DynamicProgramming\5-RemovingDigits.cpp -o CMakeFiles\5-RemovingDigits.dir\CSES\3-DynamicProgramming\5-RemovingDigits.cpp.s

# Object files for target 5-RemovingDigits
5__RemovingDigits_OBJECTS = \
"CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.obj"

# External object files for target 5-RemovingDigits
5__RemovingDigits_EXTERNAL_OBJECTS =

5-RemovingDigits.exe: CMakeFiles/5-RemovingDigits.dir/CSES/3-DynamicProgramming/5-RemovingDigits.cpp.obj
5-RemovingDigits.exe: CMakeFiles/5-RemovingDigits.dir/build.make
5-RemovingDigits.exe: CMakeFiles/5-RemovingDigits.dir/linklibs.rsp
5-RemovingDigits.exe: CMakeFiles/5-RemovingDigits.dir/objects1.rsp
5-RemovingDigits.exe: CMakeFiles/5-RemovingDigits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5-RemovingDigits.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\5-RemovingDigits.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5-RemovingDigits.dir/build: 5-RemovingDigits.exe

.PHONY : CMakeFiles/5-RemovingDigits.dir/build

CMakeFiles/5-RemovingDigits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\5-RemovingDigits.dir\cmake_clean.cmake
.PHONY : CMakeFiles/5-RemovingDigits.dir/clean

CMakeFiles/5-RemovingDigits.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\5-RemovingDigits.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5-RemovingDigits.dir/depend
