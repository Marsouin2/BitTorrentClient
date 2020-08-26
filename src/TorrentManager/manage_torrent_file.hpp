#ifndef MANAGE_TORRENT_FILE_HPP_
#define MANAGE_TORRENT_FILE_HPP_

#include "../BytesManipulator/bytes_manipulator.hpp"
#include "../PeerManager/peer_manager.hpp"
#include "../Networking/network.hpp"
#include "patron_manage_torrent_file.hpp"
#include "../my_own_exceptions.hpp"
#include "bencode_parser.hpp"

class                                           ManageTorrentFile : PatronManageTorrentFile
{
private:
    std::string                                 torrent_filename;
    std::string                                 torrent_bencode;
    std::string                                 torrent_info_hash;
    std::string                                 torrent_final_output_filename;
    std::string                                 final_url_request;
    std::string                                 torrent_hex_info_hash;
    int                                         tracker_socket;
    int                                         piece_length;
    int                                         torrent_total_length;
    std::map<std::string, std::string>          peers_list;
    std::pair<std::string, int>                 perfect_peer;
    std::string                                 output_file_path;

public:
    ManageTorrentFile(const std::string &torrent_file, const std::string &output_path_file);
    ~ManageTorrentFile() {};
    int                                         OpenAndRead();
    void                                        GetBencode() {};
    void                                        ConstituteFirstTorrentRequest(const std::string, const std::string, const std::string);
    void                                        GetDecodedBencode(); // call class BencodeParser to decode the encoded parser (the content of the .torrent file)
    void                                        SetTorrentInfoHash(const std::string torrent_info_hash) { this->torrent_info_hash = torrent_info_hash; };
    const std::string                           GetInfoHash();
    void                                        SetInfoHash(const std::string info_hash) { this->torrent_info_hash = info_hash; };
    const std::map<std::string, std::string>    GetPeersList() { return this->peers_list; };
    std::string                                 GetFinalUrl() const { return final_url_request; };
    void                                        SetFinalUrl(const std::string new_final_url_request) { this->final_url_request = new_final_url_request; };
    void                                        SetPeersList(const std::map<std::string, std::string> &new_peers_list) { this->peers_list = new_peers_list; };
    std::string                                 GetBencodeKeyContent(std::string const&, std::string const&);
    void                                        ConnectToTracker();
    void                                        ConstituteHexFinalHash(std::string);
    void                                        GetThePerfectPeer();

};

#endif // MANAGE_TORRENT_FILE_HPP_