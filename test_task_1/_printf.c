#include "main.h"

int _printf(const char *format, ...)
{
  int printedChars = 0;
  va_list argumentPointer;
  int stringIndex = 0;
  int argumentsCount = 0;
  /*int argumentsIterator = 0;*/
  char tempBuffer[2048];
  int bufferIterator = 0;
  char* stringArgumentPointer;
  int stringArgumentIndex = 0;

  while (bufferIterator < 2048)
    {
      tempBuffer[bufferIterator] = '~';
      bufferIterator++;
    }
  bufferIterator = 0;

  
  
  va_start(argumentPointer, format);

  while (format[stringIndex] != '\0')
    {
      if (format[stringIndex] == '%')
	{
	  argumentsCount++;
	  if(format[stringIndex + 1] == 'c')
	    {
	      tempBuffer[stringIndex] = (char) va_arg(argumentPointer, int);
	    }
	  else if(format[stringIndex + 1] == 's')
	    {
	      stringArgumentPointer = va_arg(argumentPointer, char*);
	      while (stringArgumentPointer[stringArgumentIndex] != '\0')
		{
		  tempBuffer[stringIndex + stringArgumentIndex] = stringArgumentPointer[stringArgumentIndex];
		  stringArgumentIndex++;
		}
	      stringArgumentIndex = 0;
	    }
	  if(format[stringIndex + 1] == '%')
	    {
	      tempBuffer[stringIndex] = '%';
	      stringIndex += 2;
	      continue;
	    }
	}
  stringIndex++;
  }
  /* By this point, the variable stringIndex shall carries the length of the format string*/

  while (bufferIterator < 2048)
    {
      printf("%c\n", tempBuffer[bufferIterator]);
      bufferIterator++;
    }
  
  /*while (argumentsIterator < argumentsCount)
    {
      
    }*/



  /*printf("The length of the passed string:\t%d\nThe number of arguments:\t%d\n", stringIndex, argumentsCount);*/

  /* printedChars =  write(1, format, strlen(format));*/


  return printedChars; 

  
}
