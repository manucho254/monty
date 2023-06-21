#include "monty.h"
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

	fprintf(stderr, "%s\n", msg);
}
