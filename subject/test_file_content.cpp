#include <fstream>

void		PutIt(std::ofstream &output_file, std::string str) {

  output_file << str << "|END_STRING|" << std::endl;
}

int		main() {
  std::ofstream	output_file;

  output_file.open("fichier_test.epub");
  
  PutIt(output_file, "Je suis la ligne 1");
  PutIt(output_file, "Quand a moi c'est 2");
  PutIt(output_file, "Wow, ici il s'agit de 3");
  PutIt(output_file, "Je suis le dernier, donc 4");

  return 0;
}
