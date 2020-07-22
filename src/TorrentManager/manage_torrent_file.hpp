#ifndef MANAGE_TORRENT_FILE_HPP_
#define MANAGE_TORRENT_FILE_HPP_

#include "../BytesManipulator/bytes_manipulator.hpp"
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
    int                 OpenAndRead();
    void                GetBencode() {};
    void                ConstituteFirstTorrentRequest(const std::string, const std::string, const std::string);
    void                GetDecodedBencode(); // call class BencodeParser to decode the encoded parser (the content of the .torrent file)
    const std::string   GetInfoHash();
    std::string         GetBencodeKeyContent(std::string const&, std::string const&);
};

#endif // MANAGE_TORRENT_FILE_HPP_