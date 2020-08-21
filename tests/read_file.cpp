#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>

int		main()
{
  std::ifstream t("/home/marsouin/Téléchargements/LE_JOUEUR_D_ECHECS.epub");
  if (!t) {
    std::cerr << "error while opening the file" << std::endl;
  }
  std::string str((std::istreambuf_iterator<char>(t)),
		  std::istreambuf_iterator<char>());

  std::ofstream e("test.epub");
  for (int i = 0; i != 16383; ++i) {
    e << str[i];
  }
  e.close();
  return 0;
}
