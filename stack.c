#include "monty.h"

/**
 * pall - prints all values on stack, from the top of the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = NULL;

	ptr = (*stack);
	if (ptr != NULL)
	{
		while (ptr != NULL)
		{
			line_number++;
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

/**
 * pint - prints the value at the top of the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
		line_number++;
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	line_number++;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	ptr = (*stack);
	(*stack) = ptr->next;
	free(ptr);
}

/**
 * push - pushes an element to the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	if (!is_int(program1.arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = atoi(program1.arg);
	new_node->prev = NULL;
	new_node->next = NULL;

	new_node->next = *stack;
	*stack = new_node;
}

/**
 * swap - swaps the top two elements of the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *node_top2;
	int top_data = 0;
	int top2_data = 0;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
	node_top2 = (*stack)->next;

	top2_data = node_top2->n;
	top_data = (*stack)->n;

	(*stack)->next->n = top_data;
	(*stack)->n = top2_data;
}
