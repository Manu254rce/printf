# include "main.h"

/**
 * handle_int - function that handles 'd' and 'i' specifeiers for integers
 * @chars: variadic list type
 * @count: pointer that keeps track of values on buffer
 */

void handle_int(va_list chars, int *count)
{
	char d, buffer[20];
	int i;

	d = va_arg(chars, int);
	sprintf(buffer, "%d", d);

	for (i = 0; i != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}
