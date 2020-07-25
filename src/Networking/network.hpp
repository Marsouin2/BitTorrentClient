#include "patron_network.hpp"

#include <iostream>
#include <string>
#include "../include/curl/curl.h"

class           Network
{
private:

public:
    Network(const std::string &url_request);
    ~Network(){};
    void        Connect(const std::string &url_request);
    void        Send();
    void        Receive();
};