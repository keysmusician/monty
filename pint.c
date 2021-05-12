#include "monty.h"

/**
 * pint - print the value at the top of the stack.
 * @stack: address of stack head pointer
 * @line_number: line number this command was called on
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);
}

/**
 * pop - pop the value at the top of the stack.
 * @stack: address of stack head pointer
 * @line_number: line number this command was called on
 */
void pint(stack_t **stack, unsigned int line_number)
{
	return;
}
