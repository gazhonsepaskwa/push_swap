#include "sort.h"

int	get_cost_to_top(t_node *head, t_node *node, int *rev)
{
	int		stack_len;
	int		cost;
	t_node	*current;

	cost = 0;
	stack_len = get_cll_len(&head);
	current = head;
	while (current != node)
	{
		cost++;
		current = current->next;
	}
	if (cost > stack_len / 2)
	{
		cost = stack_len - cost;
		*rev = TRUE;
	}
	else
		*rev = FALSE;
	return (cost);
}

t_node *get_closest(t_node *current, int trgt_val, int reset)
{
	static t_node	*closest = NULL;
	static int		closest_diff = INT_MAX;

	if (reset)
	{
		closest = NULL;
		closest_diff = INT_MAX;
		return (NULL);
	}

	if (closest_diff > ft_abs(current->val - trgt_val))
	{
		closest_diff = ft_abs(current->val - trgt_val);
		closest = current;
	}
	return (closest);
}

t_node *get_elem_b(int trgt_val, t_node *b)
{
	t_node	*current;
	t_node	*elem_b;

	current = b;
	elem_b = NULL;
	while (TRUE)	
	{
		if (current->val < trgt_val)
			elem_b = get_closest(current, trgt_val, 0); 
		current = current->next;
		if (current == b)
			break;
	}
	get_closest(NULL, 0, 1); 
	if (elem_b == NULL)
		return (max_val_elem(b));
	return (elem_b);

}

int	get_real_cost(t_cost cost, t_rev rev)
{
	int	out;

	if (rev.a == rev.b)
	{
		if (cost.a == cost.b)
			out = cost.a;
		if (cost.a > cost.b)
			out = cost.a;
		if (cost.a < cost.b)
			out = cost.b;
	}
	else
		out = cost.a + cost.b;
	return (out);
}

t_node	*get_min_push_cost(t_node *a, t_node *b)
{
	t_node	*elem_a;
	t_node	*elem_b;
	t_node	*best_a;
	t_cost	cost;
	t_rev	rev;

	elem_a = a;
	cost.min = INT_MAX;
	ft_debug("  | elem_a | cost_a |  -  | elem_b | cost_b |  -  | total_cost | real_total_cost |\n");
	while (TRUE)
	{
		cost.a = get_cost_to_top(a, elem_a, &rev.a);
		elem_b = get_elem_b(elem_a->val, b);
		cost.b = get_cost_to_top(b, elem_b, &rev.b);
		ft_debug("  |   %d    |   %d    |  -  |   %d    |   %d    |  -  |     %d      |        %d        |\n", elem_a->val, cost.a, elem_b->val, cost.b, cost.a + cost.b, get_real_cost(cost, rev));
		if (cost.min > get_real_cost(cost, rev))
		{
			cost.min = get_real_cost(cost, rev);
			best_a = elem_a;
		}
        elem_a = elem_a->next;
        if (elem_a == a)
			break;
    }
	return (best_a);
}
