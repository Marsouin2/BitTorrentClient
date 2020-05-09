#ifndef BENCODE_PARSER_HPP_
#define BENCODE_PARSER_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <regex>
#include <map>
#include <sstream>

class                                           BencodeParser
{
private:
    std::string                                 encoded_bencode;
    std::string                                 decoded_bencode;
    std::map<std::string, std::string>          bencode_informations;
    // struct decoded_bencode;  structure a retourner qui va contenir toutes les infos necessaire concernant le torrent
public:
    BencodeParser(std::string encoded_bencode_);
    ~BencodeParser(){};
    void                                        DeleteNumbersAndColon(); // delete the {70:} from the torrent's bencode
    void                                        BencodeToJson();
    std::string                                 GetIntegerInsideAString(int i);
    void                                        ErasePartOfBencode();
};

#endif // BENCODE_PARSER_HPP_