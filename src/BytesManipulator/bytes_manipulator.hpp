#ifndef BYTES_MANIPULATOR_HPP_
# define BYTES_MANIPULATOR_HPP_

#include <string>
#include <iostream>
#include <vector>

class                       BytesManipulator
{
private:
    std::string             urlencode_info_hash;

public:
    BytesManipulator(const std::string &input_info_hash);
    ~BytesManipulator(){};
    std::string             HexToBytes(const std::string&);
    //void                    StringToHex(std::string&);
    std::string             GetUrlEncodeInfoHash() const { return urlencode_info_hash; };
    void                    SetUrlEncode(const std::string new_urlencode_info_hash) { this->urlencode_info_hash = new_urlencode_info_hash; };
    std::string             Urlencode(std::string);
    void                    Hexchar(unsigned char c, unsigned char &hex1, unsigned char &hex2);

};

#endif // BYTES_MANIPULATOR_HPP_