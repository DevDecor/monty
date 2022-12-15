#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
* push_h - Adds element to stack
* @st: the stack list
* @h: the handlers array
* @arg: opcode argument
* @line: line number
* Return: nothing
*/
void push_h(stack_t **st, instruction_t **h, char *arg, unsigned int line)
{
	if (arg == NULL || (arg[0] != '0' && atoi(arg) == 0))
	{
		fprintf(stderr, "L%d: usage: push integer", line);
		terminate(st, h);
	}
	if (push(st, atoi(arg)) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		terminate(st, h);
	}
}
/**
* pint - Adds element to stack
* @stack: the stack list
* @line_number: the handlers array
* Return: nothing
*/
int pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		return (-1);
	}
	else
	{
		printf("%d\n", head->n);
	}
	return (0);
}
/**
* push - The stack list
* @stack: stack list
* @n: number
* Return: new node
*/
stack_t	*push(stack_t **stack,	int	n)
{
	stack_t	*new_item = new_stack(n);

	if	(new_item == NULL)
	{
		return	(NULL);
	}
	new_item->next = *stack;
	if	(*stack)
		(*stack)->prev = new_item;
	*stack	=	new_item;
	return	(new_item);
}
/**
* pop - pops the stack list
* @stack: stack list
* Return: new node
*/
stack_t	*pop(stack_t **stack)
{
	stack_t	*old = *stack;

	if	(old !=	NULL)
	{
		*stack = old->next;
		old->next =	NULL;
		if (*stack)
			(*stack)->prev = NULL;
	}

	return (old);
}
/**
* popp - pops the stack list
* @stack: stack list
* @line_number: line number
* Return: new node
*/
int popp(stack_t **stack, unsigned int line_number)
{
	stack_t *h = pop(stack);

	if (h == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		return (-1);
	}
	free(h);
	return (0);
}
