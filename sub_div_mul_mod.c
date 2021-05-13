#include "monty.h"
/**
 * sub - subtracts the value of the top two elements of the stack
 * @head: address of stack head pointer
 * @line_number: line number
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr,	"L%i: can't sub, stack too short\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n - (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * _div - divides the value of the top two elements of the stack
 * @head: address of stack head pointer
 * @line_number: line number
 */
void _div(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr,	"L%i: can't div, stack too short\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr,	"L%i: division by zero\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n / (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * mul - multiplies the value of the top two elements of the stack
 * @head: address of stack head pointer
 * @line_number: line number
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr,	"L%i: can't mul, stack too short\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->next->n * (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
 * mod - modulus the value of the top two elements of the stack
 * @head: address of stack head pointer
 * @line_number: line number
 */
void mod(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !((*head)->next))
	{
		fprintf(stderr,	"L%i: can't mod, stack too short\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr,	"L%i: division by zero\n", line_number);
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n = (*head)->next->n + (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}
