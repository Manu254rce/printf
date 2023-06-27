# include "main.h"

/**
 * handle_unsigned - function that handles 'u' format specifiers
 * for unsigned numbers
 * @chars: variadic list type
 * @count: pointer to variable that tracks values
 */

void handle_unsigned(va_list chars, int *count)
{
	int i;
	unsigned int u;
	char buffer[20];

	u = va_arg(chars, unsigned int);
	i = sprintf(buffer, "%u", u);

	for (i = 0; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}
