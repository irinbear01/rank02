#include "push_swap.h"

int	find_position(t_stack *a, int value)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value == value)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

int	get_last_value(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->value);
}

int	lowest_index_pos(t_stack *a)
{
	int	pos;
	int	best_pos;
	int	lowest;

	pos = 0;
	best_pos = 0;
	lowest = a->index;
	while (a)
	{
		if (a->index < lowest)
		{
			lowest = a->index;
			best_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (best_pos);
}