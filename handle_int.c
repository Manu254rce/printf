# include "main.h"

/**
 * handle_int - function that handles 'd' and 'i' specifeiers for integers
 * @chars: variadic list type
 * @count: pointer that keeps track of values on buffer
 */

void handle_int(va_list chars, int *count)
{
	char *buffer;
	int i, d, length;

	if (chars == NULL)
		return;

	d = va_arg(chars, int);
	length = snprintf(NULL, 0, "%d", d);
	buffer = malloc(length + 1);

	if (buffer == NULL)
		return;

	if (sprintf(buffer, "%d", d) < 0)
	{
		free(buffer);
		return;
	}

	for (i = 0; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}

	free(buffer);
}
