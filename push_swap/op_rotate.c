#include "push_swap.h"

static void	rotate_stack(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a)
{
	rotate_stack(a);
	write_op("ra\n");
}

void	rb(t_stack **b)
{
	rotate_stack(b);
	write_op("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
	write_op("rr\n");
}