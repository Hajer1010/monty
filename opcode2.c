#include "monty.h"

/**
 * swap - function to swap two nodes
 * @stack: the head of the list
 * @line_number: hold the value
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - function to add two nodes
 * @stack: the head of the list
 * @line_number: hold the value
*/

void add(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *st;

	st = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = st->next->n + st->n;
	st->next->n = result;
	(*stack) = st->next;
	free(st);
}

/**
 * sub - function to subtract two nodes
 * @stack: the head
 * @line_number: hold the value
*/

void sub(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *st;

	st = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = st->next->n + st->n;
	st->next->n = result;
	(*stack) = st->next;
	free(st);
}

/**
 * mul - function to multiply two nodes
 * @stack: the head
 * @line_number: ho;d the value
*/

void mul(stack_t **stack, unsigned int line_number)
{
	int result;
	stack_t *st;

	st = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (st->next->n) * (st->n);
	st->next->n = result;
	(*stack) = st->next;
	free(st);
}
