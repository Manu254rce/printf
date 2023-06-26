# include "main.h"

/**
 * handle_rot13ed - function that handles 'R' the rot13 cipher format specifier
 * @chars: variadic list function
 * @count: pointer that keeps track of characters
 */

void handle_rot13ed(va_list chars, int *count)
{
	char *str = va_arg(chars, char *);
	int i;

	if (str == NULL)
		return;

	for (i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			putchar('a' + (str[i] - 'a' + 13) % 26);
		else if (str[i] >= 'A' && str[i] <= 'Z')
			putchar('A' + (str[i] - 'A' + 13) % 26);
		else
			putchar(str[i]);

		++(*count);
	}
}
