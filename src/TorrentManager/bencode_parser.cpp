#include "bencode_parser.hpp"

BencodeParser::BencodeParser(std::string encoded_bencode_) : encoded_bencode{ encoded_bencode_ } {
    //this->DeleteNumbersAndColon();
    this->UseBencodeParser();
}

std::string                             BencodeParser::GetBencodeKeyContent(std::string const& json_string, std::string const& key) // turn string JSON to map <string, string>
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

//void                                    BencodeParser::GetInfoHash(std::string const& json_string) // get the info hash of the torrent file
/*void                                        BencodeParser::GetInfoHash2()
{
    std::string info;
    int counter = 0;

    while(info.find("4:info") == -1)
    {
        info.push_back(this->encoded_bencode[counter]);
        counter++;
    }

    std::cout << "info : " << info << std::endl;

    unsigned char array[this->encoded_bencode.size()];
    int test = 0;

    std::cout << "counter = " << counter << std::endl;

    //for(int data; (data = this->encoded_bencode[counter]) > -1;)
    for (int data = 0; data != this->encoded_bencode.length(); ++data)
    {
        array[data] = this->encoded_bencode[counter];
        counter++;
    }
    std::cout << "hash ca : " << array << std::endl;
}*/

std::string GetHexRepresentation(unsigned char *Bytes, size_t Length)
{
    std::ostringstream os;
    os.fill('0');
    os << std::hex;
    for(const unsigned char *ptr = Bytes; ptr < Bytes+Length; ++ptr) {
        os<<std::setw(2)<<(unsigned int)*ptr;
    }
    return os.str();
}

void                                        BencodeParser::GetInfoHash2()
{
    const std::string to_find = "info";

    size_t found = this->encoded_bencode.find(to_find);
    if (found != std::string::npos) {
        std::string                 tempo_content_info_hash = this->encoded_bencode.substr(found + 4, this->encoded_bencode.length());
        tempo_content_info_hash.erase(tempo_content_info_hash.end()-1);
        const int tempo_info_hash_length = tempo_content_info_hash.length();

        //unsigned char* p = (unsigned char*)(&tempo_content_info_hash[0]);
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

        std::cout << tempo_content_info_hash << std::endl;

        SHA1(p, tempo_info_hash_length, obuf);

        int j;
        for (j = 0; j < 20; j++) {
            printf("%02x ", obuf[j]);
        }
        printf("\n");
    }
}

void                                    BencodeParser::UseBencodeParser() {
    auto decodedData = bencoding::decode(this->encoded_bencode);
    std::shared_ptr<bencoding::BItem> sec = std::move(decodedData);

    std::string                 t = bencoding::getPrettyRepr(sec);

    this->GetBencodeKeyContent(t, "announce");
    this->GetBencodeKeyContent(t, "length");
    this->GetBencodeKeyContent(t, "name");
    this->GetInfoHash2();

    //std::cout << t << "\n"; // Print the decoded data in a readable way to the standard output.
}