cmake_minimum_required(VERSION 3.16)
project(BitTorrentClient)

set(CMAKE_CXX_STANDARD 14)

#set (CMAKE_CXX_FLAGS "-lrt -lm -lasound -ljack -pthread -o")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#set(NETWORKING_HEADER src/header/Networking)
#set(SOUND_MANAGER_HEADER src/header/SoundManager)

#set(HEADER_FILES ${NETWORKING_HEADER}/client.hpp ${NETWORKING_HEADER}/server.hpp ${SOUND_MANAGER_HEADER}/record.hpp ${SOUND_MANAGER_HEADER}/to_listen.hpp)
set(SOURCES src/main.cpp)

#add_library(mylib ${SOURCES} ${HEADER_FILES})
add_executable(torrent_client ${SOURCES})
#target_include_directories(torrent_client PRIVATE ${HEADER_FILES})


#target_link_libraries(my_skype ${CMAKE_SOURCE_DIR}/lib/libportaudio.a)
