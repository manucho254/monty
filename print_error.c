#include "monty.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * print_error - function to print error message
 *
 * @msg: message to print
 * @arg: argument to add to message
 */

void print_error(char *msg, char *arg)
{
	if (arg)
	{
		strcat(msg, arg);
		write(STDERR_FILENO, msg, strlen(msg));
	}
	write(STDERR_FILENO, msg, strlen(msg));
}

/**
 * print_malloc_err - function to print error message
 *
 * @msg: message to print
 */

void print_malloc_err(char *msg)
{
	write(STDERR_FILENO, msg, strlen(msg));
}

/**
 * line_or_integer_err - function to print error message
 *
 * @msg: message to print
 * @line: line with error
 */

void line_or_integer_err(char *msg, int line)
{
	char *s, *num, tmp[100];

	num = _itoa(line, tmp, 10);
	s = malloc(sizeof(char) * ((strlen(num) + strlen(msg)) + 2));
	s[0] = 'L';
	strcat(s, num);
	strcat(s, msg);
	write(STDERR_FILENO, s, strlen(s));
	free(s);
}

/**
 * unkown_op_code_err - function to print error message
 *
 * @msg: message to print
 * @arg: argument to add to message
 * @line: line with error
 */

void unkown_op_code_err(char *msg, char *arg, int line)
{
	char *s, *num, tmp[100];

	num = _itoa(line, tmp, 10);
	s = malloc(sizeof(char) * ((strlen(num) + strlen(msg)) + 2));
	s[0] = 'L';
	strcat(s, num);
	strcat(s, msg);
	strcat(s, arg);
	write(STDERR_FILENO, s, strlen(s));
	free(s);
}
