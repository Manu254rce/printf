# include "main.h"

/**
 * handle_hex_lower - function that handles 'x' format specifiers
 * for hex numbers
 * @chars: variadic list type
 * @count: pointer to variable that tracks values
 */

void handle_hex_lower(va_list chars, int *count)
{
	int i;
	unsigned int x;
	char buffer[20];

	x = va_arg(chars, unsigned int);

	sprintf(buffer, "%x", x);

	for (i = 0; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}

