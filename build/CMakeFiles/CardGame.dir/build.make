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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/fozua/Desktop/Cards/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/fozua/Desktop/Cards/build

# Include any dependencies generated for this target.
include CMakeFiles/CardGame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CardGame.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CardGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CardGame.dir/flags.make

CMakeFiles/CardGame.dir/main.cpp.o: CMakeFiles/CardGame.dir/flags.make
CMakeFiles/CardGame.dir/main.cpp.o: /Users/fozua/Desktop/Cards/src/main.cpp
CMakeFiles/CardGame.dir/main.cpp.o: CMakeFiles/CardGame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/fozua/Desktop/Cards/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CardGame.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CardGame.dir/main.cpp.o -MF CMakeFiles/CardGame.dir/main.cpp.o.d -o CMakeFiles/CardGame.dir/main.cpp.o -c /Users/fozua/Desktop/Cards/src/main.cpp

CMakeFiles/CardGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CardGame.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/fozua/Desktop/Cards/src/main.cpp > CMakeFiles/CardGame.dir/main.cpp.i

CMakeFiles/CardGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CardGame.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/fozua/Desktop/Cards/src/main.cpp -o CMakeFiles/CardGame.dir/main.cpp.s

# Object files for target CardGame
CardGame_OBJECTS = \
"CMakeFiles/CardGame.dir/main.cpp.o"

# External object files for target CardGame
CardGame_EXTERNAL_OBJECTS =

CardGame: CMakeFiles/CardGame.dir/main.cpp.o
CardGame: CMakeFiles/CardGame.dir/build.make
CardGame: CMakeFiles/CardGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/fozua/Desktop/Cards/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CardGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CardGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CardGame.dir/build: CardGame
.PHONY : CMakeFiles/CardGame.dir/build

CMakeFiles/CardGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CardGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CardGame.dir/clean

CMakeFiles/CardGame.dir/depend:
	cd /Users/fozua/Desktop/Cards/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/fozua/Desktop/Cards/src /Users/fozua/Desktop/Cards/src /Users/fozua/Desktop/Cards/build /Users/fozua/Desktop/Cards/build /Users/fozua/Desktop/Cards/build/CMakeFiles/CardGame.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/CardGame.dir/depend

