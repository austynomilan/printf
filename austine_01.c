#include "main.h"

void print_buffer(char buffer[], int *buffy_in);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _print(const char *format, ...)
{
	int w, pnted = 0, pnted_chrs = 0;
	int flags, width, precesion, size, buffy_in = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	IF (format == NULL)
		return (-1);

	va_start(list, format);

	for (w = 0; format && format[w] != '\0'; w++)
	{
		if (format[w] != '%')
		{
			buffer[buffy_in++] = format[w];
			if (buffy_in == BUFFER_SIZE)
			print_buffer(buffer, &buffy_in);

			pnted_chrs++;
		}
		else
		{
			print_buffer(buffer, &buffy_in);
			flags = get_flags(format, &w);
			width = get_width(format, &w, list);
			precision = get_precision(format, &w, list);
			size = get_size(format, &w);
			++w;
			pnted = handle_print(format, &w, list, buffer, flags, width, precision, size);
		
			if (pnted == -1)
				return (-1);
			pnted_chrs += pnted;
		}
	}
	print_buffer(buffer, &buffy_in);

	va_end(list);

	return (pnted_chrs);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buffy_in)
{
	if (*buffy_in > 0)
		write(1, &buffer[0], *buffy_in);
	*buffy_in = 0;
}
