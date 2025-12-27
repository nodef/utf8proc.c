// Example 1: Convert a Unicode codepoint to a UTF-8 string
#define UTF8PROC_IMPLEMENTATION
#include <stdio.h>
#include <utf8proc.h>


int main() {
  utf8proc_int32_t codepoint = 0x1F600; // Unicode codepoint for 😀
  utf8proc_uint8_t utf8_str[5] = {0};   // UTF-8 string buffer

  utf8proc_ssize_t len = utf8proc_encode_char(codepoint, utf8_str);
  if (len > 0) {
    printf("Codepoint U+%04X encoded as UTF-8: %s\n", codepoint, utf8_str);
  } else {
    printf("Failed to encode codepoint U+%04X\n", codepoint);
  }

  return 0;
}
