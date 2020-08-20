#include <string>
#include <iostream>

int	main()
{
  std::string zizi;
  //const std::string len_str = "\x00\x00\x00\x02";
  const std::string len_str = "\x00\x01\x02\x03";
  //const char z = '\x0d';
  const char z = '\x04';

  zizi.resize(5);
  //std::copy(len_str.begin(), len_str.end(), &zizi[0]);
  //zizi[0] = '\x00';
  //zizi[1] = '\x01';
  //zizi[2] = '\x02';
  //zizi[3] = '\x03';
  zizi[4] = z;
  //std::cout << zizi << std::endl;
  for (int i = 0; i != zizi.length(); ++i)
   printf("%d, ", zizi[i]);
  return 0;
}
