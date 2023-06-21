#include "monty.h"

/**
 * get_op_codes - function to get opcode
 *
 * @opcodes: an array to add opcodes
 *
 * Return: pointer to op_codes
 */

op_codes *get_op_codes(op_codes opcodes[])
{
	op_codes *tmp;

	opcodes[0].opcode = "push";
	opcodes[1].opcode = "pall";
	opcodes[2].opcode = "pint";
	opcodes[3].opcode = "pop";
	opcodes[4].opcode = "swap";
	opcodes[5].opcode = "add";
	opcodes[6].opcode = "nop";

	tmp = opcodes; /** assign opcodes to tmp */

	return (tmp);
}
