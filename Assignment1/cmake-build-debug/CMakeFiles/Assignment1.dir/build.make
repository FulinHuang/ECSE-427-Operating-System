# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment1.dir/flags.make

CMakeFiles/Assignment1.dir/shell.c.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/shell.c.o: ../shell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment1.dir/shell.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment1.dir/shell.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/shell.c

CMakeFiles/Assignment1.dir/shell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment1.dir/shell.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/shell.c > CMakeFiles/Assignment1.dir/shell.c.i

CMakeFiles/Assignment1.dir/shell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment1.dir/shell.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/shell.c -o CMakeFiles/Assignment1.dir/shell.c.s

CMakeFiles/Assignment1.dir/interpreter.c.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/interpreter.c.o: ../interpreter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assignment1.dir/interpreter.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment1.dir/interpreter.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/interpreter.c

CMakeFiles/Assignment1.dir/interpreter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment1.dir/interpreter.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/interpreter.c > CMakeFiles/Assignment1.dir/interpreter.c.i

CMakeFiles/Assignment1.dir/interpreter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment1.dir/interpreter.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/interpreter.c -o CMakeFiles/Assignment1.dir/interpreter.c.s

CMakeFiles/Assignment1.dir/shellmemory.c.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/shellmemory.c.o: ../shellmemory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Assignment1.dir/shellmemory.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment1.dir/shellmemory.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/shellmemory.c

CMakeFiles/Assignment1.dir/shellmemory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment1.dir/shellmemory.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/shellmemory.c > CMakeFiles/Assignment1.dir/shellmemory.c.i

CMakeFiles/Assignment1.dir/shellmemory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment1.dir/shellmemory.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/shellmemory.c -o CMakeFiles/Assignment1.dir/shellmemory.c.s

# Object files for target Assignment1
Assignment1_OBJECTS = \
"CMakeFiles/Assignment1.dir/shell.c.o" \
"CMakeFiles/Assignment1.dir/interpreter.c.o" \
"CMakeFiles/Assignment1.dir/shellmemory.c.o"

# External object files for target Assignment1
Assignment1_EXTERNAL_OBJECTS =

Assignment1: CMakeFiles/Assignment1.dir/shell.c.o
Assignment1: CMakeFiles/Assignment1.dir/interpreter.c.o
Assignment1: CMakeFiles/Assignment1.dir/shellmemory.c.o
Assignment1: CMakeFiles/Assignment1.dir/build.make
Assignment1: CMakeFiles/Assignment1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Assignment1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment1.dir/build: Assignment1

.PHONY : CMakeFiles/Assignment1.dir/build

CMakeFiles/Assignment1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment1.dir/clean

CMakeFiles/Assignment1.dir/depend:
	cd /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1 /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1 /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug /Users/Huang/Desktop/ECSE_427/Assignment/Assignment1/cmake-build-debug/CMakeFiles/Assignment1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment1.dir/depend

