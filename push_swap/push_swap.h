#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}t_stack;

typedef struct s_parse
{
	long	value;
	int		i;
	int		j;
	int		count;
}t_parse;

char	**ps_split(char const *s);
void	free_split(char **arr);
int		count_words(char const *s);
int		is_valid_number(char *s);
long	ps_atol(char *s);
void	build_stack_from_args(t_stack **a, int argc, char **argv);
void	build_stack_from_split(t_stack **a, char **split);
void	append_node(t_stack **stack, int value);
void	free_stack(t_stack **stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *a);
int		stack_min(t_stack *a);
int		stack_max(t_stack *a);
int		find_position(t_stack *a, int value);
int		get_last_value(t_stack *a);
void	assign_index(t_stack *a);
int		lowest_index_pos(t_stack *a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);
void	error_exit(t_stack **a);
void	check_duplicate(t_stack *a, int value, t_stack **head);
void	write_op(char *s);

#endif