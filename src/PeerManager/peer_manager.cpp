#include "peer_manager.hpp"

PeerManager::PeerManager(int piece_length, int torrent_total_length) : piece_length{ piece_length }, torrent_total_length { torrent_total_length } // recois la map des peers(ip:port)
{
    // doit send le handshake a chaque peer le de la liste pour ensuite acceder a leur bitfield. compter le nombre de peers et regarder a quel point c'est long
    //this->DetermineTheGoodPeer(peers);
}

int                         PeerManager::HexStringToBinary(std::string sHex) // returns the number of piece that the peer got
{
    std::bitset<8> foo (sHex[0]);
    int nb_of_one = foo.count();
    std::cout << "number of 1 : " << nb_of_one << std::endl;
    return nb_of_one;
}

int                         PeerManager::CalculatePiecesNeeded(int &pieces_number)
{
    double x = this->torrent_total_length / (double)this->piece_length;
    int y = (int)x;
    if (x > y) // alors il faut y + 1 pieces
    {
        if (pieces_number == y + 1) // on a trouve un peer qui possede toutes les pieces
            return 1;
    }
    return -1;
}

int                            PeerManager::DoesThePeerGotAllPieces(std::string str_buffer) // calcule et compare si le bitfield possede toutes les pieces
{
    if (this->piece_length <= 16384) // il y a juste a dl direct les pieces
    {
        int pieces_number = this->HexStringToBinary(str_buffer);
        return this->CalculatePiecesNeeded(pieces_number); // 1 if ok else -1
    }
    else // il faut decouper en blocks
    {

    }
    return -1;
}

int                        PeerManager::TryBitfieldPieces(std::string peer_ip, std::string peer_port, const std::string &info_hash) // handshake + get bittorrent pour savoir si le peer possede toutes les pieces ou non
{
    int sock = 0, valread;
    Network netw;
    struct sockaddr_in serv_addr;

    // ---------------------------------------------------

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    //serv_addr.sin_addr.s_addr = inet_addr(IP);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(stoi(peer_port));
    std::cout << "connect to " << peer_ip << ":" << peer_port << std::endl;
    int s;
    if (s = inet_pton(AF_INET, peer_ip.c_str(), &serv_addr.sin_addr) <= 0)
    {
        std::cout << "Invalid address / Adress not supported" << std::endl;
        return -1;
    }
    if ((s = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        std::cerr << "Connection Failed" << std::endl;
        std::cout << s << std::endl;
        return -1;
    }
    std::string handshake = netw.SendHandshakeRequest(info_hash, sock);

    send(sock, handshake.c_str(), handshake.length(), 0);
    valread = read(sock, buffer, 1024);

    valread = read(sock, buffer, 1024); // ici on read le bitfield

    printf("handshake answer de %d : ", valread);
    std::string string_buffer = buffer;
    if (valread == 1) { // on a recu que le bitfield en 1 truc (LES ECHECS)
        return this->DoesThePeerGotAllPieces(string_buffer);
    }

    return 0;
}

std::pair<std::string, int> PeerManager::GetPerfectPeer(std::map<std::string, std::string> &peers, const std::string &info_hash) // EN DUR
{
    /*for (std::map<std::string, std::string>::iterator it = peers.begin(); it != peers.end(); ++it) // display peers ip/port
    {
        std::cout << "try connection to : " << it->first << ":" << it->second << std::endl;
        if (this->TryBitfieldPieces(it->first, it->second, info_hash) == 1)
        {
            return std::make_pair(it->first, std::stoi(it->second));
        }
    }*/
    if (this->TryBitfieldPieces("37.59.56.169", "13471", info_hash) == 1) // echec
        return std::make_pair("37.59.56.169", 13471);
    else
        return std::make_pair("null", 0);

    //if (this->TryBitfieldPieces("81.141.90.197", "51413", info_hash) == 1) // ubuntu
    //    return std::make_pair("81.141.90.197", 51413);

    //if (this->TryBitfieldPieces("104.188.95.55", "13873", info_hash) == 1)
    //    std::cout << "SUCCESS CONNECT !!" << std::endl;
}