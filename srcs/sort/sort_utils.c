#include "sort.h"

int	sorted(t_node **a)
{
	t_node	*start;
	t_node	*actual;

	start = (*a);
	actual = (*a);
	while (actual->next != start)
	{
		if (actual->next->val < actual->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}

int	get_cll_len(t_node **a)
{
	t_node	*start;
	t_node	*actual;
	int		i;

	start = (*a);
	actual = (*a);
	i = 0;
	while (actual->next != start)
	{
		actual = actual->next;
		i++;
	}
	i++;
	return (i);
}

void	shift_up(t_node **a)
{
	t_node	*max_val;
	t_node	*current;
	int		list_len;
	int		i;

	max_val = max_val_elem(*a);
	list_len = get_cll_len(a);
	i = 0;
	current = *a;
	while (TRUE)
	{
		i++;
		current = current->next;
		if (current == max_val)
			break ;
	}
	while (max_val->next != *a)
	{
		if (i > list_len / 2)
			rra(a);
		else
			ra(a);
	}
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
