#include "monty.h"
#include <stddef.h>

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
	opcodes[7].opcode = "sub";
	opcodes[8].opcode = "div";
	opcodes[9].opcode = "mul";
	opcodes[10].opcode = "mod";
	opcodes[11].opcode = "pchar";
	opcodes[12].opcode = "pstr";
	opcodes[13].opcode = "rotl";
	opcodes[14].opcode = "rote";
	opcodes[15].opcode = "stack";
	opcodes[16].opcode = "queue";

	tmp = opcodes; /** assign opcodes to tmp */
	return (tmp);
}
