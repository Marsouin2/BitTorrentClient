#include "manage_torrent_file.hpp"

ManageTorrentFile::ManageTorrentFile(const std::string &torrent_file, const std::string &output_path_file) : torrent_filename { torrent_file },
                                                                                                             output_file_path { output_path_file }
{
    //this->torrent_filename = torrent_file;
    this->OpenAndRead(); // open and read the .torrent file
    this->GetDecodedBencode(); // we got all the informations we needed to handshake

    this->ConnectToTracker(); // connect to tracker with Network class and store the socket in ManageTorrent Class to use it later, and send it to PeerManager
    this->GetThePerfectPeer(); // call the class <PeerManager> qui va regarder tous les bitfield des peers jusqu'a trouver le bon
}

void                                            ManageTorrentFile::ConnectToTracker() // on set la peer list
{
    Network                                     netw(this->GetFinalUrl());

    const std::map<std::string, std::string>    peer_list = netw.GetPeersList();
    this->SetPeersList(peer_list);
    std::cout << "We've found " << this->peers_list.size() << " seeders." << std::endl;
}

void                                            ManageTorrentFile::GetThePerfectPeer() // call <PeerManager> that will make requests to get bitfields
{
    const std::string                           filepath_with_filename = this->output_file_path + '/' + this->torrent_final_output_filename;

    PeerManager                                 peer_manager(this->piece_length, this->torrent_total_length,
                                                             filepath_with_filename, this->torrent_hex_info_hash);

    this->perfect_peer = peer_manager.GetPerfectPeer(this->peers_list, this->torrent_hex_info_hash); // returns the peer with all pieces <ip><port>
    if (this->perfect_peer.first != "null") // ("null", 0) or ("ip", port)
    { // on a trouve le peer parfait
        peer_manager.DownloadTheTorrent(); // on dl le fichier
    }
    else
        std::cout << "No peer is seeding the torrent...closing..." << std::endl;
}

const std::string                               ManageTorrentFile::GetInfoHash() {
    const std::string to_find = "info";

    size_t found = this->torrent_bencode.find(to_find);
    if (found != std::string::npos) {
        std::string tempo_content_info_hash = this->torrent_bencode.substr(found + 4, this->torrent_bencode.length());
        tempo_content_info_hash.erase(tempo_content_info_hash.end() - 1);
        const int tempo_info_hash_length = tempo_content_info_hash.length();

        unsigned char *p = new unsigned char[tempo_info_hash_length];
        unsigned char obuf[20];
        int i = 0;

        for (char &c : tempo_content_info_hash)
            p[i++] = c;

        p[tempo_info_hash_length] = '\0';

        SHA1(p, tempo_info_hash_length, obuf);
        char buf[SHA_DIGEST_LENGTH * 2];

        char tempo[20]; // to copy the unsigned char to a char to copy it into a string
        for (int f = 0; f != 20; ++f)
            tempo[f] = obuf[f];

        this->torrent_hex_info_hash.assign(tempo, 20);

        for (i = 0; i < SHA_DIGEST_LENGTH; i++) {
            sprintf((char*)&(buf[i*2]), "%02x", obuf[i]);
        }
        return buf;
    }
    return "zizi";
}

std::string                             ManageTorrentFile::GetBencodeKeyContent(std::string const& json_string, std::string const& key)
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

void                        ManageTorrentFile::ConstituteFirstTorrentRequest(const std::string torrent_announce,
                                                                             const std::string torrent_info_hash,
                                                                             const std::string torrent_length) { // constitute the url for the first request to the tracker
    // https://torrent.ubuntu.com/announce?info_hash=%9F%C2%0B%9E%98%EA%98%B4%A3%5Eb%23%04%1A%5E%F9N%A2x%09&peer_id=-PC0001-706887310628&uploaded=0&downloaded=0&left=2715254784&port=6889&compact=1

    const std::string final_request = torrent_announce + "?info_hash=" + torrent_info_hash +
                                      "&peer_id=-PC0001-706887310628&uploaded=0&downloaded=0&left=" +
                                      torrent_length + "&port=6889&compact=1";
    this->SetFinalUrl(final_request);
    this->SetInfoHash(torrent_info_hash);
    //std::cout << "final request : " << final_request << std::endl;

}

void                        ManageTorrentFile::GetDecodedBencode() { // split the bencode string into multiple datas to get exactly what we want
    BencodeParser           bencode_parser(this->torrent_bencode);

    const std::string bencode_datas = bencode_parser.GetBencodeDatas();
    const std::string torrent_announce = GetBencodeKeyContent(bencode_datas, "announce");
    const std::string torrent_length = GetBencodeKeyContent(bencode_datas, "length");
    const std::string torrent_info_hash = GetInfoHash();

    // get torrent informations for the future
    this->piece_length = bencode_parser.GetPieceLength();
    this->torrent_total_length = bencode_parser.GetTorrentLength();
    this->torrent_final_output_filename = bencode_parser.GetTorrentName();

    std::cout << "Starting to download for " << this->torrent_final_output_filename << std::endl;

    // 6a41e2a67b7f9015d3fb2309dbbd2fa0e20543ac

    //this->ConstituteHexFinalHash(torrent_info_hash); // constitute the info_hash(\x21\xsf...) pour le handashak
    BytesManipulator        bytes_manipulator(torrent_info_hash);

    const std::string       final_info_hash = bytes_manipulator.GetUrlEncodeInfoHash(); // get the urlencoded info_hash

    this->ConstituteFirstTorrentRequest(torrent_announce, final_info_hash, torrent_length); // need /name/info_hash/length
}

int                         ManageTorrentFile::OpenAndRead() { // open the torrent and store the content (called bencode) inside an std::string
    try {
        std::ifstream       file_opened(this->torrent_filename);
        if (file_opened) {
            this->torrent_bencode.assign((std::istreambuf_iterator<char>(file_opened)), (std::istreambuf_iterator<char>()));
            //std::cout << "torrent_content : " << this->torrent_bencode << std::endl;
        }
        else
            throw(MyOwnExceptions("can't open the torrent, please verify the name."));
    }
    catch (MyOwnExceptions& ex) {
        std::cerr << ex.GetErrorMessage() << std::endl;
        return 84;
    }
    return 0;
}