#include<stdio.h>

/**
 * handle_flags - function to handle flags
 * @plus_flag: Addition flag
 * @space_flag: Space flag
 * @hash_flag: Hash
 * @specifier: Add Specifier
 * Return: Always 0
 */

void handle_flags(int plus_flag, int space_flag, int hash_flag, char specifier)
{
	if (plus_flag && (specifier == 'd' || specifier == 'i'))
	{
		putchar('+');
	}
	else if (space_flag && (specifier == 'd' || specifier == 'i'))
	{
		putchar(' ');
	}
	else if (hash_flag && specifier == 'o')
	{
		putchar('0');
	}
	else if (hash_flag && (specifier == 'x' || specifier == 'X'))
	{
		putchar('0');
		putchar(specifier);
	}
}
