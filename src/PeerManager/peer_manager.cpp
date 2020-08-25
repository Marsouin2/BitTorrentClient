#include "peer_manager.hpp"

PeerManager::PeerManager(int piece_length, int torrent_total_length,
                         std::string torrent_final_output_filename,
                         std::string torrent_hex_info_hash) : torrent_total_length { torrent_total_length }, // recois la map des peers(ip:port)
                                                              torrent_final_output_filename { torrent_final_output_filename },
                                                              torrent_hex_info_hash { torrent_hex_info_hash }
{
    if (piece_length >= 16384)
        this->piece_length = 16383;
    else
        this->piece_length = piece_length;
//this->DetermineTheGoodPeer(peers);
}

int                           PeerManager::DownloadTheTorrent() // on a trouve le bon peer, donc on va telecharger le contenu
{
    //Network                 netw;

    int sock = 0, valread;
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(this->perfect_peer_port);

    std::cout << "connect to " << this->perfect_peer_ip << ":" << this->perfect_peer_port << std::endl;
    if (inet_pton(AF_INET, this->perfect_peer_ip.c_str(), &serv_addr.sin_addr) <= 0)
    {
        std::cout << "Invalid address / Adress not supported" << std::endl;
        return -1;
    }
    if ((connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))) < 0)
    {
        std::cerr << "Connection Failed" << std::endl;
        return -1;
    }
    std::cout << "Connexion OK" << std::endl;

    std::string handshake = this->Handshake();
    send(sock, handshake.c_str(), handshake.length(), 0);       // HANDSHAKE
    valread = read(sock, buffer, 1024);

    uint8_t bitfield[8];                                    // BITFIELD
    uint8_t id_bitfield = 5;
    (uint32_t&) bitfield[0] = htonl(9); // len
    bitfield[4] = id_bitfield;
    valread = read(sock, buffer, 1024);

    uint8_t bitfield_payload[4];
    (uint32_t&) bitfield_payload[0] = htonl(0);    // BITFIELD PAYLOAD
    send(sock, bitfield_payload, 4, 0);
    valread = read(sock, buffer, 1024);

    uint8_t interested[5];
    uint8_t id_interested2 = 2;
    (uint32_t&) interested[0] = htonl(1);
    interested[4] = id_interested2;                        // INTERESTED / UNCHOKE
    send(sock, interested, 5, 0); // mettre le nombre d'octets
    valread = read(sock, buffer, 1024);

    //valread = recv(sock, &buffer, 1024, 0);

    //printf("%d valread\n", valread);
    for (int i = 0; i != valread; ++i)
        printf("\\x%x", buffer[i]);
    printf("\n");

    if (valread == 5) {
        if (buffer[3] == '\x01' && buffer[4] == '\x01') {
            std::ofstream     output_file(this->torrent_final_output_filename);
            for (int i = 0; i != this->number_of_pieces; ++i)
            {
                this->SendRequestMessage(output_file, valread, sock, i);
            }
        }
    }

    // 1/ connect
    // 2/ handshake
    // 3/ interested
    // 4/ ouvrir le fichier
    // 5/ while (!number_of_pieces) { request }
    // 6/ close
}

int                         PeerManager::HexStringToBinary(std::string sHex) // returns the number of piece that the peer got
{
    std::bitset<8> foo (sHex[0]);
    int nb_of_one = foo.count();
    //std::cout << "number of 1 : " << nb_of_one << std::endl;
    return nb_of_one;
}

