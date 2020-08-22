#include "peer_manager.hpp"

PeerManager::PeerManager(std::map<std::string, std::string> &peers) // recois la map des peers(ip:port)
{
    // doit send le handshake a chaque peer le de la liste pour ensuite acceder a leur bitfield. compter le nombre de peers et regarder a quel point c'est long
    this->DetermineTheGoodPeer(peers);
}

void                        PeerManager::DetermineTheGoodPeer(std::map<std::string, std::string> &peers)
{
    for (std::map<std::string, std::string>::iterator it = peers.begin(); it != peers.end(); ++it) // display peers ip/port
    {
        this->TryBitfieldPieces(it->first, it->second);
        std::cout << it->first << ":" << it->second << std::endl;
    }
}

void                        PeerManager::TryBitfieldPieces(std::string peer_ip, std::string peer_port) // handshake + get bittorrent pour savoir si le peer possede toutes les pieces ou non
{
    Network                 netw;
    int                     sock;
    std::string::size_type  sz;   // alias of size_t

    //netw.CreateTcpConnection(peer_ip, peer_port);
    sock = netw.HandleTcpConnection(peer_ip, std::stoi(peer_port, &sz));
    netw.Send(, sock);
}