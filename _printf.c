#include "main.h"

int _printf(const char *format, ...)
{
  int printedChars = 0;
  va_list argumentPointer;
  int stringIndex = 0;
  int argumentsCount = 0;
  
  va_start(argumentPointer, format);

  while (format[stringIndex] != '\0')
    {
      if (format[stringIndex] == '%')
	{
	  argumentsCount++;
	  if(format[stringIndex + 1] == '%')
	    {
	      stringIndex += 2;
	      continue;
	    }
	}
  stringIndex++;
  }
  /* By this point, the variable stringIndex shall carries the length of the format string*/
  printf("The length of the passed string:\t%d\nThe number of arguments:\t%d\n", stringIndex, argumentsCount);
  /* printedChars =  write(1, format, strlen(format));*/


  return printedChars; 

  
}
