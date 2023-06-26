# include "main.h"

/**
 * handle_bin - function that handles 'b' the binary format specifier
 * @chars: variadic list type
 * @count: pointer variable that tracks values stored in buffer
 */

void handle_bin(va_list chars, int *count)
{
	unsigned int b = va_arg(chars, unsigned int);
	char buffer[33];

	int i = 0;

	unint_to_bin(b, buffer);

	for (; buffer[i] != '\0'; ++i)
	{
		putchar(buffer[i]);
		++(*count);
	}
}

/**
 * unint_to_bin - function that handles the unsigned int to binary conversion
 * @n: int variable that performs conversion
 * @buffer: pointer variable that is an array of the buffer
 */

void unint_to_bin(unsigned int n, char *buffer)
{
	int i = 0;
	int j = 0;

	while (n > 0)
	{
		buffer[++i] = (n % 2) + '0';
		n /= 2;
	}

	buffer[i] = '\0';

	for (; j < i / 2; ++j)
	{
		char tmp = buffer[j];

		buffer[j] = buffer[i - j - 1];

		buffer[i - j - 1] = tmp;
	}
}
