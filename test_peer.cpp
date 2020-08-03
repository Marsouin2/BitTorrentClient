#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *buf = "P^L♠*j.t╤u→πe199711";
  int chunks = strlen(buf) / 6 ;
  int offset =  0;
  unsigned char *ip;
  unsigned short *port;
  int recsDone = 0;
  while (recsDone++ <= chunks){
    ip   = (unsigned char *) buf+offset;
    port = (unsigned short *) buf+offset+4;
    printf("%s - %d\n",inet_ntoa(*(in_addr*)ip),ntohs(*port));
    offset+=6;
  }
}
