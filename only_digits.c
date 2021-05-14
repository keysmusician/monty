#include "monty.h"
#include <ctype.h>

/**
 * only_digits - check if a string only contains digits
 * @str: string to check
 * Return: 1 if str only contains digits, otherwise 0
 */
int only_digits(const char *str)
{
	size_t i = 0;
	int status = 0;

	if (!str)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
		status = 1;
	}

	return (status);
}
