
#include "monty.h"
/**
* terminate - Exits with error and free all malloced spaces
* @stack: the stack list
* @hands: The handlers list
* Return: new node
*/
void terminate(stack_t **stack, instruction_t **hands)
{
	if (*stack)
		free_stack(stack);
	if (*hands)
		free_instructions(hands);
	exit(EXIT_FAILURE);
}
