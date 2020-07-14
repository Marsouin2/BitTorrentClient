#include <string>
#include <iostream>

std::string toPercent(std::string &SRC) {
  std::string ret;
  char ch;
  int i, ii;
  for (i=0; i<SRC.length(); i++) {
    if (int(SRC[i])==37) {
      sscanf(SRC.substr(i+1,2).c_str(), "%x", &ii);
      ch=static_cast<char>(ii);
      ret+=ch;
      i=i+2;
    } else {
      ret+=SRC[i];
    }
  }
  return (ret);
}

int		main()
{
  std::string	input = "84E6B5AA9F68477BE346BA762DE1A6C84CAED4EE";
  std::string	output = "%84%E6%B5%AA%9FhG%7B%E3F%BAv-%E1%A6%C8L%AE%D4%EE";

  std::string out = toPercent(input);
  std::cout << "out : " << output << std::endl;
  std::cout << "out : " << out << std::endl;
  
  return 0;
}
