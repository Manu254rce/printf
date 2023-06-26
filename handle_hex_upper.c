# include "main.h"

/**
 * handle_hex_upper - function that handles 'X' format specifiers
 * for hex numbers
 * @chars: variadic list type
 * @count: pointer to variable that tracks values
 */

void handle_hex_upper(va_list chars, int *count)
{
	int i;
	unsigned int X;
	char buffer[20];

	X = va_arg(chars, unsigned int);

	sprintf(buffer, "%X", X);

	for (i = 0; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}
