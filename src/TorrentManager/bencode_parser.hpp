#ifndef BENCODE_PARSER_HPP_
#define BENCODE_PARSER_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <regex>
#include <map>
#include <sstream>

#include "../../lib/bencoding/bencoding.h"

class                                           BencodeParser
{
private:
    std::string                                 encoded_bencode;
    /*std::string                                 decoded_bencode;
    std::map<std::string, std::string>          bencode_informations;
    std::vector<std::string>                    tempo_map_stored;*/

public:
    BencodeParser(std::string encoded_bencode_);
    ~BencodeParser(){};
    void                                        UseBencodeParser();
    /*void                                        DeleteNumbersAndColon(); // delete the {70:} from the torrent's bencode
    void                                        BencodeToJson();
    std::string                                 GetIntegerInsideAString(int i);
    void                                        ErasePartOfBencode();
    std::string                                 StoreCreationDate();
    void                                        UseBencodeParser();*/
};

#endif // BENCODE_PARSER_HPP_