# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/C++项目/Data_Structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/C++项目/Data_Structures/build

# Include any dependencies generated for this target.
include CMakeFiles/seqlist2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/seqlist2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/seqlist2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/seqlist2.dir/flags.make

CMakeFiles/seqlist2.dir/seqlist2.cpp.o: CMakeFiles/seqlist2.dir/flags.make
CMakeFiles/seqlist2.dir/seqlist2.cpp.o: ../seqlist2.cpp
CMakeFiles/seqlist2.dir/seqlist2.cpp.o: CMakeFiles/seqlist2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/seqlist2.dir/seqlist2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/seqlist2.dir/seqlist2.cpp.o -MF CMakeFiles/seqlist2.dir/seqlist2.cpp.o.d -o CMakeFiles/seqlist2.dir/seqlist2.cpp.o -c /root/C++项目/Data_Structures/seqlist2.cpp

CMakeFiles/seqlist2.dir/seqlist2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/seqlist2.dir/seqlist2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/C++项目/Data_Structures/seqlist2.cpp > CMakeFiles/seqlist2.dir/seqlist2.cpp.i

CMakeFiles/seqlist2.dir/seqlist2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/seqlist2.dir/seqlist2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/C++项目/Data_Structures/seqlist2.cpp -o CMakeFiles/seqlist2.dir/seqlist2.cpp.s

# Object files for target seqlist2
seqlist2_OBJECTS = \
"CMakeFiles/seqlist2.dir/seqlist2.cpp.o"

# External object files for target seqlist2
seqlist2_EXTERNAL_OBJECTS =

seqlist2: CMakeFiles/seqlist2.dir/seqlist2.cpp.o
seqlist2: CMakeFiles/seqlist2.dir/build.make
seqlist2: CMakeFiles/seqlist2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable seqlist2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/seqlist2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/seqlist2.dir/build: seqlist2
.PHONY : CMakeFiles/seqlist2.dir/build

CMakeFiles/seqlist2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/seqlist2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/seqlist2.dir/clean

CMakeFiles/seqlist2.dir/depend:
	cd /root/C++项目/Data_Structures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/C++项目/Data_Structures /root/C++项目/Data_Structures /root/C++项目/Data_Structures/build /root/C++项目/Data_Structures/build /root/C++项目/Data_Structures/build/CMakeFiles/seqlist2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/seqlist2.dir/depend

