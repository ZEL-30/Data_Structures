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
include CMakeFiles/memcpy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/memcpy.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/memcpy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/memcpy.dir/flags.make

CMakeFiles/memcpy.dir/memcpy.cpp.o: CMakeFiles/memcpy.dir/flags.make
CMakeFiles/memcpy.dir/memcpy.cpp.o: ../memcpy.cpp
CMakeFiles/memcpy.dir/memcpy.cpp.o: CMakeFiles/memcpy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/memcpy.dir/memcpy.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/memcpy.dir/memcpy.cpp.o -MF CMakeFiles/memcpy.dir/memcpy.cpp.o.d -o CMakeFiles/memcpy.dir/memcpy.cpp.o -c /root/C++项目/Data_Structures/memcpy.cpp

CMakeFiles/memcpy.dir/memcpy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/memcpy.dir/memcpy.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/C++项目/Data_Structures/memcpy.cpp > CMakeFiles/memcpy.dir/memcpy.cpp.i

CMakeFiles/memcpy.dir/memcpy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/memcpy.dir/memcpy.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/C++项目/Data_Structures/memcpy.cpp -o CMakeFiles/memcpy.dir/memcpy.cpp.s

# Object files for target memcpy
memcpy_OBJECTS = \
"CMakeFiles/memcpy.dir/memcpy.cpp.o"

# External object files for target memcpy
memcpy_EXTERNAL_OBJECTS =

memcpy: CMakeFiles/memcpy.dir/memcpy.cpp.o
memcpy: CMakeFiles/memcpy.dir/build.make
memcpy: CMakeFiles/memcpy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable memcpy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/memcpy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/memcpy.dir/build: memcpy
.PHONY : CMakeFiles/memcpy.dir/build

CMakeFiles/memcpy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/memcpy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/memcpy.dir/clean

CMakeFiles/memcpy.dir/depend:
	cd /root/C++项目/Data_Structures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/C++项目/Data_Structures /root/C++项目/Data_Structures /root/C++项目/Data_Structures/build /root/C++项目/Data_Structures/build /root/C++项目/Data_Structures/build/CMakeFiles/memcpy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/memcpy.dir/depend
