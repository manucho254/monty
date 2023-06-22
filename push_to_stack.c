#include "monty.h"
#include <stdlib.h>

/**
 * push - function to add item to stack.
 *
 * @data: data to add to stack
 * @stack: pointer to stack.
 *
 * Return: pointer to stack.
 */

stack_t *push(stack_t *stack, char *data)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		print_error("Error: malloc failed", NULL);
		exit(EXIT_FAILURE);
	}

	if (stack == NULL)
	{
		new->prev = NULL;
		new->n = atoi(data);
		new->next = NULL;
		(stack) = new;

		return (stack);
	}
	/** check if the list is empty */
	new->prev = NULL;
	new->n = atoi(data);
	new->next = NULL;
	new->next = stack;
	stack->prev = new;
	stack = new;

	return (stack);
}
