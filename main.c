#include "monty.h"

/**
 * main - entry point
 * @argc: argument counter
 * @argv: command line argument
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	FILE *f;
	char *op, *v_str, line[100];
	int value;
	stack_t *stack = NULL;

	if (argc != 2)
	{	fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);	}
		while (fgets(line, sizeof(line), f) != NULL)
		{	op = strtok(line, " \t\n");
			if (op == NULL)
				continue;
			if (strcmp(op, "push") == 0)
			{	v_str = strtok(NULL, " \t\n");
				value = atoi(v_str);
				if (v_str == NULL)
				{	fprintf(stderr, "L%d: usage: push integer\n", value);
					free_stack(stack);
					exit(EXIT_FAILURE);	}
				push(&stack, value);	}
			else if (strcmp(op, "pall") == 0)
			{	pall(&stack, 0);	}
			else if (strcmp(op, "pint") == 0)
			{	pint(&stack, 0);	}
			else if (strcmp(op, "pop") == 0)
			{	pop(&stack, 0);	}
			else if (strcmp(op, "swap") == 0)
			{	swap(&stack, 0);	}
			else if (strcmp(op, "add") == 0)
			{	add(&stack, 0);	}
			else
			{	fprintf(stderr, "Error: unknown instruction %s\n", op);
				free_stack(stack);
				exit(EXIT_FAILURE);	}
		}	fclose(f);
		free_stack(stack);
		return (0);	}
