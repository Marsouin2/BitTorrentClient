#include "network.hpp"

Network::Network(const std::string &url_request) {
    const std::string tracker_peer_bencode =  this->Send(url_request);
    this->GetPeersIps(tracker_peer_bencode);
}

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
    if(curl) {
        /* First set the URL that is about to receive our POST. This URL can just as well be a https:// URL if that is what should receive the data. */
        curl_easy_setopt(curl, CURLOPT_URL, message.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &reading_buffer);

        res = curl_easy_perform(curl); // Perform the request, res will get the return code

        curl_easy_cleanup(curl); // always cleanup
        return(reading_buffer);
    }
    return "error";
}

void                        Network::Receive() { // receive the message from tracker / peer
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

void                        TestStringDecimal(std::string &str)
{
    std::cout << "Integer value: ";
    for (size_t i = 0 ; i < str.size(); ++i)
        std::cout << (int)str[i] << ".";
    std::cout << "\n";
}

void                                    GetTrackerIps(const std::string &peers_ips) { // in = string of peers out = map of <ip><port>
    std::map<std::string, std::string>  decimal_peers_ips;
    std::string                         tempo_constitute_ip;
    int                                 tempo_constitute_port;
    int                                 which_octet_number = 0; // on est au 3, 4 ou 5 ? (dernier de l'ip ou au port)

    for (int y = 0; y < peers_ips.length(); ++y)
    {
        unsigned char                   tempo_peers_ips = peers_ips[y];
        int                             i = tempo_peers_ips;

        //std::cout << "y = " << y << " et which_octet_number = " << which_octet_number << std::endl;
        if (which_octet_number == 3) {
            tempo_constitute_ip = tempo_constitute_ip + std::to_string(i) + ':';
            //std::cout << "constite up : " << tempo_constitute_ip << std::endl;
        }
        else if (which_octet_number == 4) { // on store le port
            tempo_constitute_port = i;
        }
        else if (which_octet_number == 5) { // calcul port
            tempo_constitute_port = tempo_constitute_port * 256 + i;
            //decimal_peers_ips["port"] = std::to_string(tempo_constitute_port);
            //std::cout << "string ip = " << tempo_constitute_ip << std::endl;
            decimal_peers_ips[tempo_constitute_ip] = std::to_string(tempo_constitute_port);
            tempo_constitute_ip.clear();
            tempo_constitute_port = 0;
            which_octet_number = -1;
        }
        else { // on fait l'ip
            tempo_constitute_ip = tempo_constitute_ip + std::to_string(i) + '.';
            //std::cout << "constite up : " << tempo_constitute_ip << std::endl;
        }
        which_octet_number++;
    }
    //std::cout << "cense donner : 249.109.220.203:51413 et 192.131.44.104:64042" << std::endl;
    for (std::map<std::string, std::string>::iterator it = decimal_peers_ips.begin(); it != decimal_peers_ips.end(); ++it)
    {
        std::cout << it->first << ":" << it->second << std::endl;
    }
}

void                        Network::GetPeersIps(const std::string &tracker_bencode) { // get the tracker response, decode bencode to get peers ip
    BencodeParser           bencode_parser(tracker_bencode);

    const std::string tracker_response = bencode_parser.GetBencodeDatas();

    //std::cout << tracker_bencode << std::endl;
    //std::cout << "---------------------------------------" << std::endl;

    std::string tempo =  GetBencodeKeyContent(tracker_response, "peers");

    GetTrackerIps(tempo);

    //https://stackoverflow.com/questions/50094674/how-to-parse-ip-and-port-from-http-tracker-response
    //https://stackoverflow.com/questions/33675913/how-can-i-decode-the-peers-value-in-the-tracker-response-bittorent
}

void                        Network::FirstTrackerMessage() {

}