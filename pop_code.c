#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - function to pop item to stack.
 *
 * @stack: pointer to stack.
 * @line: opcode line
 *
 * Return: pointer to stack else return NULL
 */

stack_t *pop(stack_t **stack, int line)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		line_or_integer_err(": can't pop an empty stack", line);
		exit(EXIT_FAILURE);
	}

	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
		return (NULL);

	if ((*stack)->next == NULL)
	{
		free(*stack);
		return (NULL);
	}
	if ((*stack)->next != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		free(tmp);
		return (*stack);
	}

	return (*stack);
}
