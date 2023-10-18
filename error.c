#include "main.h"

/**
 * error - Prints appropiate error messages determined by their error code.
 * @err_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 */
void error(int err_code, ...)
{
	va_list arg;
	char *operator;
	int num;

	va_start(arg, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "Usage: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: can't open file %s\n",
					va_arg(arg, char *));
			break;
		case 3:
			num = va_arg(arg, int);
			operator = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n");
			break;
		case 4:
			fprintf(stderr, "Error: Malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_errors - handles errors.
 * @err_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_errors(int err_code, ...)
{
	va_list arg;
	char *operator;
	int num;

	va_start(arg, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(arg, int));
			break;
		case 8:
			num = va_arg(arg, unsigned int);
			operator = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, operator);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_error(int error_code, ...)
{
	va_list arg;
	int num;

	va_start(arg, error_code);
	num = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
