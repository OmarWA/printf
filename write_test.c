#include "main.h"

int main(void)
{

  char *text = "Hello, Write()!\n";

  long unsigned int text_length = strlen(text);

  long unsigned int print_count = write(1, text, text_length);

  printf("Original text count of \"text\"is: %ld\nWrite()'s print count is: %ld\n", strlen(text), print_count);

  
  
  return (0);
}
