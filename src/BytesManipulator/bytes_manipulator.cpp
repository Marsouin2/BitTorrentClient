#include "bytes_manipulator.hpp"

BytesManipulator::BytesManipulator(std::string input_info_hash) {
    std::cout << "test input : " << input_info_hash << std::endl;
    std::string bytes = this->HexToBytes(input_info_hash);
    this->SetUrlEncode(this->Urlencode(bytes));
}

void                        BytesManipulator::Hexchar(unsigned char c, unsigned char &hex1, unsigned char &hex2)
{
    hex1 = c / 16;
    hex2 = c % 16;
    hex1 += hex1 <= 9 ? '0' : 'a' - 10;
    hex2 += hex2 <= 9 ? '0' : 'a' - 10;
}

std::string                 BytesManipulator::Urlencode(std::string s)
{
    const char *str = s.c_str();
    std::vector<char> v(s.size());
    v.clear();
    for (size_t i = 0, l = s.size(); i < l; i++)
    {
        char c = str[i];
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '-' || c == '_' || c == '.' || c == '!'
                || c == '~' || c == '*' || c == '\'' || c == '(' || c == ')')
        {
            v.push_back(c);
        }
        else if (c == ' ')
        {
            v.push_back('+');
        }
        else
        {
            v.push_back('%');
            unsigned char d1;
            unsigned char d2;
            this->Hexchar(c, d1, d2);
            v.push_back(d1);
            v.push_back(d2);
        }
    }
    return std::string(v.cbegin(), v.cend());
}

std::string                 BytesManipulator::HexToBytes(const std::string& hex) {
    std::string         bytes;

    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);
    }
    return bytes;
}