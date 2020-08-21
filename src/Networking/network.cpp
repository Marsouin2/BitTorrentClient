#include "network.hpp"

Network::Network(const std::string &url_request) {
    std::cout << "on send : " << url_request << std::endl;
    const std::string tracker_peer_bencode =  this->Send(url_request);
    std::cout << "tracker peer bencode : " << tracker_peer_bencode << std::endl;
    std::cout << "get peer ips 2" << std::endl;
    this->GetPeersIps(tracker_peer_bencode);
    /*if (this->CreateTcpConnection("81.141.90.197", 51413) != -1) {
        this->ConstituteHandshake();
    }*/
}

Network::Network() {} // si l'on veux juste envoyer des requetes SendTcpMessage();

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return(size * nmemb);
}

const std::string         Network::Send(const std::string &message) { // send a message to the tracker / peer
    CURL            *curl;
    CURLcode        res;
    std::string     reading_buffer;

    curl = curl_easy_init();
    if (curl) {
        /* First set the URL that is about to receive our POST. This URL can just as well be a https:// URL if that is what should receive the data. */
        curl_easy_setopt(curl, CURLOPT_URL, message.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &reading_buffer);

        res = curl_easy_perform(curl); // Perform the request, res will get the return code

        curl_easy_cleanup(curl); // always cleanup
        return (reading_buffer);
    }
    return "error";
}

void                        Network::SendTcpMessage(const std::string &message_to_send)
{
    const char* tempo_message = message_to_send.c_str();

    send(this->sock, tempo_message, strlen(tempo_message), 0);
    std::cout << "sending : " << tempo_message << std::endl;
    this->ReadTcpMessage(); // on read la reponse du peer
}

void                        Network::ReadTcpMessage() {
    char buffer[1024] = { 0 };
    int valread = read(sock, buffer, 1024);
    std::cout << "received " << valread << " caracters : " << buffer << std::endl;
}

/*
 * void                                    Network::ConstituteHandshake()// make the very first request to a peer (the handshake) to know if he can dialogue with us
{
    const int handshake_size = 1+19+8+20+20;
    char handshake[handshake_size];

    const int protocol_name_offset = 1;
    const int reserved_offset = protocol_name_offset + 19;
    const int info_hash_offset = reserved_offset + 8;
    const int peer_id_offset = info_hash_offset + 20;

    const char prefix = '\x13';
    const std::string BitTorrent_protocol = "BitTorrent protocol";
    const std::string info_hash = "\x9f\xc2\xb\x9e\x98\xea\x98\xb4\xa3\x5e\x62\x23\x4\x1a\x5e\xf9\x4e\xa2\x78\x9";
    const std::string peer_id = "-PC0001-706887310628";

    handshake[0] = prefix; // length prefix of the string
    std::copy(BitTorrent_protocol.begin(), BitTorrent_protocol.end(), &handshake[protocol_name_offset]);
    for (int i = reserved_offset; i != reserved_offset + 8; ++i)
        handshake[i] = '0';
    std::copy(info_hash.begin(), info_hash.end(), &handshake[info_hash_offset]);
    std::copy(peer_id.begin(), peer_id.end(), &handshake[peer_id_offset]);

    //this->SendTcpMessage(handshake);
    //std::cout << "handshake = " << handshake << std::endl;
}*/

int                                     Network::CreateTcpConnection(const std::string &ip_addr, const int &port) {
    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_addr.c_str(), &this->serv_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address or the address not supported" << std::endl;
        return -1;
    }
    if (connect(this->sock, (struct sockaddr *)&this->serv_addr, sizeof(this->serv_addr)) < 0)
    {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }
    return 0;
}

int                                     Network::HandleTcpConnection(const std::string &ip_addr, const int &port) // fait la connection et retourne la socket
{
    int                                 sock;
    struct sockaddr_in                  serv_addr;


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, ip_addr.c_str(), &serv_addr.sin_addr) <= 0)
    {
        std::cerr << "Invalid address or the address not supported" << std::endl;
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }
    return sock;
}

void                                    Network::Receive() { // receive the message from tracker / peer
}

std::string                             Network::GetBencodeKeyContent(std::string const& json_string, std::string const& key) // duplication
{
    const std::string tempo_key = '\"' + key + "\": ";
    std::string key_content;

    std::size_t found = json_string.find(tempo_key);
    found = found + tempo_key.length() + 1;
    if (found != std::string::npos)
    {
        int i = found;
        while (42) {
            if (json_string[i] == ',')
                break;
            ++i;
        }
        key_content = json_string.substr(found, i - found);
    }
    // need "announce", "piece length" and pieces
    if (key_content.back() == '\"')
        key_content.erase(key_content.end() - 1);
    //std::cout << "le contenu de " << key << " est : |" << key_content << "|" << std::endl;
    return key_content;
}

void                                    Network::GetTrackerIps(const std::string &peers_ips) // in = string of peers out = map of <ip><port>
{
    std::string                         tempo_constitute_ip;
    int                                 tempo_constitute_port;
    int                                 which_octet_number = 0; // on est au 3, 4 ou 5 ? (dernier de l'ip ou au port)

    for (int y = 0; y < peers_ips.length(); ++y)
    {
        unsigned char                   tempo_peers_ips = peers_ips[y];
        int                             i = tempo_peers_ips;

        if (which_octet_number == 3) {
            tempo_constitute_ip = tempo_constitute_ip + std::to_string(i) + ':';
        }
        else if (which_octet_number == 4) { // on store le port
            tempo_constitute_port = i;
        }
        else if (which_octet_number == 5) { // calcul port
            tempo_constitute_port = tempo_constitute_port * 256 + i;
            //decimal_peers_ips[tempo_constitute_ip] = std::to_string(tempo_constitute_port);
            this->AddPeersInMap(tempo_constitute_ip, tempo_constitute_port);
            tempo_constitute_ip.clear();
            tempo_constitute_port = 0;
            which_octet_number = -1;
        }
        else { // on fait l'ip
            tempo_constitute_ip = tempo_constitute_ip + std::to_string(i) + '.';
        }
        which_octet_number++;
    }
    std::cout << "liste des ip:port :" << std::endl;
    for (std::map<std::string, std::string>::iterator it = this->decimal_peers_ips.begin(); it != this->decimal_peers_ips.end(); ++it) // display peers ip/port
    {
        std::cout << it->first << ":" << it->second << std::endl;
    }
}

void                        Network::GetPeersIps(const std::string &tracker_bencode) // get the tracker response, decode bencode to get peers ip
{
    BencodeParser           bencode_parser(tracker_bencode);

    const std::string tracker_response = bencode_parser.GetBencodeDatas();

    std::string tempo =  GetBencodeKeyContent(tracker_response, "peers");

    GetTrackerIps(tempo);

    //https://stackoverflow.com/questions/50094674/how-to-parse-ip-and-port-from-http-tracker-response
    //https://stackoverflow.com/questions/33675913/how-can-i-decode-the-peers-value-in-the-tracker-response-bittorent
}