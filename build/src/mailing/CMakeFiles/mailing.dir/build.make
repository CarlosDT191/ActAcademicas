# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /snap/cmake/1361/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1361/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/carlos19/Desktop/is/ActAcademicas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/carlos19/Desktop/is/ActAcademicas/build

# Include any dependencies generated for this target.
include src/mailing/CMakeFiles/mailing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/mailing/CMakeFiles/mailing.dir/compiler_depend.make

# Include the progress variables for this target.
include src/mailing/CMakeFiles/mailing.dir/progress.make

# Include the compile flags for this target's objects.
include src/mailing/CMakeFiles/mailing.dir/flags.make

src/mailing/CMakeFiles/mailing.dir/mailing.cc.o: src/mailing/CMakeFiles/mailing.dir/flags.make
src/mailing/CMakeFiles/mailing.dir/mailing.cc.o: /home/carlos19/Desktop/is/ActAcademicas/src/mailing/mailing.cc
src/mailing/CMakeFiles/mailing.dir/mailing.cc.o: src/mailing/CMakeFiles/mailing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/carlos19/Desktop/is/ActAcademicas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/mailing/CMakeFiles/mailing.dir/mailing.cc.o"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/mailing/CMakeFiles/mailing.dir/mailing.cc.o -MF CMakeFiles/mailing.dir/mailing.cc.o.d -o CMakeFiles/mailing.dir/mailing.cc.o -c /home/carlos19/Desktop/is/ActAcademicas/src/mailing/mailing.cc

src/mailing/CMakeFiles/mailing.dir/mailing.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mailing.dir/mailing.cc.i"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carlos19/Desktop/is/ActAcademicas/src/mailing/mailing.cc > CMakeFiles/mailing.dir/mailing.cc.i

src/mailing/CMakeFiles/mailing.dir/mailing.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mailing.dir/mailing.cc.s"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carlos19/Desktop/is/ActAcademicas/src/mailing/mailing.cc -o CMakeFiles/mailing.dir/mailing.cc.s

# Object files for target mailing
mailing_OBJECTS = \
"CMakeFiles/mailing.dir/mailing.cc.o"

# External object files for target mailing
mailing_EXTERNAL_OBJECTS =

src/mailing/libmailing.a: src/mailing/CMakeFiles/mailing.dir/mailing.cc.o
src/mailing/libmailing.a: src/mailing/CMakeFiles/mailing.dir/build.make
src/mailing/libmailing.a: src/mailing/CMakeFiles/mailing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/carlos19/Desktop/is/ActAcademicas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmailing.a"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing && $(CMAKE_COMMAND) -P CMakeFiles/mailing.dir/cmake_clean_target.cmake
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mailing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/mailing/CMakeFiles/mailing.dir/build: src/mailing/libmailing.a
.PHONY : src/mailing/CMakeFiles/mailing.dir/build

src/mailing/CMakeFiles/mailing.dir/clean:
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing && $(CMAKE_COMMAND) -P CMakeFiles/mailing.dir/cmake_clean.cmake
.PHONY : src/mailing/CMakeFiles/mailing.dir/clean

src/mailing/CMakeFiles/mailing.dir/depend:
	cd /home/carlos19/Desktop/is/ActAcademicas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlos19/Desktop/is/ActAcademicas /home/carlos19/Desktop/is/ActAcademicas/src/mailing /home/carlos19/Desktop/is/ActAcademicas/build /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing /home/carlos19/Desktop/is/ActAcademicas/build/src/mailing/CMakeFiles/mailing.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/mailing/CMakeFiles/mailing.dir/depend

