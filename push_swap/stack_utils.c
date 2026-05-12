#include "push_swap.h"

void	append_node(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_exit(stack);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}