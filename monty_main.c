#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/**
 * main - monty entry point
 *
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 *
 * Return: 1 if success else return 0
 */

int main(int argc, char *argv[])
{
	char *data, **sep, **tmp;
	int x, i;
	stack_t *stack;

	if (argc != 2)
	{
		print_error("USAGE: monty file", NULL);
		exit(EXIT_FAILURE);
	}

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
	{
		print_error("Error: malloc failed", NULL);
		exit(EXIT_FAILURE);
	}
	data = get_file_data(argv[1]);
	sep = separate_string(data, "\n");

	for (x = 0; sep[x] != NULL; x++)
	{
		tmp = separate_string(sep[x], " ");
		for (i = 0; tmp[i] != NULL; i++)
		{
			if (strcmp(tmp[i], "nop") == 0)
				return (0);
			printf("%s", tmp[i]);
		}
	}

	printf("\n");
	return (0);
}
