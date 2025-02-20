#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <iomanip>
#include <string>

#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <utility>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int					TryBitfieldPieces(std::string peer_ip, std::string peer_port, const std::string &info_hash)
{
  struct timeval tv;
  struct sockaddr_in address;
  fd_set fdset;
  int sock = -1;
  
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(peer_ip.c_str()); /* assign the address */
  address.sin_port = htons(stoi(peer_port));            /* translate int2port num */

  sock = socket(AF_INET, SOCK_STREAM, 0);
  fcntl(sock, F_SETFL, O_NONBLOCK);

  connect(sock, (struct sockaddr *)&address, sizeof(address));

  FD_ZERO(&fdset);
  FD_SET(sock, &fdset);
  tv.tv_sec = 3;             /* 10 second timeout */
  tv.tv_usec = 0;

  if (select(sock + 1, NULL, &fdset, NULL, &tv) == 1)
    {
      int so_error;
      socklen_t len = sizeof so_error;

      getsockopt(sock, SOL_SOCKET, SO_ERROR, &so_error, &len);

      if (so_error == 0)
	{
	  std::cout << "Connexion with peer " << peer_ip << ":" << peer_port << "done !" << std::endl;
	  close(sock);
	  return 1;
      }
    }
  else
    {
      //printf("Connection Failed\n");
      std::cout << "Connection Failed" << std::endl;
      return -1;
    }
  close(sock);
}

int					main()
{
  std::map<std::string, std::string>	peers;
  const std::string			info_hash = "\x6a\x41\xe2\xa633232\x7b\x7f\x90\x15\xd3\xfb\x23\x09\xdb\xbd\x2f\xa0\xe2\x5\x43\xac"; // echecs

  peers.insert(std::pair<std::string, std::string>("128.90.144.58", "50500"));
  peers.insert(std::pair<std::string, std::string>("197.253.195.231", "32891"));
  peers.insert(std::pair<std::string, std::string>("24.122.177.115", "21080"));
  peers.insert(std::pair<std::string, std::string>("41.108.130.50", "33232"));
  peers.insert(std::pair<std::string, std::string>("46.105.102.196", "62312"));
  peers.insert(std::pair<std::string, std::string>("90.112.152.232", "14496"));
  peers.insert(std::pair<std::string, std::string>("5.196.95.122", "45000"));
  peers.insert(std::pair<std::string, std::string>("37.59.56.169", "13471"));
  peers.insert(std::pair<std::string, std::string>("74.57.113.14", "50500"));

  for (std::map<std::string, std::string>::iterator it = peers.begin(); it != peers.end(); ++it) // display peers ip/port
    {
      std::cout << "Try connection to : " << it->first << ":" << it->second << std::endl;
      if (TryBitfieldPieces(it->first, it->second, info_hash) == 1)
	{
	  std::cout << "The peer " << it->first << ":" << it->second << " is PERFECT" << std::endl;
	}
      //if (TryBitfieldPieces("37.59.56.169", "13471", info_hash) == 1) { std::cout << "close"; };
    }
  return 0;
}
