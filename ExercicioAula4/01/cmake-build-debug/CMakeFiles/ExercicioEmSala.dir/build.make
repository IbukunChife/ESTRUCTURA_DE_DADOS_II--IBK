# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/IBK/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/IBK/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4203.549/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ExercicioEmSala.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ExercicioEmSala.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ExercicioEmSala.dir/flags.make

CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o: CMakeFiles/ExercicioEmSala.dir/flags.make
CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o: ../ArvBinBusca.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o   -c "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/ArvBinBusca.c"

CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.i"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/ArvBinBusca.c" > CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.i

CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.s"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/ArvBinBusca.c" -o CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.s

CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.requires:

.PHONY : CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.requires

CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.provides: CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.requires
	$(MAKE) -f CMakeFiles/ExercicioEmSala.dir/build.make CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.provides.build
.PHONY : CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.provides

CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.provides.build: CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o


CMakeFiles/ExercicioEmSala.dir/01.c.o: CMakeFiles/ExercicioEmSala.dir/flags.make
CMakeFiles/ExercicioEmSala.dir/01.c.o: ../01.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ExercicioEmSala.dir/01.c.o"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ExercicioEmSala.dir/01.c.o   -c "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/01.c"

CMakeFiles/ExercicioEmSala.dir/01.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ExercicioEmSala.dir/01.c.i"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/01.c" > CMakeFiles/ExercicioEmSala.dir/01.c.i

CMakeFiles/ExercicioEmSala.dir/01.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ExercicioEmSala.dir/01.c.s"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/01.c" -o CMakeFiles/ExercicioEmSala.dir/01.c.s

CMakeFiles/ExercicioEmSala.dir/01.c.o.requires:

.PHONY : CMakeFiles/ExercicioEmSala.dir/01.c.o.requires

CMakeFiles/ExercicioEmSala.dir/01.c.o.provides: CMakeFiles/ExercicioEmSala.dir/01.c.o.requires
	$(MAKE) -f CMakeFiles/ExercicioEmSala.dir/build.make CMakeFiles/ExercicioEmSala.dir/01.c.o.provides.build
.PHONY : CMakeFiles/ExercicioEmSala.dir/01.c.o.provides

CMakeFiles/ExercicioEmSala.dir/01.c.o.provides.build: CMakeFiles/ExercicioEmSala.dir/01.c.o


# Object files for target ExercicioEmSala
ExercicioEmSala_OBJECTS = \
"CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o" \
"CMakeFiles/ExercicioEmSala.dir/01.c.o"

# External object files for target ExercicioEmSala
ExercicioEmSala_EXTERNAL_OBJECTS =

ExercicioEmSala: CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o
ExercicioEmSala: CMakeFiles/ExercicioEmSala.dir/01.c.o
ExercicioEmSala: CMakeFiles/ExercicioEmSala.dir/build.make
ExercicioEmSala: CMakeFiles/ExercicioEmSala.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ExercicioEmSala"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ExercicioEmSala.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ExercicioEmSala.dir/build: ExercicioEmSala

.PHONY : CMakeFiles/ExercicioEmSala.dir/build

CMakeFiles/ExercicioEmSala.dir/requires: CMakeFiles/ExercicioEmSala.dir/ArvBinBusca.c.o.requires
CMakeFiles/ExercicioEmSala.dir/requires: CMakeFiles/ExercicioEmSala.dir/01.c.o.requires

.PHONY : CMakeFiles/ExercicioEmSala.dir/requires

CMakeFiles/ExercicioEmSala.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ExercicioEmSala.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ExercicioEmSala.dir/clean

CMakeFiles/ExercicioEmSala.dir/depend:
	cd "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01" "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01" "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug" "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug" "/home/IBK/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ATIVIDADE/ExercicioAula4/01/cmake-build-debug/CMakeFiles/ExercicioEmSala.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ExercicioEmSala.dir/depend

