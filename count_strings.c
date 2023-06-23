#include "monty.h"
#include <string.h>

/**
 * count_strings - calcute the number of strings,
 * after splitting a string.
 *
 *
 * @s: pointer to string
 * @deli: delimeter to use with strtok
 *
 * Return: string count
 */

int count_strings(char *s, char *deli)
{
	char *portion;
	int count = 0;

	if (s == NULL)
	{
		return (0);
	}
	portion = strtok(s, deli);
	while (portion != NULL)
	{
		portion = strtok(NULL, deli); /** update value of portion */
		count++;
	}

	return (count);
}
