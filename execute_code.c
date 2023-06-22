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
	int x, i, count = 0;
	op_codes *codes, tmp_2[18];

	codes = get_op_codes(tmp_2);
	for (x = 0; args[x] != NULL; x++)
	{
		tmp = separate_string(args[x], " ");
		count = count_strings(args[x], " ");
		if (count == 0)
			return (NULL);
		if (strcmp(tmp[0], "push") == 0 && count >= 2)
		{
			if (!is_number(tmp[1]))
			{
				line_or_integer_err(": usage: push integer", (x + 1));
				exit(EXIT_FAILURE);
			}
			(*stack) = push(*stack, tmp[1]);
		}
		for (i = 0; i < 17; i++)
		{
			if (strcmp(codes[i].opcode, tmp[0]) == 0)
				break;
		}
		if (i == 17)
		{
			unkown_op_code_err(": unknown instruction ", tmp[0], (x + 1));
			exit(EXIT_FAILURE);
		}
		if (strcmp(tmp[0], "nop") == 0)
			return (NULL);
		if (strcmp(tmp[0], "pall") == 0)
		{
			pall(*stack);
		}
	}
	return (*stack);
}
