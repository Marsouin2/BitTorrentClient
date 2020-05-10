#include "bencode_parser.hpp"

BencodeParser::BencodeParser(std::string encoded_bencode_) : encoded_bencode{ encoded_bencode_ } {
    //this->DeleteNumbersAndColon();
    this->UseBencodeParser();
}

void                                    BencodeParser::UseBencodeParser() {
    auto decodedData = bencoding::decode(this->encoded_bencode);
    std::shared_ptr<bencoding::BItem> sec = std::move(decodedData);

    std::string                 t = bencoding::getPrettyRepr(sec);
    std::cout << t << "\n"; // Print the decoded data in a readable way to the standard output.


    //lt::bdecode_node const e = lt::bdecode(buf, ec, &pos, cfg.max_decode_depth, cfg.max_decode_tokens);
    //std::printf("\n\n----- raw info -----\n\n%s\n", print_entry(e).c_str());
}

/*std::string                     BencodeParser::GetIntegerInsideAString(int tempo_index) {
    std::stringstream   str_strm;
    std::string         temp_str;
    std::string         tempo_substring;

    tempo_substring = this->encoded_bencode.substr(0, tempo_index);
    const std::string str_final_number = std::regex_replace(tempo_substring, std::regex("[^0-9]*([0-9]+).*"), std::string("$1"));
    int int_final_number = std::stoi(str_final_number);
    // CONST en bas
    const std::string dict_new_key = this->encoded_bencode.substr(tempo_index, int_final_number); // on get le d8:[announce] && le 70:http://yggtorrent...
    this->encoded_bencode.erase(0, tempo_index + int_final_number);

    //this->tempo_map_stored.push_back(dict_new_key);
    return dict_new_key;
}

std::string                     BencodeParser::StoreCreationDate() { // on reconnais creation date en cle donc le contenu sera <i>contenu<e>
    std::string                 creation_date;
    int                         i = 0;

    while (this->encoded_bencode[i] != 'e') {
        if (this->encoded_bencode[i] != 'i') {
            creation_date.insert(creation_date.end(), this->encoded_bencode[i]);
        }
        ++i;
    }
    this->encoded_bencode.erase(0, i);
    return creation_date;
}

void                    BencodeParser::GetTorrentFiles() { // get length and filename
    // on en est a i39856239e du length
    std::string         file_length;
    int                 i = 0;

    while (this->encoded_bencode[i] != 'e') {
        if (this->encoded_bencode[i] != 'i') {
            file_length.insert(file_length.end(), this->encoded_bencode[i]);
        }
        i++;
    }
    this->encoded_bencode.erase(0, i);
    // on en est a 4:pathl68:Xavier Dang - mr - mv... -> get le 2eme nombre et son index
}

void                    BencodeParser::DeleteNumbersAndColon() {
    std::string         tempo_string;
    int                 tempo_index = 0;
    std::string         first_map_content;
    std::string         second_map_content;
    bool                torrent_files_content = false; // est ce que on en est a tous les fichier du torrent ou non ?
    bool                key_or_content = false; // true = "announce" false = "http://ygg.peer"

    for (int i = 0; i != this->encoded_bencode.length(); ++i) {
        ++tempo_index;
        //std::cout << "tempo_index : " << tempo_index << std::endl;
        if (this->encoded_bencode[i] == ':' && isdigit(this->encoded_bencode[i - 1])) { // i<content>e / l<content>e / d<content>e
            key_or_content = !key_or_content;
            if (second_map_content == "files" && first_map_content == "info") { torrent_files_content = true; }
            if (key_or_content) { // true = "announce"
                first_map_content = this->GetIntegerInsideAString(tempo_index);
                tempo_index = 0;
                i = -1;
            }
            else if (first_map_content == "creation date") {
                second_map_content = this->StoreCreationDate();
                this->bencode_informations.insert(std::pair<std::string, std::string>(first_map_content, second_map_content));
                tempo_index = 0;
                i = -1;
            }
            else if (first_map_content == "length" && torrent_files_content) {
                this->GetTorrentFiles();
            }
            else { // false
                second_map_content = this->GetIntegerInsideAString(tempo_index);
                this->bencode_informations.insert(std::pair<std::string, std::string>(first_map_content, second_map_content));
                tempo_index = 0;
                i = -1;
            }
        }
    }
    for(std::map<std::string, std::string>::const_iterator it = this->bencode_informations.begin(); it != this->bencode_informations.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << "\n\n";
    }
}*/