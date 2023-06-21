#ifndef MONTY_H__
#define MONTY_H__

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
void print_error(char *msg, char *arg);
char *get_file_data(char *file);
void push(stack_t *stack, char *data);
void pall(stack_t *stack);
void pint(stack_t *stack);
void pop(stack_t *stack);
void swap(stack_t *stack);
void add(stack_t *stack);
void nop(void);
char **separate_string(char *s, char *deli);

#endif
