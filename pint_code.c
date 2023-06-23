#include "monty.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * pint - print top value in stack
 *
 * @stack: pointer to stack
 */

void pint(stack_t *stack)
{
	if (stack == NULL)
	{
		line_or_integer_err(": can't pint, stack empty", 0);
		exit(EXIT_FAILURE);
	}

	while (stack)
	{
		fprintf(stdout, "%d\n", stack->n);
		stack = stack->next;
		break;
	}
}
