#ifndef MANAGE_TORRENT_FILE_HPP_
#define MANAGE_TORRENT_FILE_HPP_

#include "patron_manage_torrent_file.hpp"
#include "../my_own_exceptions.hpp"
#include "bencode_parser.hpp"

class           ManageTorrentFile : PatronManageTorrentFile
{
private:
    std::string torrent_filename;
    std::string torrent_bencode;
public:
    ManageTorrentFile(const std::string &torrent_file);
    ~ManageTorrentFile() {};
    int         OpenAndRead();
    void        GetBencode() {};
    void        GetDecodedBencode(); // call class BencodeParser to decode the encoded parser (the content of the .torrent file)
};

#endif // MANAGE_TORRENT_FILE_HPP_