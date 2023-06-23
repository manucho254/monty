#ifndef MONTY_H
#define MONTY_H

#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct codes - structure to hold the, different opdcode to check for.
 *
 * @opcode: type to check of symbol
 */

typedef struct codes
{
	char *opcode;
} op_codes;

char *strdup(const char *src);
char *get_file_data(char *file);
stack_t *push(stack_t *stack, char *data);
void pall(stack_t *stack);
void pint(stack_t *stack);
void pop(stack_t *stack);
void swap(stack_t *stack, int line);
void add(stack_t *stack, int line);
void sub(stack_t *stack, int line);
void divide(stack_t *stack, int line);
void mul(stack_t *stack, int line);
void mod(stack_t *stack, int line);
void nop(void);
char **separate_string(char *s, char *deli);
int count_strings(char *s, char *deli);
stack_t *execute_codes(stack_t **stack, char *args[]);
bool is_number(char *s);
char *_itoa(int value, char *s, int base);
void print_error(char *msg, char *arg);
void print_malloc_err(char *msg);
void line_or_integer_err(char *msg, int line);
void unkown_op_code_err(char *msg, char *arg, int line);
op_codes *get_op_codes(op_codes opcodes[]);
void free_stack(stack_t *stack);
void free_list(char **args);
int stack_length(stack_t *stack);

#endif
