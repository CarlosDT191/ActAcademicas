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
include src/usuarios/organizador/CMakeFiles/organizador-main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/usuarios/organizador/CMakeFiles/organizador-main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/usuarios/organizador/CMakeFiles/organizador-main.dir/progress.make

# Include the compile flags for this target's objects.
include src/usuarios/organizador/CMakeFiles/organizador-main.dir/flags.make

src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.o: src/usuarios/organizador/CMakeFiles/organizador-main.dir/flags.make
src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.o: /home/carlos19/Desktop/is/ActAcademicas/src/usuarios/organizador/organizador-main.cc
src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.o: src/usuarios/organizador/CMakeFiles/organizador-main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/carlos19/Desktop/is/ActAcademicas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.o"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.o -MF CMakeFiles/organizador-main.dir/organizador-main.cc.o.d -o CMakeFiles/organizador-main.dir/organizador-main.cc.o -c /home/carlos19/Desktop/is/ActAcademicas/src/usuarios/organizador/organizador-main.cc

src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/organizador-main.dir/organizador-main.cc.i"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/carlos19/Desktop/is/ActAcademicas/src/usuarios/organizador/organizador-main.cc > CMakeFiles/organizador-main.dir/organizador-main.cc.i

src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/organizador-main.dir/organizador-main.cc.s"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/carlos19/Desktop/is/ActAcademicas/src/usuarios/organizador/organizador-main.cc -o CMakeFiles/organizador-main.dir/organizador-main.cc.s

# Object files for target organizador-main
organizador__main_OBJECTS = \
"CMakeFiles/organizador-main.dir/organizador-main.cc.o"

# External object files for target organizador-main
organizador__main_EXTERNAL_OBJECTS =

src/usuarios/organizador/organizador-main: src/usuarios/organizador/CMakeFiles/organizador-main.dir/organizador-main.cc.o
src/usuarios/organizador/organizador-main: src/usuarios/organizador/CMakeFiles/organizador-main.dir/build.make
src/usuarios/organizador/organizador-main: src/usuarios/organizador/liborganizador.a
src/usuarios/organizador/organizador-main: src/act_academica/libact_academica.a
src/usuarios/organizador/organizador-main: src/usuarios/usuario/libusuario.a
src/usuarios/organizador/organizador-main: src/usuarios/organizador/CMakeFiles/organizador-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/carlos19/Desktop/is/ActAcademicas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable organizador-main"
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/organizador-main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/usuarios/organizador/CMakeFiles/organizador-main.dir/build: src/usuarios/organizador/organizador-main
.PHONY : src/usuarios/organizador/CMakeFiles/organizador-main.dir/build

src/usuarios/organizador/CMakeFiles/organizador-main.dir/clean:
	cd /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador && $(CMAKE_COMMAND) -P CMakeFiles/organizador-main.dir/cmake_clean.cmake
.PHONY : src/usuarios/organizador/CMakeFiles/organizador-main.dir/clean

src/usuarios/organizador/CMakeFiles/organizador-main.dir/depend:
	cd /home/carlos19/Desktop/is/ActAcademicas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/carlos19/Desktop/is/ActAcademicas /home/carlos19/Desktop/is/ActAcademicas/src/usuarios/organizador /home/carlos19/Desktop/is/ActAcademicas/build /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador /home/carlos19/Desktop/is/ActAcademicas/build/src/usuarios/organizador/CMakeFiles/organizador-main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/usuarios/organizador/CMakeFiles/organizador-main.dir/depend

