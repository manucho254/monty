#include "monty.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * pint - print top value in stack
 *
 * @stack: pointer to stack
 */

void pint(stack_t *stack)
{
	char *val, tmp[20];

	if (stack == NULL)
	{
		line_or_integer_err(": can't pint, stack empty", 0);
		exit(EXIT_FAILURE);
	}

	while (stack)
	{
		val = _itoa(stack->n, tmp, 10);
		strcat(val, "\n");
		write(STDOUT_FILENO, val, strlen(val));
		stack = stack->next;
		break;
	}
}
