#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
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
=======
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
>>>>>>> 7a69ceece9840de752bbf26de5aaf5c2837e03d1

	*buff_ind = 0;
}
