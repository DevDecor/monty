#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
* add_instruction - adds to the instruction list
* @hands: number
* @h: call back
* @opc: opcode
* Return: new node
*/
instruction_t *add_instruction(instruction_t **hands, func_t h, char *opc)
{
	instruction_t *buf = malloc(sizeof(instruction_t));
	int i = 0;

	if (buf == NULL)
		return (NULL);
	buf->f = h;
	buf->opcode = opc;
	while (hands[i] != NULL)
		i++;
	hands[i] = buf;
	hands[i + 1] = NULL;

	return (buf);
}
/**
* free_instructions - frees the instruction list
* @hands: number
* Return: nothing
*/
void free_instructions(instruction_t **hands)
{
	int i = 0;

	while (hands[i] != NULL)
		free(hands[i++]);
}
/**
* pall - prints the stack list
* @stack: stack list
* @line_number: the line number
* Return: nothing
*/
int pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *buf = *stack;

	while (buf != NULL)
	{
		printf("%d\n", (buf)->n);
		buf = buf->next;
	}
	return (0);
}
