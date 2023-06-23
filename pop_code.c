#include "monty.h"
#include <stdlib.h>

/**
 * pop - function to pop item to stack.
 *
 * @stack: pointer to stack.
 *
 */

void pop(stack_t *stack)
{
	if (stack == NULL)
	{
		line_or_integer_err(": can't pop an empty stack", 0);
		exit(EXIT_FAILURE);
	}

	if (stack->next != NULL)
		*stack = *stack->next;
}
