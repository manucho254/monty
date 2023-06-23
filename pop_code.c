#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - function to pop item to stack.
 *
 *
 * @stack: pointer to stack.
 *
 */

void pop(stack_t *stack)
{
	int count = 0;

	if (stack == NULL)
	{
		line_or_integer_err(": can't pop an empty stack", 0);
		exit(EXIT_FAILURE);
	}

	count = stack_length(stack);

	if (count > 1)
		*stack = *stack->next;
}
