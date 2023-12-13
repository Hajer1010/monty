#include "monty.h"

/**
 * push - function to push
 * @stack: the head of list
 * @value: hold the value
*/

void push(stack_t **stack, int value)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if ((*stack) != NULL)
	{
		(*stack)->prev = *stack;
	}
	*stack = new
}

/**
 * pall - function to print all the nodes values
 * @stack: the head of the list
 * @line_number: hold the value
*/

void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	stack_t *ptr = stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
