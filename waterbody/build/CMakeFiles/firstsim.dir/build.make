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
CMAKE_SOURCE_DIR = /home/uosp/geant4_workdir/waterbody

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uosp/geant4_workdir/waterbody/build

# Include any dependencies generated for this target.
include CMakeFiles/firstsim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/firstsim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firstsim.dir/flags.make

CMakeFiles/firstsim.dir/sim.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/sim.cc.o: ../sim.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/firstsim.dir/sim.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/sim.cc.o -c /home/uosp/geant4_workdir/waterbody/sim.cc

CMakeFiles/firstsim.dir/sim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/sim.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/sim.cc > CMakeFiles/firstsim.dir/sim.cc.i

CMakeFiles/firstsim.dir/sim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/sim.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/sim.cc -o CMakeFiles/firstsim.dir/sim.cc.s

CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.o: ../src/MyActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.o -c /home/uosp/geant4_workdir/waterbody/src/MyActionInitialization.cc

CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/src/MyActionInitialization.cc > CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.i

CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/src/MyActionInitialization.cc -o CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.s

CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.o: ../src/MyDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.o -c /home/uosp/geant4_workdir/waterbody/src/MyDetectorConstruction.cc

CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/src/MyDetectorConstruction.cc > CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.i

CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/src/MyDetectorConstruction.cc -o CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.s

CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.o: ../src/MyPhysicsList.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.o -c /home/uosp/geant4_workdir/waterbody/src/MyPhysicsList.cc

CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/src/MyPhysicsList.cc > CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.i

CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/src/MyPhysicsList.cc -o CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.s

CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.o: ../src/MyPrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.o -c /home/uosp/geant4_workdir/waterbody/src/MyPrimaryGeneratorAction.cc

CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/src/MyPrimaryGeneratorAction.cc > CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.i

CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/src/MyPrimaryGeneratorAction.cc -o CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.s

CMakeFiles/firstsim.dir/src/MyRunAction.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/src/MyRunAction.cc.o: ../src/MyRunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/firstsim.dir/src/MyRunAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/src/MyRunAction.cc.o -c /home/uosp/geant4_workdir/waterbody/src/MyRunAction.cc

CMakeFiles/firstsim.dir/src/MyRunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/src/MyRunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/src/MyRunAction.cc > CMakeFiles/firstsim.dir/src/MyRunAction.cc.i

CMakeFiles/firstsim.dir/src/MyRunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/src/MyRunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/src/MyRunAction.cc -o CMakeFiles/firstsim.dir/src/MyRunAction.cc.s

CMakeFiles/firstsim.dir/src/MySD.cc.o: CMakeFiles/firstsim.dir/flags.make
CMakeFiles/firstsim.dir/src/MySD.cc.o: ../src/MySD.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/firstsim.dir/src/MySD.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/firstsim.dir/src/MySD.cc.o -c /home/uosp/geant4_workdir/waterbody/src/MySD.cc

CMakeFiles/firstsim.dir/src/MySD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/firstsim.dir/src/MySD.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uosp/geant4_workdir/waterbody/src/MySD.cc > CMakeFiles/firstsim.dir/src/MySD.cc.i

CMakeFiles/firstsim.dir/src/MySD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/firstsim.dir/src/MySD.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uosp/geant4_workdir/waterbody/src/MySD.cc -o CMakeFiles/firstsim.dir/src/MySD.cc.s

# Object files for target firstsim
firstsim_OBJECTS = \
"CMakeFiles/firstsim.dir/sim.cc.o" \
"CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.o" \
"CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.o" \
"CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.o" \
"CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.o" \
"CMakeFiles/firstsim.dir/src/MyRunAction.cc.o" \
"CMakeFiles/firstsim.dir/src/MySD.cc.o"

# External object files for target firstsim
firstsim_EXTERNAL_OBJECTS =

firstsim: CMakeFiles/firstsim.dir/sim.cc.o
firstsim: CMakeFiles/firstsim.dir/src/MyActionInitialization.cc.o
firstsim: CMakeFiles/firstsim.dir/src/MyDetectorConstruction.cc.o
firstsim: CMakeFiles/firstsim.dir/src/MyPhysicsList.cc.o
firstsim: CMakeFiles/firstsim.dir/src/MyPrimaryGeneratorAction.cc.o
firstsim: CMakeFiles/firstsim.dir/src/MyRunAction.cc.o
firstsim: CMakeFiles/firstsim.dir/src/MySD.cc.o
firstsim: CMakeFiles/firstsim.dir/build.make
firstsim: /home/uosp/Software/geant4-install/lib/libG4Tree.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4FR.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4GMocren.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4visHepRep.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4RayTracer.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4VRML.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4OpenGL.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4gl2ps.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4vis_management.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4modeling.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4interfaces.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4persistency.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4error_propagation.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4readout.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4physicslists.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4tasking.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4parmodels.so
firstsim: /usr/lib/x86_64-linux-gnu/libXmu.so
firstsim: /usr/lib/x86_64-linux-gnu/libXext.so
firstsim: /usr/lib/x86_64-linux-gnu/libXt.so
firstsim: /usr/lib/x86_64-linux-gnu/libICE.so
firstsim: /usr/lib/x86_64-linux-gnu/libSM.so
firstsim: /usr/lib/x86_64-linux-gnu/libX11.so
firstsim: /usr/lib/x86_64-linux-gnu/libGL.so
firstsim: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
firstsim: /usr/lib/x86_64-linux-gnu/libQt5PrintSupport.so.5.12.8
firstsim: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
firstsim: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
firstsim: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
firstsim: /home/uosp/Software/geant4-install/lib/libG4run.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4event.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4tracking.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4processes.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4analysis.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4tools.so
firstsim: /usr/lib/x86_64-linux-gnu/libexpat.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4digits_hits.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4track.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4particles.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4geometry.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4materials.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4zlib.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4graphics_reps.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4intercoms.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4global.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4clhep.so
firstsim: /home/uosp/Software/geant4-install/lib/libG4ptl.so.0.0.2
firstsim: CMakeFiles/firstsim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uosp/geant4_workdir/waterbody/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable firstsim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/firstsim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firstsim.dir/build: firstsim

.PHONY : CMakeFiles/firstsim.dir/build

CMakeFiles/firstsim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/firstsim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/firstsim.dir/clean

CMakeFiles/firstsim.dir/depend:
	cd /home/uosp/geant4_workdir/waterbody/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uosp/geant4_workdir/waterbody /home/uosp/geant4_workdir/waterbody /home/uosp/geant4_workdir/waterbody/build /home/uosp/geant4_workdir/waterbody/build /home/uosp/geant4_workdir/waterbody/build/CMakeFiles/firstsim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firstsim.dir/depend
