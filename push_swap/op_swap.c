#include "push_swap.h"

static void	swap_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_stack **a)
{
	swap_stack(a);
	write_op("sa\n");
}

void	sb(t_stack **b)
{
	swap_stack(b);
	write_op("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write_op("ss\n");
}