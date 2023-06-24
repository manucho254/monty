#include "monty.h"
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_error - function to print error message
 *
 * @msg: message to print
 * @arg: argument to add to message
 */

void print_error(char *msg, char *arg)
{
	if (arg)
		fprintf(stderr, "%s %s\n", msg, arg);
	else
		fprintf(stderr, "%s\n", msg);
}

/**
 * print_malloc_err - function to print error message
 *
 * @msg: message to print
 */

void print_malloc_err(char *msg)
{
	fprintf(stderr, "%s\n", msg);
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
	int len = 0;

	num = _itoa(line, tmp, 10);
	len = (strlen(num) + strlen(msg));
	s = malloc(sizeof(char) * (len));
	memset(s, 0, len - 1);
	s[0] = 'L';
	strcat(s, num);
	strcat(s, msg);
	fprintf(stderr, "%s\n", s);
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
	int len = 0;

	num = _itoa(line, tmp, 10);
	len = (strlen(num) + strlen(msg));
	s = malloc(sizeof(char) * (len + 2));
	s[0] = 'L';
	strcat(s, num);
	strcat(s, msg);
	strcat(s, arg);
	fprintf(stderr, "%s\n", s);
	free(s);
}
