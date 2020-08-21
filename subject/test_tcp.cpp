#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <cstddef>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <unistd.h>
#include <string.h>

//#define PORT 51413 // ubuntu
//#define IP "81.141.90.197" // ubuntu

//#define PORT 53703 // echec
//#define IP "185.157.245.92" // echec

#define IP "173.179.238.34"
#define PORT 39530


std::string			        Handshake()
{
  const int handshake_size = 1+19+8+20+20;
  //char handshake[handshake_size];
  //char				*handshake = malloc (sizeof(char) * handshake_size);
  std::string handshake;
  handshake.resize(handshake_size);

  const int protocol_name_offset = 1;
  const int reserved_offset = protocol_name_offset + 19;
  const int info_hash_offset = reserved_offset + 8;
  const int peer_id_offset = info_hash_offset + 20;

  const char prefix = '\x13';
  const std::string BitTorrent_protocol = "BitTorrent protocol";
  //const std::string info_hash = "\x9f\xc2\xb\x9e\x98\xea\x98\xb4\xa3\x5e\x62\x23\x4\x1a\x5e\xf9\x4e\xa2\x78\x9"; // ubuntu
  const std::string info_hash = "\x6a\x41\xe2\xa6\x7b\x7f\x90\x15\xd3\xfb\x23\x9\xdb\xbd\x2f\xa0\xe2\x5\x43\xac"; // echecs
  const std::string peer_id = "-PC0001-702887310628";

  handshake[0] = prefix; // length prefix of the string
  std::copy(BitTorrent_protocol.begin(), BitTorrent_protocol.end(), &handshake[protocol_name_offset]);
  for (int i = reserved_offset; i != reserved_offset + 8; ++i)
    handshake[i] = '0';
  std::copy(info_hash.begin(), info_hash.end(), &handshake[info_hash_offset]);
  std::copy(peer_id.begin(), peer_id.end(), &handshake[peer_id_offset]);

  //std::cout << "handshake = " << handshake << std::endl;
  return handshake;
}

std::string			Interested()
{
  std::string		interested;

  interested.resize(3);

  interested[0] = '\x00';
  interested[1] = '\x01';
  interested[2] = '\x02';
  
  return interested;
}


std::string			Unchoke()
{
  std::string			unchoke;

  unchoke.resize(3);

  unchoke[0] = '\x1';
  unchoke[1] = '\x1';

  return unchoke;
}

std::string			Bitfield()
{
  std::string			bitfield;

  bitfield.resize(6);
  bitfield[0] = '\x00';
  bitfield[1] = '\x00';
  bitfield[2] = '\x00';
  bitfield[3] = '\x02'; // len
  bitfield[4] = '\x05'; // id
  bitfield[5] = '\x00'; // piece that I have

  return bitfield;
}

void				ReadPayload(char *payload) // read the paylod to know which pieces the peer got
{
  int			begin_pieces_index = 0;
  int			tempo = 0;

  //std::cout << payload[0] << ", " << payload[1] << std::endl;
  while (42)
    {
      if (payload[begin_pieces_index] != 'e' && payload[begin_pieces_index+1] == 'E')
	break;
      std::cout << payload[begin_pieces_index];
      begin_pieces_index++;
    }
  begin_pieces_index++;
  std::cout << "pieces index : " << begin_pieces_index << std::endl;
  while (payload[begin_pieces_index] != '\0')
    {
      tempo++;
      begin_pieces_index++;
    }
  std::cout << "on a " << tempo << " pieces" << std::endl;
}

void			DisplayInHexa(const char *str, int length) // display char* to hexa
{
  for (int i = 0; i != length; ++i)
    {
      std::cout << str[i];
    }
  printf("\n");
}

/*void			PutInFile(int &block_index, char buffer[1024], std::ofstream &output_file)
{
  char			tempo_buffer_content[strlen(buffer)];

  strncpy(tempo_buffer_content, buffer, strlen(buffer));

  std::cout << "Write " << strlen(buffer) << " caracters in the file." << std::endl;
  std::cout << "Write these in the file : " << tempo_buffer_content << std::endl;
  output_file << tempo_buffer_content << std::endl;
  if (block_index == 3)
    output_file.close();
    }*/

void			SendRequestMessage(std::ofstream &output_file, int &valread, int &sock, int block_index) // if unchoked : request pieces
{
  uint32_t length = 13;
  uint8_t id_request = 6;
  uint8_t message[17];
  char buffer1[16384 + 12];
  char buffer2[1128 + 12];

  (uint32_t&) *message = htonl(length);
  message[4] = id_request;
  (uint32_t&) message[5] = htonl(block_index);
  (uint32_t&) message[9] = htonl(0);
  if (block_index == 4)
    (uint32_t&) message[13] = htonl(1128);
  else 
    (uint32_t&) message[13] = htonl(16383);

  send(sock, message, 17, 0);
  sleep(1);
  if (block_index == 4) {
    valread = read(sock, buffer2, 1129 + 12);
    int i = 13;
    while (i != 1141) {
      output_file << buffer2[i];
      i++;
    }
    output_file.close();
  }
  else {
    valread = read(sock, buffer1, 16384 + 12);
    int i = 13;
    while (i != 16397) {
      output_file << buffer1[i];
      i++;
    }
    printf("On a mis %d caracteres dans le ficiher\n", 16399 - 13);
  }
}

int main(int argc, char const *argv[])
{
  int sock = 0, valread;
  //bool continue = true;
  struct sockaddr_in serv_addr;

  // ---------------------------------------------------

  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
      std::cerr << "Socket creation error" << std::endl;
      return -1;
    }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, IP, &serv_addr.sin_addr) <= 0)
    {
      std::cerr << "Invalid address / Adress not supported" << std::endl;
      return -1;
    }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
      std::cerr << "Connection Failed" << std::endl;
      return -1;
    }
  std::cout << "Connexion OK" << std::endl;

  bool requests_bool = false;
  
  std::string handshake = Handshake();
  send(sock, handshake.c_str(), handshake.length(), 0);
  valread = read(sock, buffer, 1024);

  uint8_t bitfield[8];
  uint8_t id_bitfield = 5;
  (uint32_t&) bitfield[0] = htonl(9); // len
  bitfield[4] = id_bitfield;
  
  uint8_t bitfield_payload[4];
  (uint32_t&) bitfield_payload[0] = htonl(0);
  send(sock, bitfield_payload, 4, 0);
  valread = read(sock, buffer, 1024);

  uint8_t interested[5];
  uint8_t id_interested2 = 2;
  (uint32_t&) interested[0] = htonl(1);
  interested[4] = id_interested2; 
  send(sock, interested, 5, 0); // mettre le nombre d'octets
  valread = read(sock, buffer, 1024);
  if (valread == 5) {
    if (buffer[3] == '\x01' && buffer[4] == '\x01') {
      std::ofstream	output_file("Les_echecs.epub");
      SendRequestMessage(output_file, valread, sock, 0);
      SendRequestMessage(output_file, valread, sock, 1);
      SendRequestMessage(output_file, valread, sock, 2);
      SendRequestMessage(output_file, valread, sock, 3);
      SendRequestMessage(output_file, valread, sock, 4);
    }
  }
  return 0;
}
