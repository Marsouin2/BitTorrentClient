# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /home/marsouin/Téléchargements/clion-2020.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/marsouin/Téléchargements/clion-2020.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marsouin/Project/BitTorrentClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marsouin/Project/BitTorrentClient/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BitTorrentClient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BitTorrentClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BitTorrentClient.dir/flags.make

CMakeFiles/BitTorrentClient.dir/main.cpp.o: CMakeFiles/BitTorrentClient.dir/flags.make
CMakeFiles/BitTorrentClient.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BitTorrentClient.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BitTorrentClient.dir/main.cpp.o -c /home/marsouin/Project/BitTorrentClient/main.cpp

CMakeFiles/BitTorrentClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BitTorrentClient.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/main.cpp > CMakeFiles/BitTorrentClient.dir/main.cpp.i

CMakeFiles/BitTorrentClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BitTorrentClient.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/main.cpp -o CMakeFiles/BitTorrentClient.dir/main.cpp.s

# Object files for target BitTorrentClient
BitTorrentClient_OBJECTS = \
"CMakeFiles/BitTorrentClient.dir/main.cpp.o"

# External object files for target BitTorrentClient
BitTorrentClient_EXTERNAL_OBJECTS =

BitTorrentClient: CMakeFiles/BitTorrentClient.dir/main.cpp.o
BitTorrentClient: CMakeFiles/BitTorrentClient.dir/build.make
BitTorrentClient: CMakeFiles/BitTorrentClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marsouin/Project/BitTorrentClient/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BitTorrentClient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BitTorrentClient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BitTorrentClient.dir/build: BitTorrentClient

.PHONY : CMakeFiles/BitTorrentClient.dir/build

CMakeFiles/BitTorrentClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BitTorrentClient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BitTorrentClient.dir/clean

CMakeFiles/BitTorrentClient.dir/depend:
	cd /home/marsouin/Project/BitTorrentClient/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marsouin/Project/BitTorrentClient /home/marsouin/Project/BitTorrentClient /home/marsouin/Project/BitTorrentClient/cmake-build-debug /home/marsouin/Project/BitTorrentClient/cmake-build-debug /home/marsouin/Project/BitTorrentClient/cmake-build-debug/CMakeFiles/BitTorrentClient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BitTorrentClient.dir/depend

