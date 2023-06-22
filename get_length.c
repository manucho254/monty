#include "monty.h"

/**
 * stack_length - function to get length of a stack
 *
 * @stack: pointer to stack.
 *
 * Return: length of stack.
 */

int stack_length(stack_t *stack)
{
	int count = 0;

	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
