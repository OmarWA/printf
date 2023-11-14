#include "main.h"

int _printf(const char *format, ...)
{
  int printedChars = 0;
  va_list argumentPointer;
  
  va_start(argumentPointer, format);

  
  
  
 printedChars =  write(1, format, strlen(format));


 return printedChars; 

  
}
