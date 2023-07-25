#include <stdio.h>


/**
  *print_binary - Entry point to the program
  *@num: the number parameter
  *Return: always 0 (success)
  */

int print_binary(int num)
{
	int bin[32];
	int inertia;
	int z;

	if (num == 0)
	{
		putchar('0');
		return (1);
	}
	do
	{
		bin[inertia++] = num & 1;
		num >>= 1;
	}
	while (num > 0);
	
	for (z = inertia - 1; z >= 0; z--)
	{
		putchar(bin[z] + '0');
	}

	return (inertia);
}
