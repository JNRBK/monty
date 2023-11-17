#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#define DELIM "\n \t"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void open(char *fop);
void argument(int argc);
void exec_func(void);
void free_mem(stack_t **stack);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/**
 * nop - simply do nothing :D
 * @stack: double ptr to the stack/queue.
 * @line_number: line; the command been read from.
 * Return: nothing.
*/

void nop(__attribute__((unused))stack_t **stack,
__attribute__((unused))unsigned int line_number);

void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

int is_in_ascii(stack_t **stack);
int is_int(char *n);

/**
 * struct program - handle all parameters together.
 * @arg: argument read.
 * @file: file.
 * @line: for reading the file.
 * @op: the opcode function.
 * @mod: checks stack || queue.
 */

typedef struct program
{
	char *arg;
	FILE *file;
	char *line;
	char *op;
	int mod;
} myprog;

myprog program1;

#endif
