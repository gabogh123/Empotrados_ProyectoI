# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1378/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1378/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jsantamaria/CLionProjects/ProjectLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jsantamaria/CLionProjects/ProjectLib/build

# Include any dependencies generated for this target.
include src/CMakeFiles/SmartHomeControl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/SmartHomeControl.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/SmartHomeControl.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/SmartHomeControl.dir/flags.make

src/CMakeFiles/SmartHomeControl.dir/main.c.o: src/CMakeFiles/SmartHomeControl.dir/flags.make
src/CMakeFiles/SmartHomeControl.dir/main.c.o: /home/jsantamaria/CLionProjects/ProjectLib/src/main.c
src/CMakeFiles/SmartHomeControl.dir/main.c.o: src/CMakeFiles/SmartHomeControl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jsantamaria/CLionProjects/ProjectLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/SmartHomeControl.dir/main.c.o"
	cd /home/jsantamaria/CLionProjects/ProjectLib/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/SmartHomeControl.dir/main.c.o -MF CMakeFiles/SmartHomeControl.dir/main.c.o.d -o CMakeFiles/SmartHomeControl.dir/main.c.o -c /home/jsantamaria/CLionProjects/ProjectLib/src/main.c

src/CMakeFiles/SmartHomeControl.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SmartHomeControl.dir/main.c.i"
	cd /home/jsantamaria/CLionProjects/ProjectLib/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jsantamaria/CLionProjects/ProjectLib/src/main.c > CMakeFiles/SmartHomeControl.dir/main.c.i

src/CMakeFiles/SmartHomeControl.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SmartHomeControl.dir/main.c.s"
	cd /home/jsantamaria/CLionProjects/ProjectLib/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jsantamaria/CLionProjects/ProjectLib/src/main.c -o CMakeFiles/SmartHomeControl.dir/main.c.s

# Object files for target SmartHomeControl
SmartHomeControl_OBJECTS = \
"CMakeFiles/SmartHomeControl.dir/main.c.o"

# External object files for target SmartHomeControl
SmartHomeControl_EXTERNAL_OBJECTS =

src/SmartHomeControl: src/CMakeFiles/SmartHomeControl.dir/main.c.o
src/SmartHomeControl: src/CMakeFiles/SmartHomeControl.dir/build.make
src/SmartHomeControl: src/libbiblioteca.a
src/SmartHomeControl: src/CMakeFiles/SmartHomeControl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jsantamaria/CLionProjects/ProjectLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SmartHomeControl"
	cd /home/jsantamaria/CLionProjects/ProjectLib/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SmartHomeControl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/SmartHomeControl.dir/build: src/SmartHomeControl
.PHONY : src/CMakeFiles/SmartHomeControl.dir/build

src/CMakeFiles/SmartHomeControl.dir/clean:
	cd /home/jsantamaria/CLionProjects/ProjectLib/build/src && $(CMAKE_COMMAND) -P CMakeFiles/SmartHomeControl.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/SmartHomeControl.dir/clean

src/CMakeFiles/SmartHomeControl.dir/depend:
	cd /home/jsantamaria/CLionProjects/ProjectLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jsantamaria/CLionProjects/ProjectLib /home/jsantamaria/CLionProjects/ProjectLib/src /home/jsantamaria/CLionProjects/ProjectLib/build /home/jsantamaria/CLionProjects/ProjectLib/build/src /home/jsantamaria/CLionProjects/ProjectLib/build/src/CMakeFiles/SmartHomeControl.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/SmartHomeControl.dir/depend
