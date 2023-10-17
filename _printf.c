#include "main.h"

void write_buffer(char buffer[], int *buff_index);

/**
 * _printf - Printf function
 * @format: Format string.
 * Return: Number of printed characters.
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list arg_list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
	{
		buffer[buff_index++] = format[i];
		if (buff_index == BUFF_SIZE)
		write_buffer(buffer, &buff_index);
		printed_chars++;
	}
	else
		{
		write_buffer(buffer, &buff_index);
		flags = get_flags(format, &i);
		width = get_width(format, &i, arg_list);
		precision = get_precision(format, &i, arg_list);
		size = get_size(format, &i);
		++i;
		printed_chars += handle_print(format, &i, arg_list, buffer,
		flags, width, precision, size);
		if (printed_chars == -1)
		return (-1);
		}
	}

	write_buffer(buffer, &buff_index);

	va_end(arg_list);

	return (printed_chars);
}

/**
* write_buffer - Writes the contents of the buffer if it exists
* @buffer: Array of characters.
* @buff_index: Index to add the next character, representing the length.
*/
void write_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
	write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
