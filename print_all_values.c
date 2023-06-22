#include "monty.h"
#include <stdio.h>

/**
 * pall - print all values in stack
 *
 * @stack: pointer to stack
 */

void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		fprintf(stdout, "%d\n", stack->n);
		stack = stack->next;
	}
}
