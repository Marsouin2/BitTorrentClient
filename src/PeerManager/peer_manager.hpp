#ifndef _PEER_MANAGER_HPP_
# define _PEER_MANAGER_HPP_

#include "../Networking/network.hpp"

#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <utility>

#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <utility>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class                                   PeerManager // class qui va recevoir tous les peer (ip:port) et qui va determiner auxquels envoyer les requetes
{
private:
    int                                 piece_length;
    int                                 max_piece_length;
    int                                 last_piece_length;
    int                                 number_of_pieces;
    std::string                         torrent_final_output_filename;
    int                                 torrent_total_length;
    std::string                         torrent_hex_info_hash;
    double                              percentage_already_dl;
    std::string                         perfect_peer_ip;
    int                                 perfect_peer_port;

public:
    PeerManager(int piece_length, int torrent_total_length, std::string torrent_final_output_filename, std::string torrent_hex_info_hash);
    ~PeerManager(){};
    int                                 TryBitfieldPieces(std::string, std::string, const std::string &);
    std::pair<std::string, int>         GetPerfectPeer(std::map<std::string, std::string> &peers, const std::string &info_hash); // function that will return the good peer ip:port
    int                                 DoesThePeerGotAllPieces(std::string); // calcule et compare si le bitfield possede toutes les pieces
    int                                 HexStringToBinary(std::string); // hex to binary
    int                                 CalculatePiecesNeeded(int &);
    void                                SetPerfectPeerIp(const std::string &str) { this->perfect_peer_ip = str; };
    void                                SetPerfectPeerPort(const int &new_port) { this->perfect_peer_port = new_port; };
    int                                 DownloadTheTorrent();
    double                              GetPercentageAdvancment(int piece_value);

    void                                SendRequestMessage(std::ofstream &, int &, int &, int );
    void                                GetLastPieceLength();
    void                                GetMaxPieceLength();
    std::string                         Handshake();

};

#endif // _PEER_MANAGER_HPP_