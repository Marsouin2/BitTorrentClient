#ifndef MANAGE_TORRENT_FILE_HPP_
#define MANAGE_TORRENT_FILE_HPP_

#include "../BytesManipulator/bytes_manipulator.hpp"
#include "patron_manage_torrent_file.hpp"
#include "../my_own_exceptions.hpp"
#include "bencode_parser.hpp"

class                   ManageTorrentFile : PatronManageTorrentFile
{
private:
    std::string         torrent_filename;
    std::string         torrent_bencode;
    std::string         final_url_request;

public:
    ManageTorrentFile(const std::string &torrent_file);
    ~ManageTorrentFile() {};
    int                 OpenAndRead();
    void                GetBencode() {};
    void                ConstituteFirstTorrentRequest(const std::string, const std::string, const std::string);
    void                GetDecodedBencode(); // call class BencodeParser to decode the encoded parser (the content of the .torrent file)
    const std::string   GetInfoHash();
    std::string         GetFinalUrl() const { return final_url_request; };
    void                SetFinalUrl(const std::string new_final_url_request) { this->final_url_request = new_final_url_request; };
    std::string         GetBencodeKeyContent(std::string const&, std::string const&);
};

#endif // MANAGE_TORRENT_FILE_HPP_