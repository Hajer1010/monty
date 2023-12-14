#include "monty.h"

/**
 * process - function to do all the processes
 * @stack: the head
 * @line: char to hold the line
 * @line_number: hold the value
*/

void process(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode;
	char *v_str;
	int value;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL)
		return;

	if (strcmp(opcode, "push") == 0)
	{
		v_str = strtok(NULL, " \t\n");
		if (v_str == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(v_str);
		push(stack, value, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "pall") == 0)
		pall(stack);
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
