#include<stdio.h>

/**
 * print_unsigned_int - Function to handle u, o, x, X identifiers
 * @n: print n
 * @base: print base 10
 * @lowercase: print lowercase alphabet
 * Return: Always 0.
 */

int print_unsigned_int(unsigned int n, int base, int lowercase)

{
	char buffer[32];
	int i = 0;

	if (n == 0)
	{
	putchar('0');
	return (1);
	}
	while (n > 0)
	{
	int digit = n % base;

	buffer[i++] = digit < 10 ? '0' + digit : (lowercase ? 'a' : 'A') + digit - 10;

	n /= base;
	}

	while (i > 0)
		{
		putchar(buffer[--i]);
		}
	return (i);
}
