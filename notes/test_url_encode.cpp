#include <iostream>
#include <vector>
#include <string>

using namespace std;

void hexchar(unsigned char c, unsigned char &hex1, unsigned char &hex2)
{
  hex1 = c / 16;
  hex2 = c % 16;
  hex1 += hex1 <= 9 ? '0' : 'a' - 10;
  hex2 += hex2 <= 9 ? '0' : 'a' - 10;
}

string urlencode(string s)
{
  const char *str = s.c_str();
  vector<char> v(s.size());
  v.clear();
  for (size_t i = 0, l = s.size(); i < l; i++)
    {
      char c = str[i];
      if ((c >= '0' && c <= '9') ||
	  (c >= 'a' && c <= 'z') ||
	  (c >= 'A' && c <= 'Z') ||
	              c == '-' || c == '_' || c == '.' || c == '!' || c == '~' ||
	  c == '*' || c == '\'' || c == '(' || c == ')')
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
	  unsigned char d1, d2;
	  hexchar(c, d1, d2);
	  v.push_back(d1);
	  v.push_back(d2);
	}
    }

  return string(v.cbegin(), v.cend());
}

std::string HexToBytes(const std::string& hex) {
  //std::vector<char> bytes;
  std::string bytes;

  for (unsigned int i = 0; i < hex.length(); i += 2) {
    std::string byteString = hex.substr(i, 2);
    char byte = (char) strtol(byteString.c_str(), NULL, 16);
    bytes.push_back(byte);
  }

  return bytes;
}

int		main() {
  //cout << urlencode("9fc20b9e98ea98b4a35e6223041a5ef94ea27809") << endl;
  std::string h = HexToBytes("9fc20b9e98ea98b4a35e6223041a5ef94ea27809");
  
  cout << urlencode(h) << endl;
  
  return 0;
}
