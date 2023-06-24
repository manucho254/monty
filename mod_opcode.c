#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * mod - function to get the remainder,
 * between the two elements in stack.
 *
 * @stack: pointer to stack.
 * @line: line number of the opcode
 *
 * Return: pointer to stack
 */

stack_t *mod(stack_t **stack, int line)
{
	int len, res;

	len = stack_length(*stack); /** get length of stack */
	if (len < 2)
	{
		line_or_integer_err(": can't mod, stack too short", line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		line_or_integer_err(": division by zero", line);
		exit(EXIT_FAILURE);
	}

	/** val = stack->n; ** value for top item in stack */
	if ((*stack)->n < 0)
		(*stack)->n = abs((*stack)->n);

	res = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = res;
	pop(stack);

	return (*stack);
}
