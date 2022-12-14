#include "monty.h"
#include <stddef.h>
#include <stdlib.h>

/**
* new_stack - The stack list
* @stack: number
* Return: new node
*/
stack_t	*new_stack(int stack)
{
	stack_t	*item = malloc(sizeof(stack_t));

	if	(item == NULL)
		return (NULL);
	item->n = stack;
	return (item);
}
/**
* free_stack_element - frees a stack element
* @item: node to be freed
* Return: nothing
*/
void free_stack_element(stack_t	*item)
{
	item->next = NULL;
	item->prev = NULL;
	free(item);
}

/**
* free_stack - The stack list
* @stack: number
* Return: nothing
*/
void free_stack(stack_t	**stack)
{
	stack_t	*buf = NULL;

	while (*stack)
	{
		buf	= *stack;
		*stack = (*stack)->next;
		free(buf);
	}
}
