#include "sort.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	get_cost_b(t_node *elem_a, t_node *b, int *closest, int *i)
{
	int		closest_diff;
	t_node	*start;

	start = b;
	closest_diff = 2147483647;
	while (TRUE)
	{
		if (ft_abs(elem_a->val - b->val) < closest_diff && elem_a->val > b->val)
		{
			closest_diff = ft_abs(elem_a->val - b->val);
			(*closest) = (*i);
		}
		b = b->next;
		(*i)++;
		if (b == start) 
			break;
	}
}

static int	get_push_cost(t_node *b, t_node *elem_a, int cost_a, int *reverse)
{
	int		cost_b;
	int		i;

	cost_b = 0;
	i = 0;
	get_cost_b(elem_a, b, &cost_b, &i);
	if (cost_b > i / 2)
	{
		(*reverse) = TRUE;
		return ((cost_a + (i - cost_b) + 1));
	}
	(*reverse) = FALSE;
	return (cost_a + cost_b + 1);
}

t_node	*get_min_push_cost(t_node **a, t_node **b, int *reverse)
{
	t_node	*start;
	t_node	*curent;
	t_node	*p_min;
	int		min_cost;
	int		i;

	start = (*a);
	curent = (*a);
	min_cost = 2147482647;
	i = 0;
	while (TRUE)
	{
		if (get_push_cost(*b, curent, i, reverse) < min_cost)
		{
			p_min = curent;
			min_cost = get_push_cost(*b, curent, i, reverse); 
		}
		curent = curent->next;
		i++;
		if (curent == start)
			break;
	}
	return (p_min);
}

t_node *get_elem(int val, t_node *b)
{
	t_node	*start;
	t_node	*closest;
	int		closest_diff;

	start = b;
	closest = b;
	closest_diff = abs(val - b->val);
	while (TRUE)
	{
		if ((ft_abs(val - b->val) < closest_diff) && val > b->val)
		{
			closest_diff = ft_abs(val - b->val);
			closest = b;
		}
		b = b->next;
		if (b == start)
			break;
	}
	return (closest); 
}

void do_min_cost_push_b(t_node **a, t_node **b, t_node *elem_a, int rev)
{
	t_node	*elem_b;
	t_node	*iterator;

	iterator = *a;
	while (iterator != elem_a)
	{
		ra(a);
		iterator = iterator->next;
	}
	elem_b = get_elem(elem_a->val, *b);
	iterator = *b;
	while (iterator != elem_b)
	{
		if (rev)
		{
			rrb(b);
			iterator = iterator->prev;
		}
		else 
		{
			rb(b);
			iterator = iterator->next;
		}
	}
	pb(b, a);
}

void do_min_cost_push_a(t_node **a, t_node **b, t_node *elem_b, int rev)
{
	t_node	*elem_a;
	t_node	*iterator;

	iterator = *b;
	while (iterator != elem_b)
	{
		if (rev)
		{
			rrb(b);
			iterator = iterator->prev;
		}
		else 
		{
			rb(b);
			iterator = iterator->next;
		}
	}
	elem_a = get_elem(elem_b->val, *a);
	iterator = *a;
	while (iterator != elem_a)
	{
		if (rev)
		{
			rra(a);
			iterator = iterator->prev;
		}
		else 
		{
			ra(a);
			iterator = iterator->next;
		}
	}
	pa(a, b);
}
