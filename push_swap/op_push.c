#include "push_swap.h"

static void	push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	write_op("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	write_op("pb\n");
}