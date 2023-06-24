#include "monty.h"
#include <stdlib.h>

/**
 * divide - function to divide top two elements in stack
 *
 * @stack: pointer to stack.
 * @line: line number of the opcode
 *
 * Return: pointer to stack.
 */

stack_t *divide(stack_t **stack, int line)
{
	int len, res;

	len = stack_length(*stack); /** get length of stack */
	if (len < 2)
	{
		line_or_integer_err(": can't div, stack too short", line);
		exit(EXIT_FAILURE);
	}
	/** check if to element value equal to zero */
	if ((*stack)->n == 0)
	{
		line_or_integer_err(": division by zero", line);
		exit(EXIT_FAILURE);
	}
	res = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = res;
	pop(stack);

	return (*stack);
}
