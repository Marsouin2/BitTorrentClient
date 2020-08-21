# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marsouin/Project/BitTorrentClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marsouin/Project/BitTorrentClient

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marsouin/Project/BitTorrentClient/CMakeFiles /home/marsouin/Project/BitTorrentClient/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marsouin/Project/BitTorrentClient/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named mylib

# Build rule for target.
mylib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mylib
.PHONY : mylib

# fast build rule for target.
mylib/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/build
.PHONY : mylib/fast

#=============================================================================
# Target rules for targets named torrent_client

# Build rule for target.
torrent_client: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 torrent_client
.PHONY : torrent_client

# fast build rule for target.
torrent_client/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/build
.PHONY : torrent_client/fast

src/BytesManipulator/bytes_manipulator.o: src/BytesManipulator/bytes_manipulator.cpp.o

.PHONY : src/BytesManipulator/bytes_manipulator.o

# target to build an object file
src/BytesManipulator/bytes_manipulator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/BytesManipulator/bytes_manipulator.cpp.o
.PHONY : src/BytesManipulator/bytes_manipulator.cpp.o

src/BytesManipulator/bytes_manipulator.i: src/BytesManipulator/bytes_manipulator.cpp.i

.PHONY : src/BytesManipulator/bytes_manipulator.i

# target to preprocess a source file
src/BytesManipulator/bytes_manipulator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/BytesManipulator/bytes_manipulator.cpp.i
.PHONY : src/BytesManipulator/bytes_manipulator.cpp.i

src/BytesManipulator/bytes_manipulator.s: src/BytesManipulator/bytes_manipulator.cpp.s

.PHONY : src/BytesManipulator/bytes_manipulator.s

# target to generate assembly for a file
src/BytesManipulator/bytes_manipulator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/BytesManipulator/bytes_manipulator.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/BytesManipulator/bytes_manipulator.cpp.s
.PHONY : src/BytesManipulator/bytes_manipulator.cpp.s

src/Networking/network.o: src/Networking/network.cpp.o

.PHONY : src/Networking/network.o

# target to build an object file
src/Networking/network.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/Networking/network.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/Networking/network.cpp.o
.PHONY : src/Networking/network.cpp.o

src/Networking/network.i: src/Networking/network.cpp.i

.PHONY : src/Networking/network.i

# target to preprocess a source file
src/Networking/network.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/Networking/network.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/Networking/network.cpp.i
.PHONY : src/Networking/network.cpp.i

src/Networking/network.s: src/Networking/network.cpp.s

.PHONY : src/Networking/network.s

# target to generate assembly for a file
src/Networking/network.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/Networking/network.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/Networking/network.cpp.s
.PHONY : src/Networking/network.cpp.s

src/PeerManager/peer_manager.o: src/PeerManager/peer_manager.cpp.o

.PHONY : src/PeerManager/peer_manager.o

# target to build an object file
src/PeerManager/peer_manager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/PeerManager/peer_manager.cpp.o
.PHONY : src/PeerManager/peer_manager.cpp.o

src/PeerManager/peer_manager.i: src/PeerManager/peer_manager.cpp.i

.PHONY : src/PeerManager/peer_manager.i

# target to preprocess a source file
src/PeerManager/peer_manager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/PeerManager/peer_manager.cpp.i
.PHONY : src/PeerManager/peer_manager.cpp.i

src/PeerManager/peer_manager.s: src/PeerManager/peer_manager.cpp.s

.PHONY : src/PeerManager/peer_manager.s

# target to generate assembly for a file
src/PeerManager/peer_manager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/PeerManager/peer_manager.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/PeerManager/peer_manager.cpp.s
.PHONY : src/PeerManager/peer_manager.cpp.s

src/TorrentManager/bencode_parser.o: src/TorrentManager/bencode_parser.cpp.o

.PHONY : src/TorrentManager/bencode_parser.o

# target to build an object file
src/TorrentManager/bencode_parser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/TorrentManager/bencode_parser.cpp.o
.PHONY : src/TorrentManager/bencode_parser.cpp.o

src/TorrentManager/bencode_parser.i: src/TorrentManager/bencode_parser.cpp.i

.PHONY : src/TorrentManager/bencode_parser.i

# target to preprocess a source file
src/TorrentManager/bencode_parser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/TorrentManager/bencode_parser.cpp.i
.PHONY : src/TorrentManager/bencode_parser.cpp.i

src/TorrentManager/bencode_parser.s: src/TorrentManager/bencode_parser.cpp.s

.PHONY : src/TorrentManager/bencode_parser.s

# target to generate assembly for a file
src/TorrentManager/bencode_parser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/TorrentManager/bencode_parser.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/TorrentManager/bencode_parser.cpp.s
.PHONY : src/TorrentManager/bencode_parser.cpp.s

src/TorrentManager/manage_torrent_file.o: src/TorrentManager/manage_torrent_file.cpp.o

.PHONY : src/TorrentManager/manage_torrent_file.o

# target to build an object file
src/TorrentManager/manage_torrent_file.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/TorrentManager/manage_torrent_file.cpp.o
.PHONY : src/TorrentManager/manage_torrent_file.cpp.o

src/TorrentManager/manage_torrent_file.i: src/TorrentManager/manage_torrent_file.cpp.i

.PHONY : src/TorrentManager/manage_torrent_file.i

# target to preprocess a source file
src/TorrentManager/manage_torrent_file.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/TorrentManager/manage_torrent_file.cpp.i
.PHONY : src/TorrentManager/manage_torrent_file.cpp.i

src/TorrentManager/manage_torrent_file.s: src/TorrentManager/manage_torrent_file.cpp.s

.PHONY : src/TorrentManager/manage_torrent_file.s

# target to generate assembly for a file
src/TorrentManager/manage_torrent_file.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/TorrentManager/manage_torrent_file.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/TorrentManager/manage_torrent_file.cpp.s
.PHONY : src/TorrentManager/manage_torrent_file.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/main.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/main.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mylib.dir/build.make CMakeFiles/mylib.dir/src/main.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/torrent_client.dir/build.make CMakeFiles/torrent_client.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... mylib"
	@echo "... torrent_client"
	@echo "... src/BytesManipulator/bytes_manipulator.o"
	@echo "... src/BytesManipulator/bytes_manipulator.i"
	@echo "... src/BytesManipulator/bytes_manipulator.s"
	@echo "... src/Networking/network.o"
	@echo "... src/Networking/network.i"
	@echo "... src/Networking/network.s"
	@echo "... src/PeerManager/peer_manager.o"
	@echo "... src/PeerManager/peer_manager.i"
	@echo "... src/PeerManager/peer_manager.s"
	@echo "... src/TorrentManager/bencode_parser.o"
	@echo "... src/TorrentManager/bencode_parser.i"
	@echo "... src/TorrentManager/bencode_parser.s"
	@echo "... src/TorrentManager/manage_torrent_file.o"
	@echo "... src/TorrentManager/manage_torrent_file.i"
	@echo "... src/TorrentManager/manage_torrent_file.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

