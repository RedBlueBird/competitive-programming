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
include CMakeFiles/TerrasTextArt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TerrasTextArt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TerrasTextArt.dir/flags.make

CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.obj: CMakeFiles/TerrasTextArt.dir/flags.make
CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.obj: ../TeamsCode/Spring\ 2021/TerrasTextArt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TerrasTextArt.dir\TeamsCode\Spring_2021\TerrasTextArt.cpp.obj -c "C:\Users\xiaon\Documents\competitive-programming\TeamsCode\Spring 2021\TerrasTextArt.cpp"

CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\xiaon\Documents\competitive-programming\TeamsCode\Spring 2021\TerrasTextArt.cpp" > CMakeFiles\TerrasTextArt.dir\TeamsCode\Spring_2021\TerrasTextArt.cpp.i

CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\xiaon\Documents\competitive-programming\TeamsCode\Spring 2021\TerrasTextArt.cpp" -o CMakeFiles\TerrasTextArt.dir\TeamsCode\Spring_2021\TerrasTextArt.cpp.s

# Object files for target TerrasTextArt
TerrasTextArt_OBJECTS = \
"CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.obj"

# External object files for target TerrasTextArt
TerrasTextArt_EXTERNAL_OBJECTS =

TerrasTextArt.exe: CMakeFiles/TerrasTextArt.dir/TeamsCode/Spring_2021/TerrasTextArt.cpp.obj
TerrasTextArt.exe: CMakeFiles/TerrasTextArt.dir/build.make
TerrasTextArt.exe: CMakeFiles/TerrasTextArt.dir/linklibs.rsp
TerrasTextArt.exe: CMakeFiles/TerrasTextArt.dir/objects1.rsp
TerrasTextArt.exe: CMakeFiles/TerrasTextArt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TerrasTextArt.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TerrasTextArt.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TerrasTextArt.dir/build: TerrasTextArt.exe

.PHONY : CMakeFiles/TerrasTextArt.dir/build

CMakeFiles/TerrasTextArt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TerrasTextArt.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TerrasTextArt.dir/clean

CMakeFiles/TerrasTextArt.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\TerrasTextArt.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TerrasTextArt.dir/depend

