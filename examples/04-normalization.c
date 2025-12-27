// Example 4: Normalize a UTF-8 string to NFC and NFD
#define UTF8PROC_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <utf8proc.h>


int main() {
  utf8proc_uint8_t input[] =
      "a\u0308o\u0308u\u0308"; // "äöü" via combining characters
  utf8proc_uint8_t *nfc, *nfd;

  nfd = utf8proc_NFD(input);
  nfc = utf8proc_NFC(nfd);

  printf("Original: %s\n", input);
  printf("NFD: %s\n", nfd);
  printf("NFC: %s\n", nfc);

  free(nfd);
  free(nfc);
  return 0;
}
