#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/** global variable stack**/
extern stack_t *head = NULL;

/** functions**/
void print(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
stack_t *create_Snode(int);
void free_nodes(void);
void open_file(char *);
int parse_line(char *, int, int);
void read_file(FILE *);
void find_func(char *, char *, int, int);
void call_func(op_func, char *, char *, int, int);
void add_to_queue(stack_t **, unsigned int);
void err(int, ...);
#endif
