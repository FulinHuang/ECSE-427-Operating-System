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
CMAKE_SOURCE_DIR = /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment2.dir/flags.make

CMakeFiles/Assignment2.dir/shell.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/shell.c.o: ../shell.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Assignment2.dir/shell.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/shell.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/shell.c

CMakeFiles/Assignment2.dir/shell.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/shell.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/shell.c > CMakeFiles/Assignment2.dir/shell.c.i

CMakeFiles/Assignment2.dir/shell.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/shell.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/shell.c -o CMakeFiles/Assignment2.dir/shell.c.s

CMakeFiles/Assignment2.dir/interpreter.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/interpreter.c.o: ../interpreter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Assignment2.dir/interpreter.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/interpreter.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/interpreter.c

CMakeFiles/Assignment2.dir/interpreter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/interpreter.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/interpreter.c > CMakeFiles/Assignment2.dir/interpreter.c.i

CMakeFiles/Assignment2.dir/interpreter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/interpreter.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/interpreter.c -o CMakeFiles/Assignment2.dir/interpreter.c.s

CMakeFiles/Assignment2.dir/shellmemory.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/shellmemory.c.o: ../shellmemory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Assignment2.dir/shellmemory.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/shellmemory.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/shellmemory.c

CMakeFiles/Assignment2.dir/shellmemory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/shellmemory.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/shellmemory.c > CMakeFiles/Assignment2.dir/shellmemory.c.i

CMakeFiles/Assignment2.dir/shellmemory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/shellmemory.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/shellmemory.c -o CMakeFiles/Assignment2.dir/shellmemory.c.s

CMakeFiles/Assignment2.dir/ram.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/ram.c.o: ../ram.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Assignment2.dir/ram.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/ram.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/ram.c

CMakeFiles/Assignment2.dir/ram.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/ram.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/ram.c > CMakeFiles/Assignment2.dir/ram.c.i

CMakeFiles/Assignment2.dir/ram.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/ram.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/ram.c -o CMakeFiles/Assignment2.dir/ram.c.s

CMakeFiles/Assignment2.dir/pcb.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/pcb.c.o: ../pcb.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Assignment2.dir/pcb.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/pcb.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/pcb.c

CMakeFiles/Assignment2.dir/pcb.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/pcb.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/pcb.c > CMakeFiles/Assignment2.dir/pcb.c.i

CMakeFiles/Assignment2.dir/pcb.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/pcb.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/pcb.c -o CMakeFiles/Assignment2.dir/pcb.c.s

CMakeFiles/Assignment2.dir/kernel.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/kernel.c.o: ../kernel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Assignment2.dir/kernel.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/kernel.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/kernel.c

CMakeFiles/Assignment2.dir/kernel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/kernel.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/kernel.c > CMakeFiles/Assignment2.dir/kernel.c.i

CMakeFiles/Assignment2.dir/kernel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/kernel.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/kernel.c -o CMakeFiles/Assignment2.dir/kernel.c.s

CMakeFiles/Assignment2.dir/cpu.c.o: CMakeFiles/Assignment2.dir/flags.make
CMakeFiles/Assignment2.dir/cpu.c.o: ../cpu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Assignment2.dir/cpu.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Assignment2.dir/cpu.c.o   -c /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cpu.c

CMakeFiles/Assignment2.dir/cpu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Assignment2.dir/cpu.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cpu.c > CMakeFiles/Assignment2.dir/cpu.c.i

CMakeFiles/Assignment2.dir/cpu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Assignment2.dir/cpu.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cpu.c -o CMakeFiles/Assignment2.dir/cpu.c.s

# Object files for target Assignment2
Assignment2_OBJECTS = \
"CMakeFiles/Assignment2.dir/shell.c.o" \
"CMakeFiles/Assignment2.dir/interpreter.c.o" \
"CMakeFiles/Assignment2.dir/shellmemory.c.o" \
"CMakeFiles/Assignment2.dir/ram.c.o" \
"CMakeFiles/Assignment2.dir/pcb.c.o" \
"CMakeFiles/Assignment2.dir/kernel.c.o" \
"CMakeFiles/Assignment2.dir/cpu.c.o"

# External object files for target Assignment2
Assignment2_EXTERNAL_OBJECTS =

Assignment2: CMakeFiles/Assignment2.dir/shell.c.o
Assignment2: CMakeFiles/Assignment2.dir/interpreter.c.o
Assignment2: CMakeFiles/Assignment2.dir/shellmemory.c.o
Assignment2: CMakeFiles/Assignment2.dir/ram.c.o
Assignment2: CMakeFiles/Assignment2.dir/pcb.c.o
Assignment2: CMakeFiles/Assignment2.dir/kernel.c.o
Assignment2: CMakeFiles/Assignment2.dir/cpu.c.o
Assignment2: CMakeFiles/Assignment2.dir/build.make
Assignment2: CMakeFiles/Assignment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable Assignment2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment2.dir/build: Assignment2

.PHONY : CMakeFiles/Assignment2.dir/build

CMakeFiles/Assignment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment2.dir/clean

CMakeFiles/Assignment2.dir/depend:
	cd /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3 /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3 /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug /Users/Huang/Desktop/ECSE_427/Assignment/Assignment3/cmake-build-debug/CMakeFiles/Assignment2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment2.dir/depend

