#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}

	if (is_in_ascii(stack))
	{
		putchar((*stack)->n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_mem(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_in_ascii - checks the value if in the ascii table or not.
 * @stack: double ptr to the stack/queue.
 * Return: True || False.
*/
int is_in_ascii(stack_t **stack)
{
	int value = 0;

	value = (*stack)->n;
	if ((value >= 65 && value <= 90) ||
		(value >= 97 && value <= 122))
		return (1);
	else
		return (0);
}

/**
 * pstr - prints the string starting at the top of the stack.
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	line_number++;
	if (!stack || !(*stack))
	{
		free_mem(stack);
		putchar('\n');
	}
	ptr = *stack;
	while (ptr)
	{
		if (ptr->n == 0 || !is_in_ascii(stack))
			break;
		putchar(ptr->n);
		ptr = ptr->next;
	}
	putchar('\n');
}

/**
 * is_int - checks the value if it's integer or not.
 * @n: character to be checked.
 * Return: True || False.
*/

int is_int(char *n)
{
	int i;

	if (n == NULL)
		return (0);
	for (i = 0; n[i]; i++)
	{
		if (i == 0 && (n[i] == '-' || n[i] == '+'))
			continue;
		if (n[i] < '0' || n[i] > '9')
			return (0);
	}
	return (1);
}
