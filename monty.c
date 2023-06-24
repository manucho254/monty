#include "monty.h"
#include <stdlib.h>
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
	char *data, **sep;
	stack_t *stack, *new;
	int exit_code = 0;

	if (argc != 2)
	{
		print_error("USAGE: monty file", NULL);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	data = get_file_data(argv[1]);
	sep = separate_string(data, "\n");

	new = execute_codes(&stack, sep);
	if (new == NULL)
		exit_code = 1;

	free_list(sep);
	free(data);
	free_stack(new);
	stack = NULL;
	return (exit_code);
}
