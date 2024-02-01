#include <monty.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * push - adds new node to stack
 * @new_node: points to the new node
 * @line: line number of the opcode
 */
void push(stack_t **new_node, unsigned int line)
{
        stack_t *tmp;

        if (new_node == NULL || *new_node == NULL)
                exit(EXIT_FAILURE);
        if (head == NULL)
        {
                head = *new_node;
                return;
        }
        tmp = head;
        head = *new_node;
        head->next = tmp;
        tmp->prev = head;
}

/**
 * print - prints the stack
 * @stack: Pointer to top of the stack
 * @line: line number of opcode
 */
void print(stack_t **stack, unsigned int line)
{
        stack_t *tmp;

        if (stack == NULL)
                exit(EXIT_FAILURE);
        tmp = *stack;
        while (tmp != NULL)
        {
                printf("%d\n", tmp->n);
                tmp = tmp->next;
        }
}

