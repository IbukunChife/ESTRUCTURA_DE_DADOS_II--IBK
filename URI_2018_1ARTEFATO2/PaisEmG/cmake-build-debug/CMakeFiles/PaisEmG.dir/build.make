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
CMAKE_COMMAND = /home/ibk_akaigen/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ibk_akaigen/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PaisEmG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PaisEmG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PaisEmG.dir/flags.make

CMakeFiles/PaisEmG.dir/main.cpp.o: CMakeFiles/PaisEmG.dir/flags.make
CMakeFiles/PaisEmG.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PaisEmG.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PaisEmG.dir/main.cpp.o -c "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/main.cpp"

CMakeFiles/PaisEmG.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PaisEmG.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/main.cpp" > CMakeFiles/PaisEmG.dir/main.cpp.i

CMakeFiles/PaisEmG.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PaisEmG.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/main.cpp" -o CMakeFiles/PaisEmG.dir/main.cpp.s

CMakeFiles/PaisEmG.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PaisEmG.dir/main.cpp.o.requires

CMakeFiles/PaisEmG.dir/main.cpp.o.provides: CMakeFiles/PaisEmG.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PaisEmG.dir/build.make CMakeFiles/PaisEmG.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PaisEmG.dir/main.cpp.o.provides

CMakeFiles/PaisEmG.dir/main.cpp.o.provides.build: CMakeFiles/PaisEmG.dir/main.cpp.o


# Object files for target PaisEmG
PaisEmG_OBJECTS = \
"CMakeFiles/PaisEmG.dir/main.cpp.o"

# External object files for target PaisEmG
PaisEmG_EXTERNAL_OBJECTS =

PaisEmG: CMakeFiles/PaisEmG.dir/main.cpp.o
PaisEmG: CMakeFiles/PaisEmG.dir/build.make
PaisEmG: CMakeFiles/PaisEmG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PaisEmG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PaisEmG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PaisEmG.dir/build: PaisEmG

.PHONY : CMakeFiles/PaisEmG.dir/build

CMakeFiles/PaisEmG.dir/requires: CMakeFiles/PaisEmG.dir/main.cpp.o.requires

.PHONY : CMakeFiles/PaisEmG.dir/requires

CMakeFiles/PaisEmG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PaisEmG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PaisEmG.dir/clean

CMakeFiles/PaisEmG.dir/depend:
	cd "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG" "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG" "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug" "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug" "/home/ibk_akaigen/Documentos/Arquivos GitHub/ESTRUCTURA_DE_DADOS_II--IBK/URI_2018_1ARTEFATO2/PaisEmG/cmake-build-debug/CMakeFiles/PaisEmG.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PaisEmG.dir/depend

