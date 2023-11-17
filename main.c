#include "monty.h"

/**
 * argument - checking arguments count.
 * @argc: arguments count.
 * Return: nothing.
*/

void argument(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * open - open the file passed on.
 * @fop: pointer to the file's name.
 * Return: nothing.
*/
void open(char *fop)
{
	program1.file = fopen(fop, "r");
	if (!program1.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fop);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - Starting Monty.
 * @argc: arguments count.
 * @argv: vector to arguments.
 * Return: 0: Success.
*/

int main(int argc, char *argv[])
{
	argument(argc);
	open(argv[1]);
	exec_func();
	return (EXIT_SUCCESS);
}
