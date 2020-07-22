#include "manage_torrent_file.hpp"

ManageTorrentFile::ManageTorrentFile(const std::string &torrent_file) {
    this->torrent_filename = torrent_file;
    this->OpenAndRead();
    this->GetDecodedBencode();
}

const std::string                             ManageTorrentFile::GetInfoHash() {
    const std::string to_find = "info";

    size_t found = this->torrent_bencode.find(to_find);
    if (found != std::string::npos) {
        std::string tempo_content_info_hash = this->torrent_bencode.substr(found + 4, this->torrent_bencode.length());
        tempo_content_info_hash.erase(tempo_content_info_hash.end() - 1);
        const int tempo_info_hash_length = tempo_content_info_hash.length();

        unsigned char *p = new unsigned char[tempo_info_hash_length];
        unsigned char obuf[20];
        int i = 0;

        for (char &c : tempo_content_info_hash) {
            p[i] = c;
            i++;
        }

        p[tempo_info_hash_length] = '\0';


        //std::cout << tempo_content_info_hash << std::endl;

        SHA1(p, tempo_info_hash_length, obuf);

        std::cout << "sha1 : " << obuf << std::endl;

        //std::cout << "binary : " << binary_info_hash << std::endl;

        /*for (int y = 0; y != 20; y++) {
            std::cout << "\'" << std::bitset<8>(obuf[y]).to_string() << "\'" << std::endl;
        }*/

        /*int j;
        for (j = 0; j < 20; j++) {
            printf("%02x ", obuf[j]);
        }
        printf("\n");*/
    }
    return "zizi";
}

std::string                             ManageTorrentFile::GetBencodeKeyContent(std::string const& json_string, std::string const& key) // turn string JSON to map <string, string>
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


}

void                        ManageTorrentFile::GetDecodedBencode() { // split the bencode string into multiple datas to get exactly what we want
    BencodeParser           bencode_parser(this->torrent_bencode);

    const std::string bencode_datas = bencode_parser.GetBencodeDatas();
    const std::string torrent_announce = GetBencodeKeyContent(bencode_datas, "announce");
    const std::string torrent_length = GetBencodeKeyContent(bencode_datas, "length");
    const std::string torrent_info_hash = GetInfoHash();

    BytesManipulator        bytes_manipulator(torrent_info_hash);

    const std::string       final_info_hash = bytes_manipulator.GetUrlEncodeInfoHash(); // get the urlencoded info_hash
    std::cout << "final info_hash : " << final_info_hash << std::endl;

    this->ConstituteFirstTorrentRequest(torrent_announce, torrent_info_hash, torrent_length); // need /name/info_hash/length
    //const std::string       bencode_string =
}

int                         ManageTorrentFile::OpenAndRead() { // open the torrent and store the content (called bencode) inside a std::string
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
