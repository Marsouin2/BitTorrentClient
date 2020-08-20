#include <fstream>
#include <iostream>

int		main() {
  std::ofstream	file("test.epub");
  std::string	str = "\xffffffef\xffffffbb\xbf\x50\x4b\x03\x04\x14\x00\x00\x00\x00\x00\x42\x98\xdc"; // 16
  std::string	str2 = "\xffffffef\xffffffbb\xbf\x50\x4b\x03\x04\x14\x01\x02\x03\x04\x05\x42\x98\xdc"; // 16
  const char *str3 = "\xffffffef\xffffffbb\xbf\x50\x4b\x03\x04\x14\x00\x00\x00\x00\x00\x42\x98\xdc"; // 16

  std::cout << "13 : " << str[13] << ", " << str[14] << ", " << str[15] << std::endl;
  std::cout << "13 : " << str2[13] << ", " << str2[14] << ", " << str2[15] << std::endl;
  std::cout << "13 : " << str3[13] << ", " << str3[14] << ", " << str3[15] << std::endl;
  for (int i = 0; i != 16 ; ++i) {
    printf("\\x%x\n", str3[i]);
    //std::cout << "add : " << str[i] << " in file" << std::endl;
    file << str3[i];
  }
  file.close();
  return 0;
}
