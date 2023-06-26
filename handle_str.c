# include "main.h"

/**
 * handle_str - function that handles 's' the str format specifier
 * @chars: variadic list function
 * @count: pointer variable that iterates in the string
 */

void handle_str(va_list chars, int *count)
{
	char *s;

	s = va_arg(chars, char *);

	while (*s != '\0')
	{
		putchar(*s++);
		++(*count);
	}
}
