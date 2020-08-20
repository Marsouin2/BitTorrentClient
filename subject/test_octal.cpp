#include <iostream>

int		main() {
  std::string	test = "\xef"; // PK
  std::string	test2 = "\xbb";
  std::string	test3 = "\xbf";
  std::string	test4 = "\x50"; // P
  std::string	test5 = "\x4b"; // K
  //std::string	test6 = "\x3";
  char		test6 = '\x3';
  std::string	test7 = "\x4";
  std::string	test8 = "\x14";
  std::string	test9 = "\xbb";
  std::string   test10 = "\x42"; // B
  std::string   test11 = "\x98"; // \230

  std::cout << test << std::endl;
  std::cout << std::endl;
  std::cout << test2 << std::endl;
  std::cout << std::endl;
  std::cout << test3 << std::endl;
  std::cout << std::endl;
  std::cout << "P : " << test4 << std::endl;
  std::cout << std::endl;
  std::cout << "K : " << test5 << std::endl;
  std::cout << std::endl;
  printf("\\x%x\n", test6);
  printf("%d\n", test6);
  printf("\\x%x\n", test7);
  printf("\\x%x\n", test8);
  printf("\\x%x\n", test9);
  std::cout << test6 << std::endl;
  std::cout << std::endl;
  std::cout << test7 << std::endl;
  std::cout << std::endl;
  std::cout << test8 << std::endl;
  std::cout << std::endl;
  std::cout << test9 << std::endl;
  std::cout << std::endl;
  std::cout << "B : " << test10 << std::endl;
  std::cout << std::endl;
  std::cout << test11 << std::endl;
  return 0;
}
