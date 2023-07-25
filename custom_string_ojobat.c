#include<stdio.h>

/**
 * print_custom_string - function to print custom string
 * @s: The string to be printed
 * Return: increment
 */

int print_custom_string(char *s)
{
	int increment = 0;

	for (; *s; s++)
	{
		if (*s < 32 || *s >= 127)
		{
			printf("\\x%02X", *s);
			increment += 4;
		}
		else
		{
			putchar(*s);
			increment++;
		}
	}

	return (increment);
}
