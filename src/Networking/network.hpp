#ifndef _NETWORK_HPP_
# define _NETWORK_HPP_

#include "patron_network.hpp"

#include <iostream>
#include <string>
#include <map>
#include <arpa/inet.h>
#include <fstream>
#include "../include/curl/curl.h"
#include "../TorrentManager/bencode_parser.hpp"
#include <math.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

class                                   Network
{
private:
    std::vector<std::string>            peers_ip;
    std::map<std::string, std::string>  decimal_peers_ips;
    int                                 sock;
    struct sockaddr_in                  serv_addr;
    //std::string                         handshake_request;

public:
    Network(const std::string &url_request);
    Network();
    ~Network(){};
    void                                Connect(const std::string &url_request);
    const std::string                   Send(const std::string &message);
    void                                GetPeersIps(const std::string &tracker_bencode);
    void                                FirstTrackerMessage();
    std::string                         GetBencodeKeyContent(std::string const&, std::string const&); // duplication
    void                                Receive();
    void                                AddPeersInMap(std::string &ip_key_name, int &port_content) { this->decimal_peers_ips[ip_key_name] = std::to_string(port_content); };
    void                                SendTcpMessage(const std::string &);
    void                                ReadTcpMessage();
    int                                 CreateTcpConnection(const std::string &, const int &);
    void                                GetTrackerIps(const std::string &);
    void                                ConstituteHandshake();
    int                                 HandleTcpConnection(const std::string &, const int &);
    //void                                SetHandshakeRequest(std::string &new_handshake_request) { this->handshake_request = new_handshake_request; };
};

#endif // _NETWORK_HPP_