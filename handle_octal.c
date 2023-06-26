# include "main.h"

/**
 * handle_octal - function that handles 'o' format specifiers
 * for octal numbers
 * @chars: variadic list type
 * @count: pointer to variable that tracks values
 */

void handle_octal(va_list chars, int *count)
{
	int i;
	unsigned int o;
	char buffer[20];

	o = va_arg(chars, unsigned int);

	sprintf(buffer, "%o", o);

	for (i = 0; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}
