#include "monty.h"
stack_t *stack = NULL;
/**
 * get_function - get the appropriate function
 * @c: identifier for function
 */
void get_function(char **args, unsigned int line_number)
{
    int y = 0;
    int push_number;
    void (*opcode_func)(stack_t **, unsigned int);
    instruction_t f_table[] = {
        {"pall", pall},
        {'\0', NULL}};

    if (strcmp(args[0], "push") == 0)
    {
        if (atoi(args[1]) != 0 || strcmp(args[1], "0") == 0)
        {
            printf("pushcheck success\n");
            push_number = atoi(args[1]);
            push(&stack, push_number);
        }
        else
        {
            printf("pushcheck failure\n");
        }
    }
    while (f_table[y].opcode != args[0] && f_table[y].f)
        y++;
    opcode_func = f_table[y].f;
    if (!opcode_func)
    {
        fprintf(stderr, "L%i: unknown instruction %s\n", line_number, args[0]);
        exit(EXIT_FAILURE);
    }
    opcode_func(&stack, line_number);
}

/**
 * push - add node at the beginning
 * @head: head
 * @n: new integer
 */
void push(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!head)
    {
        fprintf(stderr, "head does not exist\n");
        return;
    }
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;
    *head = new_node;
}

/**
 * pall - prints the entire stack from head to tail
 * @stack: stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
    int iter = line_number;
    stack_t *node = *stack;

    iter = 0;
    if (!node)
    {
        printf("node allocation failed in pall()\n");
    }
    while (node)
    {
        printf("%d\n", node->n);
        node = node->next;
        iter++;
    }
}
