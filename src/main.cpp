#include "my_own_exceptions.hpp"
#include "TorrentManager/manage_torrent_file.hpp"
#include <iostream>

int                         main(int argc, char **argv) {
    try {
        if (argc != 2) { throw(MyOwnExceptions("Please specify a torrent file : ./torrent_client <file.torrent>")); }
        ManageTorrentFile torrent_manager(argv[1]);
    }
    catch (const MyOwnExceptions& ex) {
        std::cerr << ex.GetErrorMessage() << std::endl;
    }
    return 0;
}