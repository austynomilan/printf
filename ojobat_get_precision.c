#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_f = *i + 1;
	int prsc = -1;

	if (format[curr_f] != '.')
		return (prsc);

	prsc = 0;

	for (curr_f += 1; format[curr_f] != '\0'; curr_f++)
	{
		if (is_digit(format[curr_f]))
		{
			prsc *= 10;
			prsc += format[curr_f] - '0';
		}
		else if (format[curr_f] == '*')
		{
			curr_f++;
			prsc = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_f - 1;

	return (prsc);
}
