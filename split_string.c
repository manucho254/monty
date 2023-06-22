#include "monty.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

/**
 * separate_string - function to
 *
 * @s: string array
 * @deli: delimeter to use with strtok
 *
 * Return: an array of strings
 */

char **separate_string(char *s, char *deli)
{
	char *portion, *tmp;
	char **code_arr; /** array of string arrays */
	int x = 0, len = 0;

	tmp = strdup(s);
	code_arr = malloc(sizeof(char *));
	if (code_arr == NULL)
	{
		return (NULL);
	}
	portion = strtok(tmp, deli); /** split string using space */
	while (portion != NULL)
	{
		/** reallocate memory to cmd_array */
		code_arr = realloc(code_arr, (x + 1) * sizeof(char *));
		len = strlen(portion);
		code_arr[x] = malloc((len + 1)  * sizeof(char));
		if (code_arr[x] == NULL)
		{
			return (NULL);
		}
		code_arr[x] = strdup(portion);
		code_arr[x][len] = '\0';
		portion = strtok(NULL, deli); /** update value of portion */
		x++;
	}
	code_arr[x] = NULL;
	free(tmp); /** free tmp */
	return (code_arr);
}
