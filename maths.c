#include "monty.h"

/**
 * add - adds the top two elements of the stack,
 * replacing the 2nd to be top element.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	unsigned int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * sub - subtracts top element from 2nd top element of the stack,
 * replacing the 2nd to be top element.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	unsigned int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * _div - divides second top element by top element of the stack,
 * replacing the 2nd to be top element.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	unsigned int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = result;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * _mul - multiplies the second top element with the top element of the stack,
 * replacing the 2nd to be top element.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	unsigned int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = result;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * _mod - computes rest of division of the 2nd element by the top element,
 * replacing the 2nd to be top element in the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	unsigned int result = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = result;
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}
