#include "monty.h"
/**
 * push_monty - Pushes An Element To The Stack.
 * @stack: Pointer To The head
 * @line_number: The Line Number
 * Return:Void
 */
void push_monty(stack_t **stack, unsigned int line_number)
{
	stack_t *n_node;
	(void)line_number;

	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		handle_error(1);
	if (_isdigit(info.arg[1]) > 0)
		handle_error(5);
	n_node->n = atoi(info.arg[1]);
	if (info.type == LIFO)
	{
		add_node_lifo(stack, n_node);
	}
	else
		add_node_fifo(stack, n_node);
}
/**
 * pall_monty - Prints All The Values On The Stack
 * @stack: Pointer To The Head
 * @line_number: Line Number
 * Return: Void
 */
void pall_monty(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *node;
	(void)line_number;

	node = *stack;
	for (i = 0; node; i++)
	{
		fprintf(stdout, "%d\n", node->n);
		node = node->next;
	}
}