#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define READ_BUFFER 1024

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
	int x;

	if (argc != 2)
	{
		print_error("USAGE: monty file", NULL);
		exit(EXIT_FAILURE);
	}

	data = get_file_data(argv[1]);
	sep = separate_string(data, "\n");

	for (x = 0; sep[x] != NULL; x++)
	{
		printf("%s", sep[x]);
	}

	return (0);
}
