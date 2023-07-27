#include "main.h"
/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	char q = va_arg(types, int);
	return (handle_write_char(q, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int lnth = 0, p;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[lnth] != '\0')
		lnth++;
	if (precision >= 0 && precision < lnth)
		lnth = precision;

	if (width > lnth)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], lnth);
			for (p = width - lnth; p > 0; p--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (p = width - lnth; p > 0; p--)
				write(1, " ", 1);
			write(1, &str[0], lnth);
			return (width);
		}
	}
	return (write(1, str, lnth));
}

/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	int v = BUFF_SIZE - 2;
	int is_neg = 0;
	long int m = va_arg(types, long int);
	unsigned long int numb;

	m = convert_size_number(m, size);

	if (m == 0)
		buffer[v--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)m;

	if (m < 0)
	{
		numb = (unsigned long int)((-1) * m);
		is_neg = 1;
	}

	while (numb > 0)
	{
		buffer[v--] = (numb % 10) + '0';
		numb /= 10;
	}
	v++;

	return (write_number(is_neg, v, buffer, flags, width, precision, size));
}


/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
	unsigned int p, q, r, sum;
	unsigned int x[32];
	int cnt;
	

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	p = va_arg(types, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	x[0] = p / q;
	for (r = 1; r < 32; r++)
	{
		q /= 2;
		x[r] = (p / q) % 2;
	}
	for (r = 0, sum = 0, cnt = 0; r < 32; r++)
	{
		sum += x[r];
		if (sum || r == 31)
		{
			char w = '0' + x[r];

			write(1, &w, sizeof(w));
			cnt++;
		}
	}
	return (cnt);
}
