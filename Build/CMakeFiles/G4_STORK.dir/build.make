# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrewtan/geant4/G4-STORK-1.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrewtan/geant4/G4-STORK-1.0/Build

# Utility rule file for G4_STORK.

# Include the progress variables for this target.
include CMakeFiles/G4_STORK.dir/progress.make

CMakeFiles/G4_STORK: g4stork

G4_STORK: CMakeFiles/G4_STORK
G4_STORK: CMakeFiles/G4_STORK.dir/build.make
.PHONY : G4_STORK

# Rule to build all files generated by this target.
CMakeFiles/G4_STORK.dir/build: G4_STORK
.PHONY : CMakeFiles/G4_STORK.dir/build

CMakeFiles/G4_STORK.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/G4_STORK.dir/cmake_clean.cmake
.PHONY : CMakeFiles/G4_STORK.dir/clean

CMakeFiles/G4_STORK.dir/depend:
	cd /Users/andrewtan/geant4/G4-STORK-1.0/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrewtan/geant4/G4-STORK-1.0 /Users/andrewtan/geant4/G4-STORK-1.0 /Users/andrewtan/geant4/G4-STORK-1.0/Build /Users/andrewtan/geant4/G4-STORK-1.0/Build /Users/andrewtan/geant4/G4-STORK-1.0/Build/CMakeFiles/G4_STORK.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/G4_STORK.dir/depend

