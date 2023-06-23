#include "monty.h"
#include <stdlib.h>

/**
 * mul - function to multiply top two elements in stack
 *
 * @stack: pointer to stack.
 * @line: line number of the opcode
 *
 */

void mul(stack_t *stack, int line)
{
	int len, res;

	len = stack_length(stack); /** get length of stack */
	if (len < 2)
	{
		line_or_integer_err(": can't mul, stack too short", line);
		exit(EXIT_FAILURE);
	}

	res = stack->next->n * stack->n;
	stack->next->n = res;
	pop(stack);
}
