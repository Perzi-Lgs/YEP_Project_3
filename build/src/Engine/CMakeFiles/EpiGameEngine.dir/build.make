# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pierre/YEP_Project_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pierre/YEP_Project_3/build

# Include any dependencies generated for this target.
include src/Engine/CMakeFiles/EpiGameEngine.dir/depend.make

# Include the progress variables for this target.
include src/Engine/CMakeFiles/EpiGameEngine.dir/progress.make

# Include the compile flags for this target's objects.
include src/Engine/CMakeFiles/EpiGameEngine.dir/flags.make

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Application.cpp.o: src/Engine/CMakeFiles/EpiGameEngine.dir/flags.make
src/Engine/CMakeFiles/EpiGameEngine.dir/src/Application.cpp.o: ../src/Engine/src/Application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pierre/YEP_Project_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Engine/CMakeFiles/EpiGameEngine.dir/src/Application.cpp.o"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EpiGameEngine.dir/src/Application.cpp.o -c /home/pierre/YEP_Project_3/src/Engine/src/Application.cpp

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EpiGameEngine.dir/src/Application.cpp.i"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pierre/YEP_Project_3/src/Engine/src/Application.cpp > CMakeFiles/EpiGameEngine.dir/src/Application.cpp.i

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EpiGameEngine.dir/src/Application.cpp.s"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pierre/YEP_Project_3/src/Engine/src/Application.cpp -o CMakeFiles/EpiGameEngine.dir/src/Application.cpp.s

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.o: src/Engine/CMakeFiles/EpiGameEngine.dir/flags.make
src/Engine/CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.o: ../src/Engine/src/Settings/Settings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pierre/YEP_Project_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Engine/CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.o"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.o -c /home/pierre/YEP_Project_3/src/Engine/src/Settings/Settings.cpp

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.i"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pierre/YEP_Project_3/src/Engine/src/Settings/Settings.cpp > CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.i

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.s"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pierre/YEP_Project_3/src/Engine/src/Settings/Settings.cpp -o CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.s

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.o: src/Engine/CMakeFiles/EpiGameEngine.dir/flags.make
src/Engine/CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.o: ../src/Engine/src/Scene.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pierre/YEP_Project_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/Engine/CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.o"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.o -c /home/pierre/YEP_Project_3/src/Engine/src/Scene.cpp

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.i"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pierre/YEP_Project_3/src/Engine/src/Scene.cpp > CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.i

src/Engine/CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.s"
	cd /home/pierre/YEP_Project_3/build/src/Engine && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pierre/YEP_Project_3/src/Engine/src/Scene.cpp -o CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.s

# Object files for target EpiGameEngine
EpiGameEngine_OBJECTS = \
"CMakeFiles/EpiGameEngine.dir/src/Application.cpp.o" \
"CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.o" \
"CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.o"

# External object files for target EpiGameEngine
EpiGameEngine_EXTERNAL_OBJECTS =

../lib/libEpiGameEngine.a: src/Engine/CMakeFiles/EpiGameEngine.dir/src/Application.cpp.o
../lib/libEpiGameEngine.a: src/Engine/CMakeFiles/EpiGameEngine.dir/src/Settings/Settings.cpp.o
../lib/libEpiGameEngine.a: src/Engine/CMakeFiles/EpiGameEngine.dir/src/Scene.cpp.o
../lib/libEpiGameEngine.a: src/Engine/CMakeFiles/EpiGameEngine.dir/build.make
../lib/libEpiGameEngine.a: src/Engine/CMakeFiles/EpiGameEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pierre/YEP_Project_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library ../../../lib/libEpiGameEngine.a"
	cd /home/pierre/YEP_Project_3/build/src/Engine && $(CMAKE_COMMAND) -P CMakeFiles/EpiGameEngine.dir/cmake_clean_target.cmake
	cd /home/pierre/YEP_Project_3/build/src/Engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EpiGameEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Engine/CMakeFiles/EpiGameEngine.dir/build: ../lib/libEpiGameEngine.a

.PHONY : src/Engine/CMakeFiles/EpiGameEngine.dir/build

src/Engine/CMakeFiles/EpiGameEngine.dir/clean:
	cd /home/pierre/YEP_Project_3/build/src/Engine && $(CMAKE_COMMAND) -P CMakeFiles/EpiGameEngine.dir/cmake_clean.cmake
.PHONY : src/Engine/CMakeFiles/EpiGameEngine.dir/clean

src/Engine/CMakeFiles/EpiGameEngine.dir/depend:
	cd /home/pierre/YEP_Project_3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pierre/YEP_Project_3 /home/pierre/YEP_Project_3/src/Engine /home/pierre/YEP_Project_3/build /home/pierre/YEP_Project_3/build/src/Engine /home/pierre/YEP_Project_3/build/src/Engine/CMakeFiles/EpiGameEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/Engine/CMakeFiles/EpiGameEngine.dir/depend

