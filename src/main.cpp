#include "my_own_exceptions.hpp"
#include "TorrentManager/manage_torrent_file.hpp"
#include "Networking/network.hpp"
#include <iostream>

int                         main(int argc, char **argv) {
    try {
        if (argc != 2) {
	  throw(MyOwnExceptions("Please specify a torrent file : ./torrent_client <file.torrent>"));
	}
        const std::string tempo_arg = argv[1];
        ManageTorrentFile torrent_manager(tempo_arg);
        const std::string url_request = torrent_manager.GetFinalUrl();
        Network             netw(url_request);
    }
    catch (const MyOwnExceptions& ex) {
        std::cerr << ex.GetErrorMessage() << std::endl;
    }
    return 0;
}