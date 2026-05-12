#include "push_swap.h"

void	write_op(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	error_exit(t_stack **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_duplicate(t_stack *a, int value, t_stack **head)
{
	while (a)
	{
		if (a->value == value)
			error_exit(head);
		a = a->next;
	}
}