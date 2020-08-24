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
    std::string                                 bencode_datas; // real bencode_datas
    TorrentDatas                                torrent_datas;

    std::string                                 torrent_length;
    std::string                                 piece_length;
    std::string                                 torrent_name;

public:
    BencodeParser(std::string encoded_bencode_);
    ~BencodeParser(){};
    void                                        UseBencodeParser();
    std::string                                 GetBencodeKeyContent(std::string const&, std::string const&);
    void                                        GetInfoHash(std::string const&);
    //void                                        GetInfoHash2();
    void                                        SetBencodeDatas(const std::string new_bencode_datas) { this->bencode_datas = new_bencode_datas; };
    const std::string                           GetBencodeDatas() { return this->bencode_datas; };
    void                                        SetTorrentLength(const std::string &torrent_length) { this->torrent_length = torrent_length; };
    void                                        SetPieceLength(const std::string &piece_length) { this->piece_length = piece_length; };
    void                                        SetTorrentName(const std::string &torrent_name) { this->torrent_name = torrent_name; };
    const int                                   GetTorrentLength() { return stoi(this->torrent_length); } ;
    const int                                   GetPieceLength() { return stoi(this->piece_length); };
    const std::string                           GetTorrentName() { return this->torrent_name; };

};

#endif // BENCODE_PARSER_HPP_