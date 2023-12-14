#include "monty.h"

/**
 * free_stack - function that free stack
 * @stack: the head of the list
*/

void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
