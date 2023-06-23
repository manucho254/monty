#include "monty.h"
#include <stdlib.h>

/**
 * add - function to add top two elements in stack
 *
 * @stack: pointer to stack.
 * @line: line number of the opcode
 *
 */

void add(stack_t *stack, int line)
{
	int len, sum;

	len = stack_length(stack); /** get length of stack */
	if (len < 2)
	{
		line_or_integer_err(": can't add, stack too short", line);
		exit(EXIT_FAILURE);
	}

	sum = stack->n + stack->next->n;
	stack->next->n = sum;
	pop(stack);
}
