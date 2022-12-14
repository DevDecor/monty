#ifndef MONTY_H
#define MONTY_H
#define LINE_SIZE 250
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
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

stack_t *new_stack(int n);
stack_t *push(stack_t **, int n);
stack_t *pop(stack_t **stack);
void free_stack_element(stack_t *);
void free_stack(stack_t **);

typedef int (*func_t)(stack_t **stack, unsigned int line_number);

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
	func_t f;
} instruction_t;

instruction_t *add_instruction(instruction_t **, func_t, char *);
void decide(FILE *, stack_t **, instruction_t **);

/* handlers */
void terminate(stack_t **stack, instruction_t **hands);
int pall(stack_t **stack, unsigned int line_number);
int popp(stack_t **stack, unsigned int line_number);
int pint(stack_t **stack, unsigned int line_number);
void free_instructions(instruction_t **hands);
void push_h(stack_t **stack, instruction_t **, char *, unsigned int);
#endif
