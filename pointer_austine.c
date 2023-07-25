#include <stdio.h>

/**
 * print_pointer - Entry point to the program
 * @ptr: void pointer as parameter
 * Return: number of characters printed
 */

int print_pointer(void *ptr)
{
	return printf("%p", ptr);
}
