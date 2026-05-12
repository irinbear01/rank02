#include "push_swap.h"

static void	move_min_top(t_stack **a)
{
	int	pos;
	int	size;

	pos = lowest_index_pos(*a);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		move_min_top(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}