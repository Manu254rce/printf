# include "main.h"

/**
 * format_str - funcion ha handles he ieraion for specifing formas
 * @format: he forma specified
 * @chars: variadic lis pe
 * @type_list: sruc for he formas
 * @count: poiner ha keeps rack of characers
 */

void format_str(const char *format, va_list chars, _fmt *type_list, int *count)
{
	int i, j;
	char buffer[BUFFERSIZE];
	size_t buffer_len = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			++i;
			for (j = 0; type_list[j].specifier != NULL; j++)
			{
				if (*type_list[j].specifier == format[i])
				{
					if (buffer_len > 0)
					{
						buffered_write(STDOUT_FILENO, buffer, buffer_len);
						buffer_len = 0;
					}
					type_list[j].handler(chars, count);
					break;
				}
			}
		}
		else
		{
			buffer[buffer_len++] = format[i];
			if (buffer_len == BUFFERSIZE)
			{
				buffered_write(STDOUT_FILENO, buffer, buffer_len);
				buffer_len = 0;
			}
		}
	}

	if (buffer_len > 0)
		buffered_write(STDOUT_FILENO, buffer, buffer_len);
}

/**
 * _printf - function that printd output given a format specifier
 * @format: character argument
 * Return: 'count' the number of strings printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list chars;

	_fmt type_list[] = {
		{"c", handle_char},
		{"s", handle_str},
		{"d", handle_int},
		{"i", handle_int},
		{"u", handle_unsigned},
		{"b", handle_bin},
		{"o", handle_octal},
		{"x", handle_hex_lower},
		{"X", handle_hex_upper},
		{"p", handle_ptr},
		{"r", handle_revstr},
		{"R", handle_rot13ed},
		{"%", handle_perc},
		{NULL, NULL}
	};

	va_start(chars, format);
	format_str(format, chars, type_list, &count);

	va_end(chars);

	return (count);
}

