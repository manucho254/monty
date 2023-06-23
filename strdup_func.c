#include "monty.h"
#include <string.h>
#include <stdlib.h>

/**
 * strdup - function to duplicate string
 *
 * @src: pointer to source string
 *
 * Return: pointer to new string.
 */

char *strdup(const char *src)
{
	char *dst;

	dst = malloc(strlen(src) + 1);/** Space for length plus null */
	if (dst == NULL)
		return (NULL);/** No memory */
	strcpy(dst, src);/** Copy the characters */

	return (dst);/** Return the new string */
}
