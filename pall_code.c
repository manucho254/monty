#include "monty.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * pall - print all values in stack
 *
 * @stack: pointer to stack
 */

void pall(stack_t *stack)
{
	while (stack)
	{
		fprintf(stdout, "%d\n", stack->n);
		stack = stack->next;
	}
}
