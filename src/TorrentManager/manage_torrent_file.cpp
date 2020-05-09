#include "manage_torrent_file.hpp"

ManageTorrentFile::ManageTorrentFile(const std::string &torrent_file) {
    this->torrent_filename = torrent_file;
    this->OpenAndRead();
    this->GetDecodedBencode();
}

void                        ManageTorrentFile::GetDecodedBencode() { // split the bencode string into multiple datas to get exactly what we want
    BencodeParser           bencode_parser(this->torrent_bencode);
}

int                         ManageTorrentFile::OpenAndRead() { // open the torrent and store the content (called bencode) inside a std::string
    try {
        std::ifstream       file_opened(this->torrent_filename);
        if (file_opened) {
            this->torrent_bencode.assign((std::istreambuf_iterator<char>(file_opened)), (std::istreambuf_iterator<char>()));
            //std::cout << "torrent_content : " << this->torrent_bencode << std::endl;
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