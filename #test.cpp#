#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;

int main() {
  std::string input = "d42:zi9";
  std::string output = std::regex_replace(input, std::regex("[^0-9]*([0-9]+).*"), std::string("$1"));
  cout << input << endl;
  cout << output << endl;
}
