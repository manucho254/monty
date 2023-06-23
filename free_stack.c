#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - function to free stack
 *
 * @stack: pointer to stack
 *
 */

void free_stack(stack_t *stack)
{
	while (stack)
	{
		stack_t *tmp = stack;

		stack = stack->next;
		free(tmp);
	}
	free(stack);
}

/**
 * free_list - function to free an array of strings
 *
 * @args: pointer to an array of strings.
 *
 */

void free_list(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
