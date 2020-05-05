#include "patron_manage_torrent_file.hpp"

class           ManageTorrentFile : PatronManageTorrentFile
{
private:
    std::string torrent_filename;
    std::string torrent_content;
public:
    ManageTorrentFile(const std::string &torrent_file);
    ~ManageTorrentFile() {};
    int         OpenAndRead();
    void        GetBencode() {};
};