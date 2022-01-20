#include "main.h"

/**
 * push - Pushes an element to the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * @n: variable
 * Return: address of new element
 */

void push(stack_t **stack, unsigned int line_num, int n)
{
	stack_t *new, *h = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_num);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack)
		h->prev = new;
	*stack = new;
}

/**
 * pall - Print all values on the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;
	(void)line_num;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - Prints value at top of stack.
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);

}

/**
 * pop - Removes the top element of the stack
 * @stack: pointer to head of stack
 * @line_num: file's line number
 * Return: Void
 */

void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *h = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}


	if (h)
	{
		*stack = (h)->next;
		free(h);
	}
}