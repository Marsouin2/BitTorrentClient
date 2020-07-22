#ifndef BENCODE_PARSER_HPP_
#define BENCODE_PARSER_HPP_

#include <iostream>
#include <memory>
#include <string>
#include <regex>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>

#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/evp.h>
#include "../../lib/bencoding/bencoding.h"

struct                                          TorrentDatas
{
    std::string                                 announce;
    std::string                                 torrent_name;
    int                                         torrent_length;

} ;

class                                           BencodeParser
{
private:
    std::string                                 encoded_bencode;
    TorrentDatas                                torrent_datas;
    //std::string                                 decoded_bencode;
    //std::map<std::string, std::string>          bencode_informations;
    //std::vector<std::string>                    tempo_map_stored;*/

public:
    BencodeParser(std::string encoded_bencode_);
    ~BencodeParser(){};
    void                                        UseBencodeParser();
    std::string                                 GetBencodeKeyContent(std::string const&, std::string const&);
    void                                        GetInfoHash(std::string const&);
    void                                        GetInfoHash2();
    //std::map<std::string, std::string>          GetBencodeInformations() { return this->bencode_informations; };
    /*void                                        DeleteNumbersAndColon(); // delete the {70:} from the torrent's bencode
    void                                        BencodeToJson();
    std::string                                 GetIntegerInsideAString(int i);
    void                                        ErasePartOfBencode();
    std::string                                 StoreCreationDate();
    void                                        UseBencodeParser();*/
};

#endif // BENCODE_PARSER_HPP_