#include "push_swap.h"

static int	count_smaller(t_stack *head, int value)
{
	int	count;

	count = 0;
	while (head)
	{
		if (head->value < value)
			count++;
		head = head->next;
	}
	return (count);
}

void	assign_index(t_stack *a)
{
	t_stack	*head;

	head = a;
	while (a)
	{
		a->index = count_smaller(head, a->value);
		a = a->next;
	}
}