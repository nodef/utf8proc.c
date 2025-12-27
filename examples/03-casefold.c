// Example 3: Casefold a UTF-8 string
#define UTF8PROC_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <utf8proc.h>


int main() {
  utf8proc_uint8_t input[] = "Straße"; // German word for "street"
  utf8proc_uint8_t *casefolded;

  utf8proc_ssize_t result = utf8proc_map(input, 0, &casefolded,
                                         UTF8PROC_NULLTERM | UTF8PROC_CASEFOLD);
  if (result < 0) {
    printf("Error during casefolding\n");
    return 1;
  }

  printf("Original: %s\n", input);
  printf("Casefolded: %s\n", casefolded);

  free(casefolded);
  return 0;
}
