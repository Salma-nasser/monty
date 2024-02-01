#include "monty.h"
/** open_file - open file given
 * A Filename: name of the file
 */
void open_file(char *Filename)
{
        FILE *fd = fopen(Filename, "r");

        if (file_name == NULL || fd == NULL)
        {
                err(2, Filename);
        }
        read_file(fd);
        fclose(fd);
}
/**
 * read_file - read the file
 * @fd: pointer to file
 */
void read_file(FILE *fd)
{
        int line_num, format = 0;
        char *buffer = NULL;
        size_t len = 0;

        for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
                format = parse_line(buffer, line_num, format);
        free(buffer);
}
/**
 * parse_line - seperates line into tokens
 * @buffer: line from the file
 * @line_num: number of line
 * @format: storage so if 0 enter as stack
 * Return: 0 if stack code else 1
 */
int parse_line(char *buffer, int line_num, int format)
{
        char *opcode, *value;
        const char *delim = " \n";

        if (buffer == NULL)
                err(4);
        opcode = strtok(buffer, delim);
        if (opcode == NULL)
                return (format);
        value = strtok(NULL, delim);
        if (strcmp(opcode, "stack") == 0)
                return (0);
        else
                return (1);
        find_func(opcode, value, line_num, format);
        return (format);
}
/**
 * find_func - find function given opcode
 * @opcode: opcode
 * @value: arguments
 * @format: 0 for stack 1 for queue
* @line_num: number of line
 */
void find_func(char *opcode, char *value, int line_num, int format)
{
        int i, flag;

        instruction_t func_list[] = {
                {"push", push},
                {"pall", print},
                {"pint", print_top},
                {"pop", pop},
                {"nop", nop},
                {"swap", swap},
                {NULL, NULL}
        };
        if (opcode[0] == '#')
                return;
        for (flag = 1, i = 0;func_list[i].opcode != NULL; i++)
        {
                if (strcmp(opcode, func_list[i].opcode) == 0)
                {
                        call_func(func_list[i].f, opcode, value, line_num, format);
                        flag = 0;
                }
        }
        if (flag == 1)
                err(3, line_num, opcode);
}
/**
* call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @line_num: line number
 * @format: 0 for stack 1 for queue.
 */
void call_func(op_func func, char *op, char *val, int line_num, int format)
{
        stack_t *node;
        int flag;
        int i;

        flag = 1;
        if (strcmp(op, "push") == 0)
        {
                if (val != NULL && val[0] == '-')
                {
                        val = val + 1;
                        flag = -1;
                }
                if (val == NULL)
                        err(5, ln);
                for (i = 0; val[i] != '\0'; i++)
                {
                        if (isdigit(val[i]) == 0)
                                err(5, ln);
                }
                node = create_node(atoi(val) * flag);
                if (format == 0)
                        func(&node, line_num);
                else
                        add_to_queue(&node, line_num);
        }
        else
                func(&head, line_num);
}
