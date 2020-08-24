#ifndef _PEER_MANAGER_HPP_
# define _PEER_MANAGER_HPP_

#include "../Networking/network.hpp"

#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class                                   PeerManager // class qui va recevoir tous les peer (ip:port) et qui va determiner auxquels envoyer les requetes
{
private:
    int                                 piece_length;
    int                                 torrent_total_length;
public:
    PeerManager(int piece_length, int torrent_total_length);
    ~PeerManager(){};
    int                                 TryBitfieldPieces(std::string, std::string, const std::string &);
    std::pair<std::string, int>         GetPerfectPeer(std::map<std::string, std::string> &peers, const std::string &info_hash); // function that will return the good peer ip:port
    int                                 DoesThePeerGotAllPieces(std::string); // calcule et compare si le bitfield possede toutes les pieces
    int                                 HexStringToBinary(std::string); // hex to binary
    int                                 CalculatePiecesNeeded(int &);
};

#endif // _PEER_MANAGER_HPP_