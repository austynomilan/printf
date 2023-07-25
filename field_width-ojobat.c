#include<stdio.h>

/**
 * print_field_width - field with for non custom conversion
 * @format: format of
 * @args: argument
 * Return: Always 0
 */

const char *print_field_width(const char *format, va_list args)

{
	int width = 0;
	int i;
	int arg_width = va_arg(args, int);

	if (*format >= '0' && *format <= '9')
	{
	while (*format >= '0' && *format <= '9')
	{
		width = width * 10 + (*format - '0');
		format++;
	}

	if (arg_width > 0)
		width += arg_width;
	else if (arg_width < 0)
		width -= arg_width;
	}
	for (i = 0; i < width; i++)
	putchar(' ');

	return (format);
}
