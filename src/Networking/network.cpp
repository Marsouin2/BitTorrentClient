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

void                        Network::GetPeersIps(const std::string &tracker_bencode) { // get the tracker response, decode bencode to get peers ip
    BencodeParser           bencode_parser(tracker_bencode);

    const std::string tracker_response = bencode_parser.GetBencodeDatas();

    std::string tempo =  GetBencodeKeyContent(tracker_response, "peers");
    char zizi[300];
    //https://stackoverflow.com/questions/33675913/how-can-i-decode-the-peers-value-in-the-tracker-response-bittorent
    for (int i = 0; i < 300; i++) {
        printf("%x | ", tempo[i]);
        //sprintf((char*)&(zizi[i*2]), "%x", tempo[i]);
    }
    //std::cout << std::endl;

    //sprintf((char*)zizi, "%x", tempo);
    //std::cout << "zizi : " << zizi << std::endl;

    //std::cout << "tracker response : " << tracker_bencode << std::endl;
}

void                        Network::FirstTrackerMessage() {

}