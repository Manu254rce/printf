# include "main.h"

/**
 * _printf - function that printd output given a format specifier
 * @format: character argument
 * Return: 'count' the number of strings printed
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int i, j;
	va_list chars;

	_fmt type_list[] = {
		{"c", handle_char},
		{"s", handle_str},
		{"d", handle_int},
		{"i", handle_int},
		{"b", handle_bin},
		{"o", handle_octal},
		{"x", handle_hex_lower},
		{"X", handle_hex_upper},
		{"p", handle_ptr}
		{NULL, NULL}
	};

	va_start(chars, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			++i;
			for (j = 0; type_list[j].specifier != NULL; j++)
			{
				if (*type_list[j].specifier == format[i])
				{
					type_list[j].handler(chars, &count);
					break;
				}
			}
		}
		else
		{
			putchar(format[i])
		}
	}
	va_end(chars);
	return (count);
}
