#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

int print_char(int c);
int print_string(char *s);
int print_percent(void);
int print_binary(int num);

/**
  *_printf - Entry point to the program
  *@format: format pointer
  *Return: the printed item
  */

int _printf(const char *format, ...)
{
	int adder = 0;
	va_list args;
	int width = 0;
	int plus_flag;
	int space_flag;
	int hash_flag;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			while (*format == '+' || *format == ' ' || *format == '#')
			{
				if (*format == '+')
				{
					plus_flag = 1;
				}
				else if (*format == ' ')
				{
					space_flag = 1;
				}
				else if (*format == '#')
				{
					hash_flag = 1;
				}
				format++;
			}

			while (*format >= '0' && *format <= '9')
			{
				width = (width * 10) + (*format - '0');
				format++;
			}

			switch (*format)
			{
				case 'c':

					adder = adder + print_char(va_arg(args, int));
					break;
				case 's':
					adder = adder + print_string(va_arg(args, char *));
					break;
				case '%':
					adder = adder + print_percent();
					break;
				case 'b':
					adder = adder + print_binary(va_arg(args, int));
					break;
				case 'p':
					adder = adder + print_pointer(va_arg(args, void *));
					break;
				case 'd':
				case 'i':
					adder = adder + print_integer(va_arg(args, int));
					break;
				case 'u':
					adder = adder + print_unsigned_int(va_arg(args, unsigned int), 10, 0, 0);
					break;
				case 'o':
					adder = adder + print_unsigned_int(va_arg(args, unsigned int), 8, 0, 0);
					break;
				case 'x':
					adder = adder + print_unsigned_int(va_arg(args, unsigned int), 16, 1, 1);
					break;
				case 'X':
					adder = adder + print_unsigned_int(va_arg(args, unsigned int), 16, 0, 0);
					break;
				case 'S':
					 adder = adder + print_custom_string(va_arg(args, char *));
					 break;

			}
		}
		else
		{
			adder = adder + print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (adder);
}

/**
  *print_char - Entry point to the program
  *@c: the charater as paremter
  *Return: Always 1 (success)
  */

int print_char(int c)
{
	static char buffer[BUFFER_SIZE];
	static size_t x;

	if (x >= sizeof(buffer))
	{
		write(STDOUT_FILENO, buffer, x);
			x = 0;
	}
	buffer[x++] = c;
	return (1);
}

/**
  *print_string - Entry point to the program
  *@s: pointer to string as parameter
  *Return: always 0 (success)
  */


int print_string(char *s)
{
	static char buffer[BUFFER_SIZE];
	int increment = 0;
	static size_t x;

	while (*s)
	{
		buffer[x++] = *s++;
		increment++;
		if (x  == sizeof(buffer))
		{
			write(STDOUT_FILENO, buffer, sizeof(buffer));
			x = 0;
		}
	}
	return (increment);
}

/**
  *print_percent - Entry point to the program
  *Return: ...
  */

int print_percent(void)
{
	putchar('%');
	return (1);
}
