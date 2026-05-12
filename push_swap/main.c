#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	assign_index(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	build_stack_from_args(&a, argc, argv);
	if (!is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}