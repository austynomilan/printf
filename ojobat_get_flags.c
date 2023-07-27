#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flg:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int ft, curr_f;
	int flg = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_f = *i + 1; format[curr_f] != '\0'; curr_f++)
	{
		for (ft = 0; FLAGS_CH[ft] != '\0'; ft++)
			if (format[curr_ft] == FLAGS_CH[ft])
			{
				flg |= FLAGS_ARR[ft];
				break;
			}

		if (FLAGS_CH[ft] == 0)
			break;
	}

	*i = curr_f - 1;

	return (flg);
}
