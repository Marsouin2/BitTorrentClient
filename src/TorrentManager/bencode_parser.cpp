#include "bencode_parser.hpp"

BencodeParser::BencodeParser(std::string encoded_bencode_) : encoded_bencode{ encoded_bencode_ } {
    this->DeleteNumbersAndColon();
}

std::string             BencodeParser::GetIntegerInsideAString(int i) {
    std::stringstream   str_strm;
    std::string         temp_str;
    std::string         tempo_substring;

    tempo_substring = this->encoded_bencode.substr(0, i);
    std::cout << "_substring : " << tempo_substring << "\n";
    const std::string str_final_number = std::regex_replace(tempo_substring, std::regex("[^0-9]*([0-9]+).*"), std::string("$1"));
    std::cout << "one : " << str_final_number << "\n";
    int int_final_number = std::stoi(str_final_number);
    std::string dict_first_key = this->encoded_bencode.substr(i, int_final_number); // on get le d8:[announce]
    std::cout << "de " << i << " a " << int_final_number << " dans " << this->encoded_bencode << "\n";
    this->encoded_bencode.erase(0, i);

    std::cout << "retourne : " << dict_first_key << "\n";
    return dict_first_key;
}

void                    BencodeParser::DeleteNumbersAndColon() {
    this->encoded_bencode = "d8:announce70:http://ygg.peer2peer.cc:8080/qzW6hdFRmiEAuOiomGeLUL5LV4xBs5YQ/announce10:created by10:YggTorrent13:creation datei1588682976e4:infod5:filesld6:lengthi9796011e4:pathl68:Xavier -mv- Dang - metamorphoses EP - 07 packt (radiohead cover).mp3eed4:attr1:h6:lengthi39489e4:pathl10:Folder.jpgeed6:lengthi7787717e4:pathl55:Xavier -mv- Dang - metamorphoses EP - 01 initiative.mp3eed6:lengthi7526492e4:pathl54:Xavier -mv- Dang - metamorphoses EP - 02 the dream.mp3eed6:lengthi8825300e4:pathl51:Xavier -mv- Dang - metamorphoses EP - 03 summer.mp3eed6:lengthi8105366e4:pathl49:Xavier -mv- Dang - metamorphoses EP - 04 rush.mp3eed6:lengthi6888060e4:pathl54:Xavier -mv- Dang - metamorphoses EP - 05 protector.mp3eed6:lengthi8421970e4:pathl49:Xavier -mv- Dang - metamorphoses EP - 06 load.mp3eed4:attr1:h6:lengthi7039e4:pathl17:AlbumArtSmall.jpgeee4:name15:Metamorphose EP12:piece lengthi32768e6:pieces35040:c!>SâÆ±YSð¥Eïâõ3ÓË|ÌZèìÂÀéç÷+)tv7ÓI]¬L";
    std::string         tempo_string;
    int                 tempo_index = 0;
    bool                key_or_content = false; // true = "announce" false = "http://ygg.peer"
    std::string         dict_first_key;
    std::string         dict_second_key;

    for (int i = 0; i != this->encoded_bencode.length(); ++i) {
        ++tempo_index;
        if (this->encoded_bencode[i] == ':' && isdigit(this->encoded_bencode[i - 1])) {
            std::cout << '\n' << this->encoded_bencode[i - 2] << this->encoded_bencode[i - 1] << this->encoded_bencode[i] << std::endl;
            key_or_content = !key_or_content;
            if (key_or_content == true) { // true = "announce"
                dict_first_key = this->GetIntegerInsideAString(tempo_index);
            }
            else if (key_or_content == false) { // false
                dict_second_key = this->GetIntegerInsideAString(tempo_index);
                this->bencode_informations.insert(std::pair<std::string, std::string>(dict_first_key, dict_second_key)); //Error
                //this->bencode_informations.insert(dict_first_key, dict_second_key);
                tempo_index = 0;
            }
        }
    }
}