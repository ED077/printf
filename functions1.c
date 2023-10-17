#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Outputs an unsigned number
 * @types: Argument list
 * @buffer: Buffer array for printing
 * @flags: Flag calculations
 * @width: Retrieve width
 * @precision: Precision setting
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 10) + '0';
	num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Outputs an unsigned number in octal format
 * @types: Argument list
 * @buffer: Buffer array for printing
 * @flags: Flag calculations
 * @width: Retrieve width
 * @precision: Precision setting
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 8) + '0';
	num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
	buffer[i--] = '0';

	i++;

return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Outputs an unsigned number in hexadecimal format
 * @types: Argument list
 * @buffer: Buffer array for printing
 * @flags: Flag calculations
 * @width: Retrieve width
 * @precision: Precision setting
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Outputs an unsigned number in uppercase hexadecimal
 *format
 * @types: Argument list
 * @buffer: Buffer array for printing
 * @flags: Flag calculations
 * @width: Retrieve width
 * @precision: Precision setting
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags, 'X',
width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Outputs a hexadecimal number in lowercase or uppercase
 * @types: Argument list
 * @map_to: Array of values for mapping the number
 * @buffer: Buffer array for printing
 * @flags: Flag calculations
 * @flag_ch: Flag calculations
 * @width: Retrieve width
 * @precision: Precision setting
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int flags,
char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = map_to[num % 16];
	num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
	buffer[i--] = flag_ch;
	buffer[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
