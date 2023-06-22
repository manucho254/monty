#include "monty.h"
#include <unistd.h>
#include <string.h>

/**
 * pall - print all values in stack
 *
 * @stack: pointer to stack
 */

void pall(stack_t *stack)
{
	char *val, tmp[100];

	while (stack)
	{
		val = _itoa(stack->n, tmp, 10);
		strcat(val, "\n");
		write(STDOUT_FILENO, val, strlen(val));
		stack = stack->next;
	}
}
