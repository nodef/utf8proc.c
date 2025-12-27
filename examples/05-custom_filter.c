// Example 5: Custom filter to remove non-ASCII characters
#define UTF8PROC_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <utf8proc.h>


utf8proc_int32_t filter_non_ascii(utf8proc_int32_t codepoint, void *data) {
  return codepoint < 128? codepoint : 0;
}

int main() {
  utf8proc_uint8_t input[] = "Hello, 😀!";
  utf8proc_uint8_t *filtered;

  utf8proc_ssize_t result = utf8proc_map_custom(
      input, 0, &filtered, UTF8PROC_NULLTERM, filter_non_ascii, NULL); // Pass NULL as custom_data
  if (result < 0) {
    printf("Error during filtering\n");
    return 1;
  }

  printf("Original: %s\n", input);
  printf("Filtered: %s\n", filtered);

  free(filtered);
  return 0;
}
