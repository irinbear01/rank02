#include "push_swap.h"

static int	get_max_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = stack_size(a) - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	size = stack_size(*a);
	bits = get_max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(a, b);
		i++;
	}
}