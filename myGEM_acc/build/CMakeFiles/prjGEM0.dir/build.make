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
CMAKE_SOURCE_DIR = /home/uosp/geant4_workdir/myGEM_acc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uosp/geant4_workdir/myGEM_acc/build

# Utility rule file for prjGEM0.

# Include the progress variables for this target.
include CMakeFiles/prjGEM0.dir/progress.make

CMakeFiles/prjGEM0: myGEM


prjGEM0: CMakeFiles/prjGEM0
prjGEM0: CMakeFiles/prjGEM0.dir/build.make

.PHONY : prjGEM0

# Rule to build all files generated by this target.
CMakeFiles/prjGEM0.dir/build: prjGEM0

.PHONY : CMakeFiles/prjGEM0.dir/build

CMakeFiles/prjGEM0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prjGEM0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prjGEM0.dir/clean

CMakeFiles/prjGEM0.dir/depend:
	cd /home/uosp/geant4_workdir/myGEM_acc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uosp/geant4_workdir/myGEM_acc /home/uosp/geant4_workdir/myGEM_acc /home/uosp/geant4_workdir/myGEM_acc/build /home/uosp/geant4_workdir/myGEM_acc/build /home/uosp/geant4_workdir/myGEM_acc/build/CMakeFiles/prjGEM0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prjGEM0.dir/depend

