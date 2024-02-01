#include "monty.h"
/**
 * main - entry point
 * @argc: count of arguments
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        open_file(argv[1]);
        free_nodes();
        return (0);
}
/**
 * free_nodes - free nodes in stack
 */
void free_nodes(void)
{
        stack_t *tmp;

        if (head == NULL)
                return;
        while (head != NULL)
        {
                tmp = head;
                head = head->next;
                free(tmp);
        }
}
/**
 * create_Snode - greates a stack node
 * @n: number to be pushed
 * Return: pointer to node if successful else NULL
 */
stack_t *create_Snode(int n)
{
        stack_t *tmp;

        node = malloc(sizeof(stack_t));
        if (node == NULL)
                err(4);
        node->next = NULL;
        node->prev = NULL;
        node->n = n;
        return (node);
}
/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, unsigned int ln)
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
        while (tmp->next != NULL)
                tmp = tmp->next;

        tmp->next = *new_node;
        (*new_node)->prev = tmp;

}
