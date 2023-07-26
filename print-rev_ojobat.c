#include <stdio.h>
#include <string.h>

/**
 * print_reversed_string - prints the string in reverse
 * @s: string to be printed
 * Return: Always 0
 */

void print_reversed_string(char *s)
{
	int i;
	int len = strlen(s);

	for (i = len - 1; i >= 0; i--)
	putchar(s[i]);
}
