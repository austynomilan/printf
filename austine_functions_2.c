#include "main.h"
/**
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char era_c = 0, tab = ' ';
	int nd = BUFF_SIZE - 2, lnth = 2, tab_strt = 1;
	unsigned long numb_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	numb_addrs = (unsigned long)addrs;

	while (numb_addrs > 0)
	{
		buffer[nd--] = map_to[numb_addrs % 16];
		numb_addrs /= 16;
		lnth++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		tab = '0';
	if (flags & F_PLUS)
		era_c = '+', lnth++;
	else if (flags & F_SPACE)
		era_c = ' ', lnth++;
	nd++;

	return (write_pointer(buffer, nd, lnth,
				width, flags, tab, era_c, tab_strt));
}


/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[l] != '\0')
	{
		if (is_printed(str[l]))
			buffer[l + offset] = str[l];
		else
			offset += concat_hex_code(str[l], buffer, l + offset);
		l++;
	}

	buffer[l + offset] = '\0';
	return (write(1, buffer, l + offset));
}

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int d, cnt = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	for (d = 0; str[d]; d++)
		;
	for (d = d - 1; d >= 0; d--)
	{
		char z = str[d];

		write(1, &z, 1);
		cnt++;
	}
	return (cnt);
}


/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char y;
	char *str;
	unsigned int p, q;
	int cnt = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (p = 0; str[p]; p++)
	{
		for (q = 0; in[q]; q++)
		{
			if (in[q] == str[p])
			{
				y = out[q];
				write(1, &y, 1);
				cnt++;
				break;
			}
		}
		if (!in[q])
		{
			y = str[p];
			write(1, &y, 1);
			cnt++;
		}
	}
	return (cnt);
}
