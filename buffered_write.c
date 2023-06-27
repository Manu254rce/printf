# include "main.h"

/**
 * buffered_write - funcion ha performs buffer handling
 * @fd: integer variable
 * @str: buffer sring variable
 * @len: buffer length
 */

void buffered_write(int fd, const char *str, size_t len)
{
	char buffer[BUFFERSIZE];
	size_t buffer_len = 0;
	size_t i;

	for (i = 0; i < len; i++)
	{
		buffer[buffer_len++] = str[i];
		if (buffer_len == BUFFERSIZE)
		{
			write(fd, buffer, buffer_len);
			buffer_len = 0;
		}
	}

	if (buffer_len > 0)
		write(fd, buffer, buffer_len);
}
