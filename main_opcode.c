#include "monty.h"

/**
 * push - function to push
 * @stack: the head of list
 * @value: hold the value
*/

void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	(void)line_number;
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = value;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = *stack;
	}
	*stack = new;
}

/**
 * pall - function to print all the nodes values
 * @stack: the head of the list
 * @line_number: hold the value
*/

void pall(stack_t **stack)
{
	stack_t *ptr;

	ptr = *stack;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
