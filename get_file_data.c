#include "monty.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define READ_BUFFER 1024
char *remove_spaces_from_str(char *string);
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
		print_error("Error: malloc failed ", NULL);
		exit(EXIT_FAILURE);
	}
	read_size = read(fd, codes, READ_BUFFER);
	/** check for read errors */
	if (read_size == -1)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}

	codes = remove_spaces_from_str(codes);
	return (codes);
}

/**
 * remove_spaces_from_str - function to remove spaces from string
 *
 * @str: string to remove spaces
 *
 * Return: pointer to string.
 */

char *remove_spaces_from_str(char *str)
{
	/** non_space_count to keep the frequency of non space characters */
	int i, len = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			str[len] = str[i];
			len++;/** non_space_count incremented */
		}
		if (i >= 1)
		{
			if (str[i] == ' ' && str[i - 1] != ' ' && str[i - 1] != '\n')
			{
				str[len] = str[i];
				len++;
			}
		}
	}

	str[len] = '\0'; /** null pointer to the end of the string */
	return (str);
}
