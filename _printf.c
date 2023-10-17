#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
* _printf - Implementation of printf
* @format: Format string.
* Return: Number of characters printed.
*/
int _printf(const char *format, ...)
{
	int i, total_printed_chars = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
	if (format[i] != '%')
	{
	buffer[buffer_index++] = format[i];
	if (buffer_index == BUFF_SIZE)
		flush_buffer(buffer, &buffer_index);
		total_printed_chars++;
	}
	else
	{
	flush_buffer(buffer, &buffer_index);
	flags = get_flags(format, &i);
	width = get_width(format, &i, args);
	precision = get_precision(format, &i, args);
	size = get_size(format, &i);
	++i;
	total_printed_chars += handle_print(format, &i, args, buffer,
	flags, width, precision, size);
	if (total_printed_chars == -1)
		return (-1);
	}
	}

	flush_buffer(buffer, &buffer_index);

	va_end(args);

	return (total_printed_chars);
}

/**
* flush_buffer - Writes the contents of the buffer if it exists
* @buffer: Array of characters.
* @buffer_index: Index for the next character, representing the length.
*/
void flush_buffer(char buffer[], int *buffer_index)
{
if (*buffer_index > 0)
	write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
