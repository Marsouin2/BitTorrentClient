cmake_minimum_required(VERSION 3.16)
project(BitTorrentClient)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "-lssl -lcrypto")
#-lasound -ljack

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(NETWORKING_HEADER src/Networking)
set(TORRENT_MANAGER_HEADER src/TorrentManager)
set(BYTES_MANIPULATOR src/BytesManipulator)
set(BENCODING_LIB lib/bencoding)
set(LIBBENCODING lib/)

set(HEADER_FILES
			${TORRENT_MANAGER_HEADER}/manage_torrent_file.hpp
			${NETWORKING_HEADER}/network.hpp
			${TORRENT_MANAGER_HEADER}/patron_manage_torrent_file.hpp
			${BYTES_MANIPULATOR}/bytes_manipulator.hpp
			${NETWORKING_HEADER}/patron_network.hpp
			src/my_own_exceptions.hpp
			${TORRENT_MANAGER_HEADER}/bencode_parser.hpp
			${BENCODING_LIB}/bencoding.h
)

set(SOURCES src/main.cpp ${TORRENT_MANAGER_HEADER}/manage_torrent_file.cpp ${TORRENT_MANAGER_HEADER}/bencode_parser.cpp ${BYTES_MANIPULATOR}/bytes_manipulator.cpp)

add_library(mylib ${SOURCES} ${HEADER_FILES})
add_executable(torrent_client ${SOURCES})
target_include_directories(torrent_client PRIVATE ${HEADER_FILES})


target_link_libraries(torrent_client ${CMAKE_SOURCE_DIR}/lib/libbencoding.a)
