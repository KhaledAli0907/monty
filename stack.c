#include "main.h"

/**
 * add_node_stack - add not the stack
 *
 * @node: pointer to the new node
 *
 * Return: pointer to the new node
 */
void add_node_stack(stack_t **node)
{
	stack_t *temp = NULL;

	if (node == NULL || *node == NULL)
		return (EXIT_FAILURE);

	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}

/**
 * pop_last - delete the last node added top the stack
 *
 * @last: pointer to last node added to the stack
 * @n: integer represinting opcode
 */
void pop_last(stack_t **last, int n)
{
	stack_t *temp = NULL;

	if (last == NULL || *last == NULL)
		more_errors(7, n);

	temp = *last;
	*last = temp->next;
	if (*last != NULL)
		(*last)->prev = NULL;
	free(temp);
}

/**
 * print_last - prints the latest node added to the stack
 *
 * @last: double pointer to the top node of the stack
 * @n: line number
 */
void print_last(stack_t **last, int n)
{
	if (*last == NULL || last == NULL)
		more_errors(6, n);
	printf("%d\n", (*last)->n);
}

/**
 * print_stack - prints the whole stack
 *
 * @last: double pointer to the last elemnt added to the stack
 */
void print_stack(stack_t **last)
{
	stack_t *temp = NULL;

	if (last == NULL)
		return (EXIT_FAILURE);

	temp = *last;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * swap_nodes - Swaps the first two nodes in the stack
 *
 * @last: pointer to the first node;
 * @n: line number;
 */
void swap_nodes(stack_t **last, unsigned int n)
{
	stack_t *temp = NULL;

	if (last == NULL || *last == NULL || (*last)->next == NULL)
		more_errors(8, n, "swap");

	temp = (*last)->next;
	(*last)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *last;
	temp->next = *last;
	(*last)->prev = temp;
	temp->prev = NULL;
	*last = temp;
}
