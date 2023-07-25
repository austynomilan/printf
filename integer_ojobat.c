#include <stdio.h>

/**
 * print_integer - Helper function to handle d and i specifiers
 * @num: The integer to be printed
 * Return: The number characters printed
 */

int print_integer(int num)
{
	int index = 0;
	int adder = 0;
	char buffer[BUFFER_SIZE];

	if (num < 0)
	{
		print_char('-');
		num = -num;
	}
	do {
		buffer[index++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);
	for (int i = index - 1; i >= 0; i--)
	{
		adder += print_char(buffer[i]);
	}
	return (adder);
}
