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
include CMakeFiles/A-HappyXORSadXOR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A-HappyXORSadXOR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A-HappyXORSadXOR.dir/flags.make

CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.obj: CMakeFiles/A-HappyXORSadXOR.dir/flags.make
CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.obj: ../Proco/2021/A-HappyXORSadXOR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\A-HappyXORSadXOR.dir\Proco\2021\A-HappyXORSadXOR.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\Proco\2021\A-HappyXORSadXOR.cpp

CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\Proco\2021\A-HappyXORSadXOR.cpp > CMakeFiles\A-HappyXORSadXOR.dir\Proco\2021\A-HappyXORSadXOR.cpp.i

CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\Proco\2021\A-HappyXORSadXOR.cpp -o CMakeFiles\A-HappyXORSadXOR.dir\Proco\2021\A-HappyXORSadXOR.cpp.s

# Object files for target A-HappyXORSadXOR
A__HappyXORSadXOR_OBJECTS = \
"CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.obj"

# External object files for target A-HappyXORSadXOR
A__HappyXORSadXOR_EXTERNAL_OBJECTS =

A-HappyXORSadXOR.exe: CMakeFiles/A-HappyXORSadXOR.dir/Proco/2021/A-HappyXORSadXOR.cpp.obj
A-HappyXORSadXOR.exe: CMakeFiles/A-HappyXORSadXOR.dir/build.make
A-HappyXORSadXOR.exe: CMakeFiles/A-HappyXORSadXOR.dir/linklibs.rsp
A-HappyXORSadXOR.exe: CMakeFiles/A-HappyXORSadXOR.dir/objects1.rsp
A-HappyXORSadXOR.exe: CMakeFiles/A-HappyXORSadXOR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A-HappyXORSadXOR.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\A-HappyXORSadXOR.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A-HappyXORSadXOR.dir/build: A-HappyXORSadXOR.exe

.PHONY : CMakeFiles/A-HappyXORSadXOR.dir/build

CMakeFiles/A-HappyXORSadXOR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\A-HappyXORSadXOR.dir\cmake_clean.cmake
.PHONY : CMakeFiles/A-HappyXORSadXOR.dir/clean

CMakeFiles/A-HappyXORSadXOR.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\A-HappyXORSadXOR.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A-HappyXORSadXOR.dir/depend

