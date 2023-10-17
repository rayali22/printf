#include "main.h"

/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
**/

int _printf(const char * const format, ...)
{
	int a, b, n, length = 0;

	spec_func options[] = {
		{"%c", print_one_char}, {"%s", print_string},
		{"%%", print_percent}, {"%d", print_signed_int},
		{"%i", print_unsigned_int}, {"%u", print_custom_unsigned},
		{"%o", print_octal}, {"%x", print_hex_lowercase},
		{"%X", print_hex_uppercase}, {"%b", print_binary},
		{"%p", print_pointer}, {"%S", print_s}, {"%R", print_rot}, {NULL, NULL}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
