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
CMAKE_COMMAND = /home/WizIbk/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4668.70/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/WizIbk/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.4668.70/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ArvoreRubroNegra.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ArvoreRubroNegra.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ArvoreRubroNegra.dir/flags.make

CMakeFiles/ArvoreRubroNegra.dir/main.c.o: CMakeFiles/ArvoreRubroNegra.dir/flags.make
CMakeFiles/ArvoreRubroNegra.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ArvoreRubroNegra.dir/main.c.o"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ArvoreRubroNegra.dir/main.c.o   -c "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/main.c"

CMakeFiles/ArvoreRubroNegra.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ArvoreRubroNegra.dir/main.c.i"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/main.c" > CMakeFiles/ArvoreRubroNegra.dir/main.c.i

CMakeFiles/ArvoreRubroNegra.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ArvoreRubroNegra.dir/main.c.s"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/main.c" -o CMakeFiles/ArvoreRubroNegra.dir/main.c.s

CMakeFiles/ArvoreRubroNegra.dir/main.c.o.requires:

.PHONY : CMakeFiles/ArvoreRubroNegra.dir/main.c.o.requires

CMakeFiles/ArvoreRubroNegra.dir/main.c.o.provides: CMakeFiles/ArvoreRubroNegra.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/ArvoreRubroNegra.dir/build.make CMakeFiles/ArvoreRubroNegra.dir/main.c.o.provides.build
.PHONY : CMakeFiles/ArvoreRubroNegra.dir/main.c.o.provides

CMakeFiles/ArvoreRubroNegra.dir/main.c.o.provides.build: CMakeFiles/ArvoreRubroNegra.dir/main.c.o


CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o: CMakeFiles/ArvoreRubroNegra.dir/flags.make
CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o: ../RubroNegra.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o   -c "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/RubroNegra.c"

CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.i"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/RubroNegra.c" > CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.i

CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.s"
	/usr/lib64/ccache/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/RubroNegra.c" -o CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.s

CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.requires:

.PHONY : CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.requires

CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.provides: CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.requires
	$(MAKE) -f CMakeFiles/ArvoreRubroNegra.dir/build.make CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.provides.build
.PHONY : CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.provides

CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.provides.build: CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o


# Object files for target ArvoreRubroNegra
ArvoreRubroNegra_OBJECTS = \
"CMakeFiles/ArvoreRubroNegra.dir/main.c.o" \
"CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o"

# External object files for target ArvoreRubroNegra
ArvoreRubroNegra_EXTERNAL_OBJECTS =

ArvoreRubroNegra: CMakeFiles/ArvoreRubroNegra.dir/main.c.o
ArvoreRubroNegra: CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o
ArvoreRubroNegra: CMakeFiles/ArvoreRubroNegra.dir/build.make
ArvoreRubroNegra: CMakeFiles/ArvoreRubroNegra.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ArvoreRubroNegra"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ArvoreRubroNegra.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ArvoreRubroNegra.dir/build: ArvoreRubroNegra

.PHONY : CMakeFiles/ArvoreRubroNegra.dir/build

CMakeFiles/ArvoreRubroNegra.dir/requires: CMakeFiles/ArvoreRubroNegra.dir/main.c.o.requires
CMakeFiles/ArvoreRubroNegra.dir/requires: CMakeFiles/ArvoreRubroNegra.dir/RubroNegra.c.o.requires

.PHONY : CMakeFiles/ArvoreRubroNegra.dir/requires

CMakeFiles/ArvoreRubroNegra.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ArvoreRubroNegra.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ArvoreRubroNegra.dir/clean

CMakeFiles/ArvoreRubroNegra.dir/depend:
	cd "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra" "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra" "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug" "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug" "/home/WizIbk/Dropbox/4eme Semestre/ESTRUTURAS DE DADOS II/ARQUIVOS EXTRAS/ESTRUCTURA_DE_DADOS_II--IBK/ArvoreRubroNegra/cmake-build-debug/CMakeFiles/ArvoreRubroNegra.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ArvoreRubroNegra.dir/depend
