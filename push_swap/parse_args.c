#include "push_swap.h"

static void	parse_one_arg(t_stack **a, char *arg)
{
	char	**split;

	split = ps_split(arg);
	if (!split || !split[0])
	{
		free_split(split);
		error_exit(a);
	}
	build_stack_from_split(a, split);
	free_split(split);
}

void	build_stack_from_args(t_stack **a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			error_exit(a);
		parse_one_arg(a, argv[i]);
		i++;
	}
}