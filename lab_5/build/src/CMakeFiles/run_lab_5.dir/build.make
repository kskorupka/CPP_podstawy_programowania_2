# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/podstawy_programowania_2/lab_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/podstawy_programowania_2/lab_5/build

# Utility rule file for run_lab_5.

# Include the progress variables for this target.
include src/CMakeFiles/run_lab_5.dir/progress.make

src/CMakeFiles/run_lab_5: src/lab_5
	cd /home/student/podstawy_programowania_2/lab_5/build/src && ./lab_5

run_lab_5: src/CMakeFiles/run_lab_5
run_lab_5: src/CMakeFiles/run_lab_5.dir/build.make

.PHONY : run_lab_5

# Rule to build all files generated by this target.
src/CMakeFiles/run_lab_5.dir/build: run_lab_5

.PHONY : src/CMakeFiles/run_lab_5.dir/build

src/CMakeFiles/run_lab_5.dir/clean:
	cd /home/student/podstawy_programowania_2/lab_5/build/src && $(CMAKE_COMMAND) -P CMakeFiles/run_lab_5.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/run_lab_5.dir/clean

src/CMakeFiles/run_lab_5.dir/depend:
	cd /home/student/podstawy_programowania_2/lab_5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/podstawy_programowania_2/lab_5 /home/student/podstawy_programowania_2/lab_5/src /home/student/podstawy_programowania_2/lab_5/build /home/student/podstawy_programowania_2/lab_5/build/src /home/student/podstawy_programowania_2/lab_5/build/src/CMakeFiles/run_lab_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/run_lab_5.dir/depend

