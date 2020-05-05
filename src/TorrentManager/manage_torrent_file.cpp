#include "manage_torrent_file.hpp"
#include "../my_own_exceptions.hpp"

ManageTorrentFile::ManageTorrentFile(const std::string &torrent_file) {
    this->torrent_filename = torrent_file;
    this->OpenAndRead();
}

int                         ManageTorrentFile::OpenAndRead() {
    try {
        std::ifstream       file_opened(this->torrent_filename);
        if (file_opened) {
            //std::string     torrent_content((std::istreambuf_iterator<char>(file_opened)), (std::istreambuf_iterator<char>()));
            this->torrent_content.assign((std::istreambuf_iterator<char>(file_opened)), (std::istreambuf_iterator<char>()));
            std::cout << "torrent_content : " << this->torrent_content << std::endl;
        }
        else
            throw(MyOwnExceptions("can't open the torrent, please verify the name."));
    }
    catch (MyOwnExceptions& ex) {
        std::cerr << ex.GetErrorMessage() << std::endl;
        return 84;
    }
    return 0;
}