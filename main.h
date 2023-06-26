# ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <ctype.h>

# define BUFFERSIZE 1024

/**
 * struct dtypes - structure variable defining our format specifiers
 * @specifier: pointer to specifier value
 * @handler: pointer function to handler functions
 */

typedef struct dtypes
{
	char *specifier;
	void (*handler)(va_list, int *);
}_fmt;

int _printf(const char *format, ...);

void handle_char(va_list chars, int *count);
void handle_str(va_list chars, int *count);
void handle_int(va_list chars, int *count);
void handle_bin(va_list chars, int *count);
void handle_octal(va_list chars, int *count);
void handle_hex_lower(va_list chars, int *count);
void handle_hex_upper(va_list chars, int *count);
void handle_unsigned(va_list chars, int *count);
void handle_ptr(va_list chars, int *count);
void handle_perc(va_list chars, int *count);

# endif
