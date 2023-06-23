#include "monty.h"
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/**
 * is_number - function to check if string contains only numbers.
 *
 * @s: string to check
 *
 * Return: True if all values in string are numbers else false.
 */

bool is_number(char *s)
{
	unsigned int x;

	if (strcmp(s, "0") == 0)
		return (true);

	for (x = 0; s[x] != '\0'; x++)
	{
		if (s[x] == '-')
			continue;
		if (!isdigit(s[x]))
		{
			return (false);
		}
	}

	return (true);
}
