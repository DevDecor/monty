#include "monty.h"
/**
* main - Entry point
* @ac: argument counter
* @av: argument vector
* Return: nothing
*/
int main(int ac, char **av)
{
	FILE *file = NULL;
	stack_t *stack = NULL;
	instruction_t *hands[10];

	hands[0] = NULL;
	add_instruction(hands, pall, "pall");
	add_instruction(hands, pint, "pint");
	add_instruction(hands, popp, "pop");
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	decide(file, &stack, hands);
	free_stack(&stack);
	free_instructions(hands);
	fclose(file);
	return (0);
}

/**
* decide - Decides the operation for every opcode
* @file: File pointer
* @stack: the stack list
* @hands: array of handlers
* Return: nothing
*/
void decide(FILE *file, stack_t **stack, instruction_t **hands)
{
	size_t size = LINE_SIZE, len;
	unsigned int line = 0, i, found = 0;
	char *s = NULL, *opcode = NULL, *arg = NULL;

	while ((len = getline(&s, &size, file)) != (size_t)(-1))
	{
		line++;
		if (s[len - 1] == '\n')
			s[len - 1] = '\0';
		else
			s[len] = '\0';
		opcode = strtok(s, " ");
		arg = strtok(NULL, " ");
		if (strcmp(opcode, "push") == 0)
		{
			push_h(stack, hands, arg, line);
		}
		else
		{
			i = 0;
			found = 0;
			while (hands[i] != NULL)
			{
				if (strcmp(opcode, (hands[i])->opcode) == 0)
				{
					if ((hands[i])->f(stack, line) == -1)
						terminate(stack, hands);
					found = 1;
					break;
				}
				i++;
			}
			if (found == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s", line, opcode);
				terminate(stack, hands);
			}
		}
	}
}
