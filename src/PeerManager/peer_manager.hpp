#ifndef _PEER_MANAGER_HPP_
# define _PEER_MANAGER_HPP_

#include "../Networking/network.hpp"

#include <iostream>
#include <map>
#include <string>

class                                   PeerManager // class qui va recevoir tous les peer (ip:port) et qui va determiner auxquels envoyer les requetes
{
private:

public:
    PeerManager(std::map<std::string, std::string> &);
    ~PeerManager(){};
    void                                DetermineTheGoodPeer(std::map<std::string, std::string> &);
    void                                TryBitfieldPieces(std::string, std::string);
};

#endif // _PEER_MANAGER_HPP_