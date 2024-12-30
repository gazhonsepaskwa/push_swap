#include "sort.h"

void	sort_tree(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->val;
	second = (*a)->next->val;
	third = (*a)->next->next->val;
	if (first < second && second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second < third && third > first)
		sa(a);
	else if (first < second && second > third && third < first)
		rra(a);
	else if (first > second && second < third && third < first)
		ra(a);
	else if (first > second && second > third && third < first)
	{
		sa(a);
		rra(a);
	}
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
			break;
	}
	while (max_val->next != *a)
	{
		if (i > list_len / 2)
			rra(a);
		else
			ra(a);
	}
}

int	sort_other(t_node **a, t_node **b)
{
	t_node	*best_a;
	t_node	*best_b;

	while (TRUE)
	{
		if (sorted(a) && (*b) == NULL)
			break ;
		if (get_cll_len(a) == 3)
		{
			sort_tree(a);
			while (*b)
			{
				best_b = get_min_push_cost(*b, *a, "a");
				do_min_cost_push_a(b, a, best_b);
			}
			shift_up(a);
			break ;
		}
		else
		{
			best_a = get_min_push_cost(*a, *b, "b");
			do_min_cost_push_b(a, b, best_a);
		}
	}
	return (0);
}

int	sort(t_node **a, t_node **b)
{
	int	len_a;

	if (sorted(a))
		return (0);
	len_a = get_cll_len(a);
	if (len_a == 2)
		ra(a);
	else if (len_a == 3)
		sort_tree(a);
	else
	{
		if (len_a > 4)
			pb(b, a);
		pb(b, a);
		sort_other(a, b);
	}
	return (0);
}
