#include "main.h"

/**
* _open - opens a file
* @fileName: name of the file
*/
void _open(char *fileName)
{
	FILE *pointer = fopen(fileName, "r");

	if (fileName == NULL || pointer == NULL)
		error(fileName, 2);

	read_lines(pointer);
	fclose(pointer);
}

/**
* read_lines - reads a file
* @pointer: pointer to file
*/
void read_lines(FILE *pointer)
{
	int line_n = 0, format = 0;

	char *buffer = NULL;

	size_t len = 0;

	for (line_n = 1; getline(&buffer, &len, 0) != -1; line_n++)
		format = parse_line(buffer, line_n, format);
	free(buffer);
}

/**
* parse_line - Separates each line into tokens to determine
* which function to call
* @buffer: line from the file
* @line_n: line number
* @format:  storage format. If 0 Nodes will be entered as a stack.
* if 1 nodes will be entered as a queue.
* Return: Returns 0 if the opcode is stack. 1 if queue.
*/
int parse_line(char *buffer, int line_n, int format)
{
	char *operator, *value;

	const char *delimeter = "\n ";

	if (buffer == NULL)
		err(4);

	operator = strtok(buffer, delimeter);
	if (operator == NULL)
		return (format);

	value = strtok(NULL, delimeter);
	if (strcmp(operator, "stack") == 0)
		return (0);
	if (strcmp(operator, "queue") == 0)
		return (1);

	_find(operator, value, line_n, format);
	return (format);
}
/**
 * _find - find the appropriate function for the opcode
 * @operator: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void _find(char *operator, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", add_node_stack},
		{"pall", print_stack},
		{"pint", print_stack},
		{"pop", pop_last},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_two_nodes},
		{"sub", sub_two_nodes},
		{"div", div_two_nodes},
		{"mul", mul_two_nodes},
		{"mod", mod_two_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (operator[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].operator != NULL; i++)
	{
		if (strcmp(operator, func_list[i].operator) == 0)
		{
			call_fun(func_list[i].f, operator, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, operator);
}

/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(operator_func func, char *op, char *val, int ln, int format)
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
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
