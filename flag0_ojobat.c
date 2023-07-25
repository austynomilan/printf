#include<stdio.h>

/**
 * print_flag_zero - prints flag character for non custom conversion
 * @format: format of
 * @args: argument
 * Return: Always 0
 */

const char *print_flag_zero(const char *format, va_list args)
{
	int flag_zero = 0;
	int i;
	int width = 0;
	int arg_width = va_arg(args, int);

	if (*format == '0')
	{
		flag_zero = 1;
		format++;
	}
		if (flag_zero)
	{
	if (*format >= '1' && *format <= '9')
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
	putchar('0');
	}

	return (format);
}
