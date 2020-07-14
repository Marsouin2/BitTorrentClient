#include "patron_network.hpp"

#include <boost/array.hpp>
#include <boost/asio.hpp>

class           Network
{
private:

public:
    Network(){};
    ~Network(){};
    void        Connect();
    void        Send();
    void        Receive();
};