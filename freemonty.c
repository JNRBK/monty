#include "monty.h"

/**
 * free_mem - freeing the stack/memory.
 * @stack: double ptr to the stack/queue.
 * Return: nothing.
*/

void free_mem(stack_t **stack)
{
	stack_t *s;

	while (*stack)
	{
		s = *stack;
		*stack = (*stack)->next;
		free(s);
	}
	free(program1.line);
	fclose(program1.file);
}
