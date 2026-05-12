#include "push_swap.h"

static void	rev_rotate_stack(t_stack **s)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_stack **a)
{
	rev_rotate_stack(a);
	write_op("rra\n");
}

void	rrb(t_stack **b)
{
	rev_rotate_stack(b);
	write_op("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	write_op("rrr\n");
}