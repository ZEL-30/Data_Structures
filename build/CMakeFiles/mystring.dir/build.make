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
include CMakeFiles/mystring.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/mystring.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/mystring.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mystring.dir/flags.make

CMakeFiles/mystring.dir/mystring.cpp.o: CMakeFiles/mystring.dir/flags.make
CMakeFiles/mystring.dir/mystring.cpp.o: ../mystring.cpp
CMakeFiles/mystring.dir/mystring.cpp.o: CMakeFiles/mystring.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mystring.dir/mystring.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mystring.dir/mystring.cpp.o -MF CMakeFiles/mystring.dir/mystring.cpp.o.d -o CMakeFiles/mystring.dir/mystring.cpp.o -c /root/C++项目/Data_Structures/mystring.cpp

CMakeFiles/mystring.dir/mystring.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mystring.dir/mystring.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/C++项目/Data_Structures/mystring.cpp > CMakeFiles/mystring.dir/mystring.cpp.i

CMakeFiles/mystring.dir/mystring.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mystring.dir/mystring.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/C++项目/Data_Structures/mystring.cpp -o CMakeFiles/mystring.dir/mystring.cpp.s

CMakeFiles/mystring.dir/src/MyString.cpp.o: CMakeFiles/mystring.dir/flags.make
CMakeFiles/mystring.dir/src/MyString.cpp.o: ../src/MyString.cpp
CMakeFiles/mystring.dir/src/MyString.cpp.o: CMakeFiles/mystring.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mystring.dir/src/MyString.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/mystring.dir/src/MyString.cpp.o -MF CMakeFiles/mystring.dir/src/MyString.cpp.o.d -o CMakeFiles/mystring.dir/src/MyString.cpp.o -c /root/C++项目/Data_Structures/src/MyString.cpp

CMakeFiles/mystring.dir/src/MyString.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mystring.dir/src/MyString.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/C++项目/Data_Structures/src/MyString.cpp > CMakeFiles/mystring.dir/src/MyString.cpp.i

CMakeFiles/mystring.dir/src/MyString.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mystring.dir/src/MyString.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/C++项目/Data_Structures/src/MyString.cpp -o CMakeFiles/mystring.dir/src/MyString.cpp.s

# Object files for target mystring
mystring_OBJECTS = \
"CMakeFiles/mystring.dir/mystring.cpp.o" \
"CMakeFiles/mystring.dir/src/MyString.cpp.o"

# External object files for target mystring
mystring_EXTERNAL_OBJECTS =

mystring: CMakeFiles/mystring.dir/mystring.cpp.o
mystring: CMakeFiles/mystring.dir/src/MyString.cpp.o
mystring: CMakeFiles/mystring.dir/build.make
mystring: CMakeFiles/mystring.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/C++项目/Data_Structures/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable mystring"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mystring.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mystring.dir/build: mystring
.PHONY : CMakeFiles/mystring.dir/build

CMakeFiles/mystring.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mystring.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mystring.dir/clean

CMakeFiles/mystring.dir/depend:
	cd /root/C++项目/Data_Structures/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/C++项目/Data_Structures /root/C++项目/Data_Structures /root/C++项目/Data_Structures/build /root/C++项目/Data_Structures/build /root/C++项目/Data_Structures/build/CMakeFiles/mystring.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mystring.dir/depend
