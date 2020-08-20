#include <stdio.h>

#define WIDTH 16

int main (int argc, char **argv) {
  int offset = 0;
  FILE *fp;
  int byte;
  char buffer[WIDTH] = ""; // This buffer will store the data read, essentially concatenating it

  if (argc < 2)
    return 1;

  if (fp = fopen(argv[1], "rb")) {
    for(;;) {
      byte = fgetc(fp); // get the next byte

      if (byte == EOF) { // did we read over the end of the file?
	if (offset % WIDTH)
	  printf("%*s %*.*s", 3 * (WIDTH - offset % WIDTH), "", offset % WIDTH, offset % WIDTH, buffer);
	else
	  printf("\n");
	return 0;
      }

      if (offset % WIDTH == 0) { // should we print the offset?
	if (offset)
	  printf(" %*.*s", WIDTH, WIDTH, buffer); // print the char representation of the last line
	printf("\n0x%08x", offset);
      }

      // print the hex representation of the current byte
      printf(" %02x", byte);

      // add printable characters to our buffer
      if (byte >= ' ')
	buffer[offset % WIDTH] = byte;
      else
	buffer[offset % WIDTH] = '.';

      // move the offset
      ++offset;
    }
    fclose(fp);
  }
  return 0;
}
