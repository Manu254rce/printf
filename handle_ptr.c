# include "main.h"

/**
 * handle_ptr - function that handles 'p' the pointer format specifier
 * @chars: variadic list type
 * @count: pointer to keep track of values
 */

void handle_ptr(va_list chars, int *count)
{
	void *p;
	char buffer[20];
	int i = 0;

	p = va_arg(chars, void *);
	sprintf(buffer, "%p", p);

	for (; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}
