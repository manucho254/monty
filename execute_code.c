#include "monty.h"
#include <stdlib.h>
#include <string.h>

int _helper(stack_t **stack, char **str, int line);
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
	op_codes *codes, tmp_2[17];

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
				free_stack(*stack);
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
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
		if (_helper(stack, tmp, x) == 1)
			return (NULL);
	}
	return (*stack);
}

/**
 * _helper - helper function for execute commands
 *
 * @stack: pointer to stack
 * @str: pointer to array of strings
 * @line: line number of opcode.
 *
 * Return: 1 if failure else 0
 */

int _helper(stack_t **stack, char **str, int line)
{
	if (strcmp(str[0], "nop") == 0)
		return (1);
	if (strcmp(str[0], "pall") == 0)
		pall(*stack);
	if (strcmp(str[0], "pint") == 0)
		pint(*stack);
	if (strcmp(str[0], "pop") == 0)
		(*stack) = pop(stack);
	if (strcmp(str[0], "swap") == 0)
		swap(*stack, (line + 1));
	if (strcmp(str[0], "add") == 0)
		(*stack) = add(stack, (line + 1));
	if (strcmp(str[0], "sub") == 0)
		(*stack) = sub(stack, (line + 1));
	if (strcmp(str[0], "div") == 0)
		(*stack) = divide(stack, (line + 1));
	if (strcmp(str[0], "mul") == 0)
		(*stack) = mul(stack, (line + 1));
	if (strcmp(str[0], "mod") == 0)
		(*stack) = mod(stack, (line + 1));
	return (0);
}
