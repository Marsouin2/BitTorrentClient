cmake_minimum_required(VERSION 3.16)
project(BitTorrentClient)

set(CMAKE_CXX_STANDARD 14)

#set (CMAKE_CXX_FLAGS "-lrt -lm -lasound -ljack -pthread -o")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(NETWORKING_HEADER src/Networking)
set(TORRENT_MANAGER_HEADER src/TorrentManager)

set(HEADER_FILES ${TORRENT_MANAGER_HEADER}/manage_torrent_file.hpp ${NETWORKING_HEADER}/network.hpp ${TORRENT_MANAGER_HEADER}/patron_manage_torrent_file.hpp ${NETWORKING_HEADER}/patron_network.hpp src/my_own_exceptions.hpp)
set(SOURCES src/main.cpp ${TORRENT_MANAGER_HEADER}/manage_torrent_file.cpp)

#add_library(mylib ${SOURCES} ${HEADER_FILES})
add_executable(torrent_client ${SOURCES})
target_include_directories(torrent_client PRIVATE ${HEADER_FILES})


#target_link_libraries(my_skype ${CMAKE_SOURCE_DIR}/lib/libportaudio.a)
