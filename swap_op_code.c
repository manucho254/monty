#include "monty.h"
#include <stdlib.h>

/**
 * swap - function to swap top elements in stack
 *
 * @stack: pointer to stack.
 * @line: line number of the opcode.
 *
 */

void swap(stack_t *stack, int line)
{
	int len, val;

	len = stack_length(stack); /** get length of stack */
	if (len < 2)
	{
		line_or_integer_err(": can't swap, stack too short", line);
		exit(EXIT_FAILURE);
	}

	val = stack->n;
	stack->n = stack->next->n;
	stack->next->n = val;
}
