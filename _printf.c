#include "main.h"

int _printf(const char *format, ...)
{
  int printedChars = 0;
  va_list argumentPointer;
  int stringIndex = 0;
  /* int argumentsCount = 0;*/
  
  va_start(argumentPointer, format);

  while (format[stringIndex] != '\0')
   {
      printf("char: %c$; ASCII: %d\n", format[stringIndex], format[stringIndex]);
  stringIndex++;
  }
  
  /* printedChars =  write(1, format, strlen(format));*/


 return printedChars; 

  
}
