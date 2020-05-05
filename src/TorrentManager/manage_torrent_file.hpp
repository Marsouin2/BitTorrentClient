#include "patron_manage_torrent_file.hpp"

class           ManageTorrentFile : PatronManageTorrentFile
{
private:
    std::string torrent_filename;
public:
    ManageTorrentFile(std::string torrent_file) { this->torrent_filename = torrent_file; };
    ~ManageTorrentFile()
    {};
    void        OpenAndRead()
    {};
    void        GetBencode()
    {};
};