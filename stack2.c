#include "monty.h"

/**
 * nop - simply do nothing :D
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number) {}

/**
 * rotl - rotates the stack to the top.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void rotl(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *ptr = NULL;

	line_number++;
	ptr = *stack;
	data = (*stack)->n;

	if ((*stack)->next != NULL && (*stack))
	{
		while (ptr->next)
		{
			ptr->n = ptr->next->n;
			ptr = ptr->next;
		}
		ptr->n = data;
	}
}

/**
 * rotr - rotates the stack to the bottom.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void rotr(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *ptr = NULL;

	line_number++;
	ptr = *stack;
	data = (*stack)->n;

	if ((*stack)->prev != NULL && (*stack))
	{
		while (ptr->prev)
		{
			ptr->n = ptr->prev->n;
			ptr = ptr->prev;
		}
		(*stack)->n = data;
	}
}
