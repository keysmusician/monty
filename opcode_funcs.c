#include "monty.h"

stack_t *stack = NULL;

/**
 * get_function - get the appropriate function
 * @tokens: first two tokens on the line, followed by a NULL pointer
 * @line_number: line number
 */
void get_function(char **tokens, unsigned int line_number)
{
	int y = 0;
	char *opcode = tokens[0], *push_arg = tokens[1];
	void (*opcode_func)(stack_t **, unsigned int);
	instruction_t f_table[] = {
		{"pall", pall}, {"pint", pint},
		{"nop", nop}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"sub", sub}, {"mul", mul},
		{"div", _div}, {"mod", mod},
		{"", NULL}
	};

	if (!opcode || opcode[0] == '#')
		return;

	if (handle_push(opcode, push_arg, line_number))
		return;

	while (f_table[y].f)
	{
#if DEBUG
		printf("get_function: opcode == %s\n", f_table[y].opcode);
#endif
		if (strcmp(f_table[y].opcode, opcode) == 0)
		{
			opcode_func = f_table[y].f;
			opcode_func(&stack, line_number);
			return;
		}
		y++;
#if DEBUG
		printf("y is %d\n", y);
#endif
	}
	/* No opcode match */
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, opcode);
	free_all(NULL, NULL);
	exit(EXIT_FAILURE);
}

/**
 * handle_push - wrapper to check push requirements, push if neccessary,
 * and print errors
 * @opcode: an opcode
 * @push_arg: argument to push (if opcode is "push")
 * @line_number: line number to print if line contains an error
 * Return: 1 if push was handled, 0 if not
 */
int handle_push(char *opcode, char *push_arg, unsigned int line_number)
{
	if (strcmp("push", opcode) != 0)
		return (0); /* Return if opcode is not "push" */

	if (push_arg && only_digits(push_arg))
	{
		push(&stack, atoi(push_arg));
#if DEBUG
			printf("push success\n");
#endif
		return (1);
	}
	fprintf(stderr, "L%i: usage: push integer\n", line_number);
	free_all(NULL, NULL);
	exit(EXIT_FAILURE);
}

/**
 * push - add node at the beginning
 * @head: head
 * @n: new integer
 */
void push(stack_t **head, int n)
{
	stack_t *new_node;

	if (!head)
	{
		fprintf(stderr, "push: NULL stack head address\n");
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(NULL, NULL);
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
}

/**
 * pall - prints the entire stack from head to tail
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (!stack)
		fprintf(stderr, "pall: L%i: NULL stack head address\n", line_number);

	for (node = *stack; node; node = node->next)
		printf("%d\n", node->n);
}

/**
 * free_stack - frees a doubly linked list
 * @head: head node of doubly linked list
 */
void free_stack(stack_t *head)
{
	stack_t *node_i, *next;

	for (node_i = head; node_i; node_i = next)
	{
		next = node_i->next;
		free(node_i);
	}
}
