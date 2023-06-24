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

	fprintf(stderr, "L%d%s\n", line, msg);
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
	fprintf(stderr, "L%d%s %s\n", line, msg, arg);
}
