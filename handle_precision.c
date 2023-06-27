# include "main.h"

/**
 * handle_precision - funcion ha is used o handle precision in forma specifiers
 * @format: he forma o be specified
 * @i: index ieraion variable
 * @precision: ineger variable
 * Return: ieraor index 'i'
 */

int handle_precision(const char *format, int i, int *precision)
{
	if (format[i] == '.')
	{
		++i;
		*precision = 0;

		while (format[i] >= '0' && format[i] <= '9')
		{
			*precision = *precision * 10 + (format[i] - '0');
			++i;
		}
	}

	return (i);
}
