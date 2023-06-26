# include "main.h"

/**
 * handle_perc - function that handles '%' specifier
 * @chars: variadic list type
 * @count: pointer that keeps track of values on buffer
 */

void handle_perc(va_list chars, int *count)
{
	(void) chars;
	(void) count;

	putchar('%');
	++(*count);
}
