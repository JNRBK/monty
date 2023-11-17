#include "monty.h"

/**
 * exec_func - Executing functions based on the command read from the file.
 * Return: nothing.
*/

void exec_func(void)
{
	unsigned int x, ln = 0;
	size_t size = 0;
	char *line = NULL;
	stack_t *head = NULL;

	instruction_t hold[] = {
	{"push", push}, {"pall", pall}, {"pop", pop}, {"pint", pint}, {"swap", swap},
	{"nop", nop}, {"add", add}, {"sub", sub}, {"div", _div}, {"mul", _mul},
	{"mod", _mod}, {"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},
	{"rotr", rotr}, {NULL, NULL}};

	while (getline(&line, &size, program1.file) != -1)
	{
		ln++;
		program1.line = line;
		program1.op = strtok(line, DELIM);

		if (!program1.op || program1.op[0] == '#')
		{
			continue;
		}
		program1.arg = strtok(NULL, DELIM);

		for (x = 0; hold[x].opcode; x++)
		{
			if (strcmp(hold[x].opcode, program1.op) == 0)
			{
				hold[x].f(&head, ln);
				break;
			}
		}
		if (hold[x].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, program1.op);
			free_mem(&head);
			exit(EXIT_FAILURE);
		}
	}
	free_mem(&head);
}
