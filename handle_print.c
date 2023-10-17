#include "main.h"

/**
 * * handle_unknown_format - Handles unknown format specifiers.
 * * @fmt: Formatted string in which to print the arguments.
 * * @ind: List of arguments to be printed.
 * * @buffer: Buffer array to handle print.
 * * @width: Width specifier.
 * *
 * * Return: Number of characters printed for unknown format specifiers.
*/

int handle_unknown_format(const char *fmt, int *ind, char buffer[], int width)
{
	int unknown_len = 0;

	unknown_len += write(1, "%%", 1);

	if (fmt[*ind - 1] == ' ')
{
	unknown_len += write(1, " ", 1);
}
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
{
--(*ind);
}
	if (fmt[*ind] == ' ')
{
	--(*ind);
}
	unknown_len++;
	}

	return (unknown_len);
}

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
	int unknown_len = 0;
	fmt_t fmt_types[] = {
	{'c', print_char}, {'s', print_string}, {'%', print_percent},
	{'i', print_int}, {'d', print_int}, {'b', print_binary},
	{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
	{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
	{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};

	for (int i = 0; fmt_types[i].fmt != '\0'; i++)
{
	if (fmt[*ind] == fmt_types[i].fmt)
{
	return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}
	}

	if (fmt_types[i].fmt == '\0')
{
	if (fmt[*ind] == '\0')
{
	return (-1);
	}

	unknown_len += handle_unknown_format(fmt, ind, buffer, width);
	unknown_len += write(1, &fmt[*ind], 1);

	return (unknown_len);
	}

	return (-1);
}
