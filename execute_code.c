#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * execute_codes - function to run opcodes
 *
 * @stack: pointer to stack
 * @args: array of strings
 *
 * Return: pointer to stack.
 */

stack_t *execute_codes(stack_t **stack, char *args[])
{
	char **tmp;
	int x, count = 0;

	for (x = 0; args[x] != NULL; x++)
	{
		tmp = separate_string(args[x], " ");
		count = count_strings(args[x], " ");

		if (count == 0)
			return (NULL);
		if (count == 2)
		{
			if (strcmp(tmp[0], "push\n"))
			{
				(*stack) = push(*stack, tmp[1]);
			}
		}
		if (strcmp(tmp[0], "nop") == 0)
			return (NULL);
		if (strcmp(tmp[0], "pall") == 0)
		{
			pall(*stack);
			return (NULL);
		}
	}

	return (*stack);
}
