#include "monty.h"

/**
 * swap - function to swap two nodes
 * @stack: the head of the list
 * @line_number: hold the value
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *f;
	stack_t *s;

	if (stack == NULL ||*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	f = *stack;
	s = f->next;
	f->next = s->next;
	if (s->next)
		s->next->prev = f;
	s->next = f;
	f->prev = s;
	s->prev = NULL;
	*stack = s;
}

/**
 * add - function to add two nodes
 * @stack: the head of the list
 * @line_number: hold the value
*/

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
