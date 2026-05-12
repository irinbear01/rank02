#include "push_swap.h"

static void	add_checked_value(t_stack **a, char *s)
{
	long	value;

	if (!is_valid_number(s))
		error_exit(a);
	value = ps_atol(s);
	if (value < INT_MIN || value > INT_MAX)
		error_exit(a);
	check_duplicate(*a, (int)value, a);
	append_node(a, (int)value);
}

void	build_stack_from_split(t_stack **a, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		add_checked_value(a, split[i]);
		i++;
	}
}