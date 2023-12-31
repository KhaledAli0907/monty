#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	char *operator;

	void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;

extern stack_t *head;
typedef void (*operator_func)(stack_t **, unsigned int);

/* Erros handlers */
void error(int error_code, ...);
void more_errors(int err_code, ...);
void string_error(int err_code, ...);

/*file operations*/
void _open(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_lines(FILE *);
int len_chars(FILE *);
void _find(char *, char *, int, int);

/*stack functions*/
void add_node_stack(stack_t **node, unsigned int n);
void pop_last(stack_t **last, unsigned int n);
void print_last(stack_t **last, unsigned int n);
void print_stack(stack_t **last, unsigned int n);
void swap_nodes(stack_t **last, unsigned int n);
void nop(stack_t **stack, unsigned int line_number);
void call_fun(operator_func func, char *op, char *val, int ln, int format);

/* stack calculation functions */
void add_two_nodes(stack_t **, unsigned int);
void sub_two_nodes(stack_t **, unsigned int);
void div_two_nodes(stack_t **, unsigned int);
void mul_two_nodes(stack_t **, unsigned int);
void mod_two_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
stack_t *create_node(int n);
void free_nodes(void);
void add_to_queue(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);

#endif /*MAIN_H*/
