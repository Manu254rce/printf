# include "main.h"

/**
 * handle_char - function that handles 'c' the char fmt specifier
 * @chars: variadic list type
 * @count: pointer variable tracking count
 */

void handle_char(va_list chars, int *count)
{
	char c;

	c = va_arg(chars, int);

	putchar(c);

	++(*count);
}
