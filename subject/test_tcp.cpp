#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <string.h>

#define PORT 51413

int main(int argc, char const *argv[])
{
  int sock = 0, valread;
  struct sockaddr_in serv_addr;

  const int handshake_size = 1+19+8+20+20;
  char handshake[handshake_size];

  const int protocol_name_offset = 1;
  const int reserved_offset = protocol_name_offset + 19;
  const int info_hash_offset = reserved_offset + 8;
  const int peer_id_offset = info_hash_offset + 20;

  const char prefix = '\x13';
  const std::string BitTorrent_protocol = "BitTorrent protocol";
  const std::string info_hash = "\x9f\xc2\xb\x9e\x98\xea\x98\xb4\xa3\x5e\x62\x23\x4\x1a\x5e\xf9\x4e\xa2\x78\x9";
  const std::string peer_id = "-PC0001-706887310628";

  handshake[0] = prefix; // length prefix of the string
  std::copy(BitTorrent_protocol.begin(), BitTorrent_protocol.end(), &handshake[protocol_name_offset]);
  for (int i = reserved_offset; i != reserved_offset + 8; ++i)
    handshake[i] = '0';
  std::copy(info_hash.begin(), info_hash.end(), &handshake[info_hash_offset]);
  std::copy(peer_id.begin(), peer_id.end(), &handshake[peer_id_offset]);

  std::cout << "handshake = " << handshake << std::endl;

  // ---------------------------------------------------

  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      printf("\n Socket creation error \n");
      return -1;
    }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "81.141.90.197", &serv_addr.sin_addr) <= 0)
    {
      printf("\nInvalid address/ Address not supported \n");
      return -1;
    }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
      printf("\nConnection Failed \n");
      return -1;
    }
  printf("Connexion OK\n");
  send(sock, handshake, strlen(handshake), 0);
  printf("Envoi du message BitTorrent protocol de %d caracteres\n", strlen(handshake));
  //while (valread > 0) {
    valread = read(sock , buffer, 1024);
    printf("reception de %d : %s\n", valread, buffer);
    // }
  return 0;
}
