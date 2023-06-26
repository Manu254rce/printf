# include "main.h"

/**
 * unint_to_bin - function that handles the unsigned int to binary conversion
 * @n: int variable that performs conversion
 * @buffer: pointer variable that is an array of the buffer
 */

void unint_to_bin(int n, char *buffer)
{
	char tmp;

	int i = 0;
	int j = 0;
	unsigned int m;

	if (n < 0)
		m = ~(-n) + 1;
	else
		m = n;

	while (m > 0)
	{
		buffer[i++] = (m % 2) + '0';
		m /= 2;
	}

	if (n == 0)
		buffer[i++] = '0';
	if (n < 0)
		buffer[i++] = '1';

	buffer[i] = '\0';

	for (; j < i / 2; ++j)
	{
		tmp = buffer[j];

		buffer[j] = buffer[i - j - 1];

		buffer[i - j - 1] = tmp;
	}
}


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
