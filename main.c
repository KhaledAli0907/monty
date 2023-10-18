#include "main.h"


/**
* main - entry point
* @argc: arguments count
* @argv: list of arguments
* Return: always 0
*/

int main(int argc, char *argv[])
{
	stack_t *head = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	_open(argv[1]);
	free_nodes();
	return (0);
}
