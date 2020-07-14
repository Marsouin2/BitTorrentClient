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
    std::cout << "le contenu de " << key << " est : |" << key_content << "|" << std::endl;
    return key_content;
}

void                                    BencodeParser::UseBencodeParser() {
    auto decodedData = bencoding::decode(this->encoded_bencode);
    std::shared_ptr<bencoding::BItem> sec = std::move(decodedData);

    std::string                 t = bencoding::getPrettyRepr(sec);

    this->GetBencodeKeyContent(t, "announce");
    this->GetBencodeKeyContent(t, "length");
    this->GetBencodeKeyContent(t, "name");

    //std::cout << t << "\n"; // Print the decoded data in a readable way to the standard output.
}