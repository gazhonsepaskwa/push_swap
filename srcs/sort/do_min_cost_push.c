# include "sort.h"

void	multi_rotate(int count, char *rotate, t_node **a, t_node **b)
{
	while (count != 0)
	{
		if (!ft_strncmp(rotate, "rr ", 3))
			rr(a, b);
		if (!ft_strncmp(rotate, "ra ", 3))
			ra(a);
		if (!ft_strncmp(rotate, "rra", 3))
			rra(a);
		if (!ft_strncmp(rotate, "rb ", 3))
			rb(b);
		if (!ft_strncmp(rotate, "rrb", 3))
			rrb(b);
		if (!ft_strncmp(rotate, "rrr", 3))
			rrr(a, b);
		count--;
	}
}

void	do_min_cost_push(t_node **a, t_node **b, t_node *best_a)
{
	t_node	*elem_b;
	t_cost	cost;
	t_rev	rev;

	cost.a = get_cost_to_top(*a, best_a, &rev.a);
	elem_b = get_elem_b(best_a->val, *b);
	cost.b = get_cost_to_top(*b, elem_b, &rev.b);

	if (rev.a == rev.b && !rev.a)
	{
		if (cost.a < cost.b)
		{
			multi_rotate(cost.a, "rr ", a, b);
			multi_rotate(cost.b - cost.a, "rb ", a, b);
		}
		if (cost.a > cost.b)
		{
			multi_rotate(cost.b, "rr ", a, b);
			multi_rotate(cost.a - cost.b, "ra ", a, b);
		}
	}
	else if (rev.a == rev.b && rev.a)
	{
		if (cost.a < cost.b)
		{
			multi_rotate(cost.a, "rrr", a, b);
			multi_rotate(cost.b - cost.a, "rrb", a, b);
		}
		if (cost.a > cost.b)
		{
			multi_rotate(cost.b, "rrr", a, b);
			multi_rotate(cost.a - cost.b, "rra", a, b);
		}
	}
	else
	{
		if (!rev.a)
			multi_rotate(cost.a, "ra ", a, b);
		else
			multi_rotate(cost.a, "rra", a, b);
		if (!rev.b)
			multi_rotate(cost.b, "rb ", a, b);
		else
			multi_rotate(cost.b, "rrb", a, b);
	}
	pb(b, a);
}
























// t_node *get_elem(int val, t_node *b)
// {
// 	t_node	*start;
// 	t_node	*closest;
// 	int		closest_diff;
//
// 	start = b;
// 	closest = b;
// 	closest_diff = abs(val - b->val);
// 	while (TRUE)
// 	{
// 		if ((ft_abs(val - b->val) < closest_diff) && val > b->val)
// 		{
// 			closest_diff = ft_abs(val - b->val);
// 			closest = b;
// 		}
// 		b = b->next;
// 		if (b == start)
// 			break;
// 	}
// 	return (closest); 
// }

// void do_min_cost_push_b(t_node **a, t_node **b, t_node *elem_a, int rev)
// {
// 	t_node	*elem_b;
// 	t_node	*iterator;
//
// 	iterator = *a;
// 	while (iterator != elem_a)
// 	{2    |  -  |   9    |   1 
// 		ra(a);
// 		iterator = iterator->next;
// 	}
// 	elem_b = get_elem(elem_a->val, *b);
// 	iterator = *b;
// 	while (iterator != elem_b)
// 	{
// 		if (rev)
// 		{
// 			rrb(b);
// 			iterator = iterator->prev;
// 		}
// 		else 
// 		{
// 			rb(b);
// 			iterator = iterator->next;
// 		}
// 	}
// 	pb(b, a);
// }

// void do_min_cost_push_a(t_node **a, t_node **b, t_node *elem_b, int rev)
// {
// 	t_node	*elem_a;
// 	t_node	*iterator;
//
// 	iterator = *b;
// 	while (iterator != elem_b)
// 	{
// 		if (rev)
// 		{
// 			rrb(b);
// 			iterator = iterator->prev;
// 		}
// 		else 
// 		{
// 			rb(b);
// 			iterator = iterator->next;
// 		}
// 	}
// 	elem_a = get_elem(elem_b->val, *a);
// 	iterator = *a;
// 	while (iterator != elem_a)
// 	{
// 		if (rev)
// 		{
// 			rra(a);
// 			iterator = iterator->prev;
// 		}
// 		else 
// 		{
// 			ra(a);
// 			iterator = iterator->next;
// 		}
// 	}
// 	pa(a, b);
// }
