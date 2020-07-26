#include "patron_network.hpp"

#include <iostream>
#include <string>
#include "../include/curl/curl.h"
#include "../TorrentManager/bencode_parser.hpp"

class                       Network
{
private:

public:
    Network(const std::string &url_request);
    ~Network(){};
    void                    Connect(const std::string &url_request);
    const std::string       Send(const std::string &message);
    void                    GetPeersIps(const std::string &tracker_bencode);
    void                    FirstTrackerMessage();
    std::string             GetBencodeKeyContent(std::string const&, std::string const&); // duplication
    void                    Receive();
};