int                         PeerManager::CalculatePiecesNeeded(int &pieces_number)
{
    double x = this->torrent_total_length / (double)this->piece_length;
    int y = (int)x;
    if (x > y) // alors il faut y + 1 pieces
    {
        if (pieces_number == y + 1) { // on a trouve un peer qui possede toutes les pieces
            this->number_of_pieces = pieces_number;
            return 1;
        }
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
        //std::cout << s << std::endl;
        return -1;
    }
    std::string handshake = netw.SendHandshakeRequest(info_hash, sock);

    send(sock, handshake.c_str(), handshake.length(), 0);
    valread = read(sock, buffer, 1024);

    valread = read(sock, buffer, 1024); // ici on read le bitfield

    //printf("handshake answer de %d : ", valread);
    std::string string_buffer = buffer;
    if (valread == 1) { // on a recu que le bitfield en 1 truc (LES ECHECS)
        int ret_value =  this->DoesThePeerGotAllPieces(string_buffer);
        close(sock);
        return ret_value;
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
    if (this->TryBitfieldPieces("37.59.56.169", "13471", info_hash) == 1) { // echec
        this->SetPerfectPeerIp("37.59.56.169");
        this->SetPerfectPeerPort(13471);
        return std::make_pair("37.59.56.169", 13471);
    }
    else
        return std::make_pair("null", 0);

    //if (this->TryBitfieldPieces("81.141.90.197", "51413", info_hash) == 1) // ubuntu
    //    return std::make_pair("81.141.90.197", 51413);

    //if (this->TryBitfieldPieces("104.188.95.55", "13873", info_hash) == 1)
    //    std::cout << "SUCCESS CONNECT !!" << std::endl;
}

std::string                             PeerManager::Handshake()
{
  const int handshake_size = 1+19+8+20+20;
  std::string handshake;
  handshake.resize(handshake_size);

  const int protocol_name_offset = 1;
  const int reserved_offset = protocol_name_offset + 19;
  const int info_hash_offset = reserved_offset + 8;
  const int peer_id_offset = info_hash_offset + 20;

  const char prefix = '\x13';
  const std::string BitTorrent_protocol = "BitTorrent protocol";
  //const std::string info_hash = "\x9f\xc2\xb\x9e\x98\xea\x98\xb4\xa3\x5e\x62\x23\x4\x1a\x5e\xf9\x4e\xa2\x78\x9"; // ubuntu
  //const std::string info_hash = "\x6a\x41\xe2\xa6\x7b\x7f\x90\x15\xd3\xfb\x23\x09\xdb\xbd\x2f\xa0\xe2\x5\x43\xac"; // echecs
  const std::string peer_id = "-PC0001-702887310628";

  handshake[0] = prefix; // length prefix of the string
  std::copy(BitTorrent_protocol.begin(), BitTorrent_protocol.end(), &handshake[protocol_name_offset]);
  for (int i = reserved_offset; i != reserved_offset + 8; ++i)
    handshake[i] = '0';
  std::copy(this->torrent_hex_info_hash.begin(), this->torrent_hex_info_hash.end(), &handshake[info_hash_offset]);
  std::copy(peer_id.begin(), peer_id.end(), &handshake[peer_id_offset]);

  //std::cout << "handshake = " << handshake << std::endl;
  return handshake;
}

void                    PeerManager::GetMaxPieceLength()
{
    if (this->piece_length == 16384)
        this->max_piece_length = 16383;
    else
        this->max_piece_length = this->piece_length;
}

void                    PeerManager::GetLastPieceLength()
{
    int                 reste = this->piece_length * (this->number_of_pieces - 1);
    this->last_piece_length = this->torrent_total_length - reste;
}

void                    PeerManager::SendRequestMessage(std::ofstream &output_file, int &valread, int &sock, int index) {
    //std::cout << "On check si " << index - 1 << " == " << this->number_of_pieces << std::endl;
    if (index == this->number_of_pieces - 1) // last piece
    {
        this->GetLastPieceLength();
        //printf("Last piece length : %d\n", this->last_piece_length);
    }
    else if (index == 0)
    {
        this->GetMaxPieceLength();
        //printf("Max piece length : %d\n", this->max_piece_length);
    }

    uint32_t length = 13;
    uint8_t id_request = 6;
    uint8_t message[17];
    /*if (index - 1 == this->number_of_pieces)
        char buffer[this->last_piece_length + 8];
    else
        char buffer[this->max_piece_length + 12];*/
    //char buffer1[16384 + 12];
    //char buffer2[1128 + 12];

    (uint32_t&) *message = htonl(length);
    message[4] = id_request;
    (uint32_t&) message[5] = htonl(index);
    (uint32_t&) message[9] = htonl(0);
    if (index == this->number_of_pieces - 1)
        //(uint32_t&) message[13] = htonl(1128);
        (uint32_t&) message[13] = htonl(this->last_piece_length);
    else
        //(uint32_t&) message[13] = htonl(16383);
        (uint32_t&) message[13] = htonl(this->max_piece_length);
    send(sock, message, 17, 0);
    sleep(1);

    if (index == this->number_of_pieces - 1)
    {
      char buffer[this->last_piece_length + 8];
      //char buffer[1128 + 12];
      valread = read(sock, buffer, this->last_piece_length + 9);
      //valread = read(sock, buffer, 1129 + 12);
        int i = 13;
        while (i != this->last_piece_length + 9)
	//while (i != 1141)
        {
            //while (i != 1141) {
            output_file << buffer[i];
            i++;
        }
        std::cout /*<< this->GetPercentageAdvancment*/ << "Downloading piece #" << index + 1 << " from 1 peer" << std::endl;
        output_file.close();
    }
    else
    {
        //char buffer[16384 + 12];
        char buffer[this->max_piece_length + 13];
        //valread = read(sock, buffer, 16384 + 12);
        valread = read(sock, buffer, this->max_piece_length + 13);
        //valread = recv(sock, buffer, this->max_piece_length + 12, 0);
        int i = 13;
        //while (i != 16397)
        while (i != this->max_piece_length + 14)
        {
            output_file << buffer[i];
            i++;
        }
        std::cout /*<< this->GetPercentageAdvancment*/ << "Downloading piece #" << index + 1 << " from 1 peer" << std::endl;
    }
}
