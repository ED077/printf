#include "main.h"

/**
 * get_flags - Determine active formatting flags
 * @format: The formatted string for argument printing
 * @i: Current index in the format string
 * Return: The active formatting flags
 */
int get_flags(const char *format, int *i)
{
	/* Flags mapping: '-' '+' '0' '#' ' ' */
	/* Corresponding values: 1   2   4   8   16  */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
	for (j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
	{
	if (format[curr_i] == FLAGS_CHARACTERS[j])
		{
		flags |= FLAGS_VALUES[j];
		break;
		}
	}

	if (FLAGS_CHARACTERS[j] == 0)
	break;
	}

	*i = curr_i - 1;

	return (flags);
}
