#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define READ_BUFFER 1024

/**
 * get_file_data - function to get data in file
 *
 * @file: pointer to filename.
 *
 * Return: pointer to new string
 */

char *get_file_data(char *file)
{
	char *codes;
	int fd, read_size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print_error("Error: Can't open file ", file);
		exit(EXIT_FAILURE);
	}
	codes = malloc(READ_BUFFER * sizeof(char));
	if (codes == NULL)
	{
		print_error("Error: malloc failed", NULL);
		exit(EXIT_FAILURE);
	}
	read_size = read(fd, codes, READ_BUFFER);
	/** check for read errors */
	if (read_size == -1)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}

	return (codes);
}
