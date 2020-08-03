#include "patron_network.hpp"

#include <iostream>
#include <string>
#include <map>
#include <arpa/inet.h>
#include <fstream>
#include "../include/curl/curl.h"
#include "../TorrentManager/bencode_parser.hpp"
#include <math.h>

#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>

class                           Network
{
private:
    std::vector<std::string>    peers_ip;
public:
    Network(const std::string &url_request);
    ~Network(){};
    void                        Connect(const std::string &url_request);
    const std::string           Send(const std::string &message);
    void                        GetPeersIps(const std::string &tracker_bencode);
    void                        FirstTrackerMessage();
    std::string                 GetBencodeKeyContent(std::string const&, std::string const&); // duplication
    void                        Receive();
};