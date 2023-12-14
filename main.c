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
	stack_t *stack = NULL;
	char line[100];
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);	}
		while (fgets(line, sizeof(line), f) != NULL)
		{
			process(&stack, line, line_number);
			line_number++;
		}

	fclose(f);
	free_stack(stack);
	return (0);
}
