// Example 2: Decode a UTF-8 string into Unicode codepoints
#define UTF8PROC_IMPLEMENTATION
#include <stdio.h>
#include <utf8proc.h>


int main() {
  utf8proc_uint8_t utf8_str[] = "Hello, 😀!";
  utf8proc_int32_t codepoint;
  utf8proc_ssize_t len;
  utf8proc_uint8_t *ptr = utf8_str;

  printf("Decoding UTF-8 string: %s\n", utf8_str);
  while (*ptr) {
    len = utf8proc_iterate(ptr, -1, &codepoint);
    if (len < 0) {
      printf("Invalid UTF-8 sequence\n");
      return 1;
    }
    printf("Codepoint: U+%04X\n", codepoint);
    ptr += len;
  }

  return 0;
}
