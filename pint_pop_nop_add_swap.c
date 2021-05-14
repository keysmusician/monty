#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: address of stack head pointer
 * @line_number: line number this command was called on
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);
}

/**
 * nop - do nothing
 * @stack: stack
 * @line_number: line_number
 */
void nop(stack_t **stack __attribute__((unused)),
	unsigned int line_number __attribute__((unused)))
{

}

/**
 * pop - pop the value at the top of the stack
 * @head: address of stack head pointer
 * @line_number: line number this command was called on
 */
void pop(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		fprintf(stderr,	"L%i: can't pop an empty stack\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

/**
 * swap - swap the value of the top two elements of the stack
 * @head: address of stack head pointer
 * @line_number: line number
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr,	"L%i: can't add, stack too short\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next->n;
	(*head)->next->n = (*head)->n;
	(*head)->n = temp;
}

/**
 * add - adds the value of the top two elements of the stack
 * @head: address of stack head pointer
 * @line_number: line number
 */
void add(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr,	"L%i: can't add, stack too short\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n + (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
