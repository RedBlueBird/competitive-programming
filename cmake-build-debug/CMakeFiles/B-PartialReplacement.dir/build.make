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
include CMakeFiles/B-PartialReplacement.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/B-PartialReplacement.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/B-PartialReplacement.dir/flags.make

CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.obj: CMakeFiles/B-PartialReplacement.dir/flags.make
CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.obj: ../Codeforces/Division-3/710/B-PartialReplacement.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\B-PartialReplacement.dir\Codeforces\Division-3\710\B-PartialReplacement.cpp.obj -c C:\Users\xiaon\Documents\competitive-programming\Codeforces\Division-3\710\B-PartialReplacement.cpp

CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\xiaon\Documents\competitive-programming\Codeforces\Division-3\710\B-PartialReplacement.cpp > CMakeFiles\B-PartialReplacement.dir\Codeforces\Division-3\710\B-PartialReplacement.cpp.i

CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\xiaon\Documents\competitive-programming\Codeforces\Division-3\710\B-PartialReplacement.cpp -o CMakeFiles\B-PartialReplacement.dir\Codeforces\Division-3\710\B-PartialReplacement.cpp.s

# Object files for target B-PartialReplacement
B__PartialReplacement_OBJECTS = \
"CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.obj"

# External object files for target B-PartialReplacement
B__PartialReplacement_EXTERNAL_OBJECTS =

B-PartialReplacement.exe: CMakeFiles/B-PartialReplacement.dir/Codeforces/Division-3/710/B-PartialReplacement.cpp.obj
B-PartialReplacement.exe: CMakeFiles/B-PartialReplacement.dir/build.make
B-PartialReplacement.exe: CMakeFiles/B-PartialReplacement.dir/linklibs.rsp
B-PartialReplacement.exe: CMakeFiles/B-PartialReplacement.dir/objects1.rsp
B-PartialReplacement.exe: CMakeFiles/B-PartialReplacement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable B-PartialReplacement.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\B-PartialReplacement.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/B-PartialReplacement.dir/build: B-PartialReplacement.exe

.PHONY : CMakeFiles/B-PartialReplacement.dir/build

CMakeFiles/B-PartialReplacement.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\B-PartialReplacement.dir\cmake_clean.cmake
.PHONY : CMakeFiles/B-PartialReplacement.dir/clean

CMakeFiles/B-PartialReplacement.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug C:\Users\xiaon\Documents\competitive-programming\cmake-build-debug\CMakeFiles\B-PartialReplacement.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B-PartialReplacement.dir/depend

