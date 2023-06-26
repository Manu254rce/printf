# include "main.h"

/**
 * handle_revstr - program that handles 'r' the format
 * specifier for reversed string
 * @chars: variadic list function
 * @count: pointer that tracks characters
 */

void handle_revstr(va_list chars, int *count)
{
	char *str = va_arg(chars, char *);
	int length = 0;
	int i;

	if (str == NULL)
		return;

	while (str[length] != '\0')
		length++;

	for (i = length - 1; i >= 0; i--)
	{
		putchar(str[i]);
		++(*count);
	}
}
