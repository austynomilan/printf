#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Size.
 */
int get_size(const char *format, int *i)
{
	int curr_f = *i + 1;
	int sz = 0;

	if (format[curr_f] == 'l')
		sz = S_LONG;
	else if (format[curr_f] == 'h')
		sz = S_SHORT;

	if (sz == 0)
		*i = curr_f - 1;
	else
		*i = curr_f;

	return (sz);
}
