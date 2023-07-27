#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_f;
	int wdth = 0;

	for (curr_f = *i + 1; format[curr_f] != '\0'; curr_f++)
	{
		if (is_digit(format[curr_f]))
		{
			wdth *= 10;
			wdth += format[curr_f] - '0';
		}
		else if (format[curr_f] == '*')
		{
			curr_i++;
			wdth = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_f - 1;

	return (wdth);
}
