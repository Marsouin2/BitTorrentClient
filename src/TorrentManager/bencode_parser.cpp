#include "bencode_parser.hpp"

BencodeParser::BencodeParser(std::string encoded_bencode_) : encoded_bencode{ encoded_bencode_ } {
    //this->DeleteNumbersAndColon();
    this->UseBencodeParser();
}

/*std::string                             BencodeParser::GetBencodeKeyContent(std::string const& json_string, std::string const& key) // turn string JSON to map <string, string>
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
}*/

/*void                                        BencodeParser::GetInfoHash2()
{
    const std::string to_find = "info";

    size_t found = this->encoded_bencode.find(to_find);
    if (found != std::string::npos) {
        std::string                 tempo_content_info_hash = this->encoded_bencode.substr(found + 4, this->encoded_bencode.length());
        tempo_content_info_hash.erase(tempo_content_info_hash.end()-1);
        const int tempo_info_hash_length = tempo_content_info_hash.length();

        unsigned char *p = new unsigned char[tempo_info_hash_length];

        int i = 0;

        for(char& c : tempo_content_info_hash) {
            //std::cout << c;
            p[i] = c;
            //std::cout << "copie de " << c << " index " << i << std::endl;
            i++;
        }
        p[tempo_info_hash_length] = '\0';

        unsigned char obuf[20];

        //std::cout << tempo_content_info_hash << std::endl;

        SHA1(p, tempo_info_hash_length, obuf);

        std::cout << "binary : " << obuf[0] << "\'" << std::bitset<8>(obuf[0]).to_string() << "\'" << std::endl;

    }
}*/

void                                    BencodeParser::UseBencodeParser() {
    auto decodedData = bencoding::decode(this->encoded_bencode);
    std::shared_ptr<bencoding::BItem> sec = std::move(decodedData);

    const std::string                 t = bencoding::getPrettyRepr(sec);

    this->SetBencodeDatas(t);

    // https://torrent.ubuntu.com/announce?info_hash=%9F%C2%0B%9E%98%EA%98%B4%A3%5Eb%23%04%1A%5E%F9N%A2x%09&peer_id=-PC0001-706887310628&uploaded=0&downloaded=0&left=2715254784&port=6889&compact=1

    //std::cout << this->GetBencodeKeyContent(t, "announce") << std::endl; // https://torrent.ubuntu.com/announce
    //std::cout << this->GetBencodeKeyContent(t, "length") << std::endl; // left ?
    //std::cout << this->GetBencodeKeyContent(t, "name") << std::endl; // ubuntu-20.04-desktop-amd64.iso (inutile ici)
    //this->GetInfoHash2(); // get le info hash
}