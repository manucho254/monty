#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * push - function to add item to stack.
 *
 * @data: data to add to stack
 */

void push(char *data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		print_error("Error: malloc failed", NULL);
		exit(EXIT_FAILURE);
	}

	printf("%s", data);
}
