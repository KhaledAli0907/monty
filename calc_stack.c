#include "main.h"

/**
 * add_two_nodes - Adds the values of the top two nodes in the stack
 *
 * @last: pointer to the last node in the stack
 * @n: line number
 */
void add_two_nodes(stack_t **last, unsigned int n)
{
	int result = 0;

	if (last == NULL || *last == NULL || (*last)->next == NULL)
		more_errors(8, n, "add");

	(*last) = (*last)->next;
	result = (*last)->n + (*last)->prev->n;
	(*last)->n = result;
	free((*last)->prev);
	(*last)->prev = NULL;
}

/**
 * sub_two_nodes - sub the values of the top two nodes in the stack
 *
 * @last: pointer to the last node in the stack
 * @n: line number
 */
void sub_two_nodes(stack_t **last, unsigned int n)
{
	int result = 0;

	if (last == NULL || *last == NULL || (*last)->next == NULL)
		more_errors(8, n, "add");

	(*last) = (*last)->next;
	result = (*last)->n - (*last)->prev->n;
	(*last)->n = result;
	free((*last)->prev);
	(*last)->prev = NULL;
}
/**
 * div_two_nodes - devide the values of the top two nodes in the stack
 *
 * @last: pointer to the last node in the stack
 * @n: line number
 */
void div_two_nodes(stack_t **last, unsigned int n)
{
	int result = 0;

	if (last == NULL || *last == NULL || (*last)->next == NULL)
		more_errors(8, n, "div");

	if ((*last)->n == 0)
		more_errors(9, n);

	(*last) = (*last)->next;
	result = (*last)->n + (*last)->prev->n;
	(*last)->n = result;
	free((*last)->prev);
	(*last)->prev = NULL;
}

/**
 * mul_two_nodes - multiply the values of the top two nodes in the stack
 *
 * @last: pointer to the last node in the stack
 * @n: line number
 */
void mul_two_nodes(stack_t **last, unsigned int n)
{
	int result = 0;

	if (last == NULL || *last == NULL || (*last)->next == NULL)
		more_errors(8, n, "mul");

	(*last) = (*last)->next;
	result = (*last)->n * (*last)->prev->n;
	(*last)->next->n = result;
	free((*last)->prev);
	(*last)->prev = NULL;
}

/**
 * mod_two_nodes - get the mod value of the values/
 *  of the top two nodes in the stack
 *
 * @last: pointer to the last node in the stack
 * @n: line number
 */
void mod_two_nodes(stack_t **last, unsigned int n)
{
	int result = 0;

	if (last == NULL || *last == NULL || (*last)->next == NULL)
		more_errors(8, n, "mul");

	if ((*last)->next == 0)
		more_errors(9, n);

	(*last) = (*last)->next;
	result = (*last)->n % (*last)->prev->n;
	(*last)->next->n = result;
	free((*last)->prev);
	(*last)->prev = NULL;
}
