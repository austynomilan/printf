#include <stdio.h>
#include <stdarg.h>
#include <main.h>


int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int adder = 0;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					adder++;
					break;
				case 's':
					{
						char *s = va_arg(args, char *);
						while (*s)
						{
							putchar(*s);
							s++;
							adder++;
						}
						break;
					}
				case '%':
					putchar ('%');
					adder++;
					break;
			}
		}
		else
			{
				putchar(*format);
				adder++;
			}
		format++;
	}
	va_end(args);

	return adder++;
}
