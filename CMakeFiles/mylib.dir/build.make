# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/marsouin/Project/BitTorrentClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marsouin/Project/BitTorrentClient

# Include any dependencies generated for this target.
include CMakeFiles/mylib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mylib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mylib.dir/flags.make

CMakeFiles/mylib.dir/src/main.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mylib.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/main.cpp.o -c /home/marsouin/Project/BitTorrentClient/src/main.cpp

CMakeFiles/mylib.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/src/main.cpp > CMakeFiles/mylib.dir/src/main.cpp.i

CMakeFiles/mylib.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/src/main.cpp -o CMakeFiles/mylib.dir/src/main.cpp.s

CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o: src/TorrentManager/manage_torrent_file.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o -c /home/marsouin/Project/BitTorrentClient/src/TorrentManager/manage_torrent_file.cpp

CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/src/TorrentManager/manage_torrent_file.cpp > CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.i

CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/src/TorrentManager/manage_torrent_file.cpp -o CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.s

CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o: src/TorrentManager/bencode_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o -c /home/marsouin/Project/BitTorrentClient/src/TorrentManager/bencode_parser.cpp

CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/src/TorrentManager/bencode_parser.cpp > CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.i

CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/src/TorrentManager/bencode_parser.cpp -o CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.s

CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o: src/BytesManipulator/bytes_manipulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o -c /home/marsouin/Project/BitTorrentClient/src/BytesManipulator/bytes_manipulator.cpp

CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/src/BytesManipulator/bytes_manipulator.cpp > CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.i

CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/src/BytesManipulator/bytes_manipulator.cpp -o CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.s

CMakeFiles/mylib.dir/src/Networking/network.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/Networking/network.cpp.o: src/Networking/network.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mylib.dir/src/Networking/network.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/Networking/network.cpp.o -c /home/marsouin/Project/BitTorrentClient/src/Networking/network.cpp

CMakeFiles/mylib.dir/src/Networking/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/Networking/network.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/src/Networking/network.cpp > CMakeFiles/mylib.dir/src/Networking/network.cpp.i

CMakeFiles/mylib.dir/src/Networking/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/Networking/network.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/src/Networking/network.cpp -o CMakeFiles/mylib.dir/src/Networking/network.cpp.s

CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o: CMakeFiles/mylib.dir/flags.make
CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o: src/PeerManager/peer_manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o -c /home/marsouin/Project/BitTorrentClient/src/PeerManager/peer_manager.cpp

CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marsouin/Project/BitTorrentClient/src/PeerManager/peer_manager.cpp > CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.i

CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marsouin/Project/BitTorrentClient/src/PeerManager/peer_manager.cpp -o CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.s

# Object files for target mylib
mylib_OBJECTS = \
"CMakeFiles/mylib.dir/src/main.cpp.o" \
"CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o" \
"CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o" \
"CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o" \
"CMakeFiles/mylib.dir/src/Networking/network.cpp.o" \
"CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o"

# External object files for target mylib
mylib_EXTERNAL_OBJECTS =

libmylib.a: CMakeFiles/mylib.dir/src/main.cpp.o
libmylib.a: CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o
libmylib.a: CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o
libmylib.a: CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o
libmylib.a: CMakeFiles/mylib.dir/src/Networking/network.cpp.o
libmylib.a: CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o
libmylib.a: CMakeFiles/mylib.dir/build.make
libmylib.a: CMakeFiles/mylib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marsouin/Project/BitTorrentClient/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libmylib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mylib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mylib.dir/build: libmylib.a

.PHONY : CMakeFiles/mylib.dir/build

CMakeFiles/mylib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mylib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mylib.dir/clean

CMakeFiles/mylib.dir/depend:
	cd /home/marsouin/Project/BitTorrentClient && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marsouin/Project/BitTorrentClient /home/marsouin/Project/BitTorrentClient /home/marsouin/Project/BitTorrentClient /home/marsouin/Project/BitTorrentClient /home/marsouin/Project/BitTorrentClient/CMakeFiles/mylib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mylib.dir/depend

