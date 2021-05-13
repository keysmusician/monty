#include "monty.h"
#include <ctype.h>

/**
 * only_digits - check if a string only contains digits
 * @str: string to check
 * Return: 1 if str only contains digits, otherwise 0
 */
int only_digits(const char *str)
{
	size_t i;

	for (i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
