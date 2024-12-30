#include "../push_swap.h"

static t_node	*create_node(int val, t_node *prev)
{
	t_node	*self;

	self = malloc(sizeof(t_node));
	if (!self)
		return (NULL);
	self->val = val;
	self->prev = prev;
	self->next = NULL;
	return (self);
}

int	create_stack(t_node **stack, char **tab, int start, int lim)
{
	int		i;
	t_node	*prev;

	i = 0;
	*stack = create_node((int)ft_atoi(tab[start]), NULL);
	if (!(*stack))
		return (free_stack(*stack));
	prev = *stack;
	while (tab[start + i + 1] && start + i + 1 < lim)
	{
		prev->next = create_node((int)ft_atoi(tab[start + i + 1]), prev);
		if (!prev->next)
			return (free_stack(*stack));
		prev = prev->next;
		i++;
	}
	prev->next = *stack;
	(*stack)->prev = prev;
	return (0);
}

int	free_stack(t_node *stack)
{
	t_node	*start;
	t_node	*second;

	if (!stack)
		return (-1);
	start = stack;
	while (start->next != start)
	{
		second = stack->next;
		stack->next = stack->next->next;
		free(second);
		second = NULL;
	}
	free(start);
	return (-1);
}
