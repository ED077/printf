#include "main.h"

/**
 *  * is_printable - Checks if a character is printable.
 *   * @c: The character to evaluate.
 *    *
 *     * Return: 1 if 'c' is printable, 0 otherwise.
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	return (1);

	return (0);
}

/**
 *  * append_hexa_code - Appends the ASCII code in hexadecimal format
 *   * @buffer: Character array.
 *    * @i: Starting index for appending.
 *     * @ascii_code: ASCII code.
 *      *
 *       * Return: Always 3.
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 *  * is_digit - Checks if a character is a digit.
 *   * @c: The character to evaluate.
 *    *
 *     * Return: 1 if 'c' is a digit, 0 otherwise.
*/
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
	return (1);

	return (0);
}

/**
 *  * convert_size_number - Casts a number to the specified size.
 *   * @num: The number to be cast.
 *    * @size: The size specifier for the cast.
 *     *
 *      * Return: The casted value of 'num'.
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((short)num);

	return ((int)num);
}

/**
 *  * convert_size_unsgnd - Casts an unsigned number to the specified size.
 *   * @num: The unsigned number to be cast.
 *    * @size: The size specifier for the cast.
 *     *
 *      * Return: The casted value of 'num'.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((unsigned short)num);

	return ((unsigned int)num);
}
