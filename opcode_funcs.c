#include "monty.h"

/**
 * get_function - get the appropriate function
 * @c: identifier for function
 */
void get_function(char **args)
{
    int y = 0;
    int push_number;
    instruction_t f_table[] = {
        {"push", push},
        {"pall", pall},
        {'\0', NULL}};

    while (strcmp(f_table[y].opcode, args[y]) != 0 && f_table[y].opcode != '\0')
    {
        y++;
    }
    if (strcmp(f_table[y].opcode, "push") == 0)
    {
        if (pushcheck(&args, y) == 0)
        {
            printf("pushcheck success\n");
            push_number = atoi(args[y + 1]);
            push(&stack, push_number);
        }
        else
        {
            printf("pushcheck failure\n");
        }
    }
    else
    {
        if (f_table[y].opcode != '\0')
        {
            f_table[y].f;
            printf("implemented %s", f_table[y].opcode);
        }
        else
            printf("implemented NULL");
    }
}

/**
 * push - add node at the end
 * @head: head
 * @n: new integer
 * Return: address of the new element
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *current_node = *head;

	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	if (new_node->n != 0 && !new_node->n)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	while (current_node->next)
	{
		current_node = current_node->next;
	}
	current_node->next = new_node;
	new_node->prev = current_node;
	return (new_node);
}

/**
 * pushcheck - checks if the information is correct for pushing to stack
 * @args: arguments from strtok
 * @idx: index of argument
 * Return: 0 for success. 1 for failure
 */
int pushcheck(char **args, int idx)
{
    if (args[idx] != '\0')
    {
        if (args[idx + 1] != '\0')
        {
            if (atoi(args[idx + 1]) != 0 && args[idx + 1] != '0')
            {
                return (0);
            }
        }
    }
    return (1);
}

