#include "sort.h"

static void	case1(t_cost cost, t_node **a, t_node **b)
{
	if (cost.a < cost.b)
	{
		multi_rotate(cost.a, "rr ", a, b);
		multi_rotate(cost.b - cost.a, "ra ", b, a);
	}
	if (cost.a > cost.b)
	{
		multi_rotate(cost.b, "rr ", a, b);
		multi_rotate(cost.a - cost.b, "rb ", b, a);
	}
	if (cost.a == cost.b)
		multi_rotate(cost.b, "rr ", a, b);
}

static void	case2(t_cost cost, t_node **a, t_node **b)
{
	if (cost.a < cost.b)
	{
		multi_rotate(cost.a, "rrr", a, b);
		multi_rotate(cost.b - cost.a, "rra", b, a);
	}
	if (cost.a > cost.b)
	{
		multi_rotate(cost.b, "rrr", a, b);
		multi_rotate(cost.a - cost.b, "rrb", b, a);
	}
	if (cost.a == cost.b)
		multi_rotate(cost.b, "rrr", a, b);
}

static void	case3(t_cost cost, t_rev rev, t_node **a, t_node **b)
{
	if (!rev.a)
		multi_rotate(cost.a, "rb ", b, a);
	else
		multi_rotate(cost.a, "rrb", b, a);
	if (!rev.b)
		multi_rotate(cost.b, "ra ", b, a);
	else
		multi_rotate(cost.b, "rra", b, a);
}

void	do_min_cost_push_a(t_node **a, t_node **b, t_node *best_a)
{
	t_node	*elem_b;
	t_cost	cost;
	t_rev	rev;

	cost.a = get_cost_to_top(*a, best_a, &rev.a);
	elem_b = get_elem(best_a->val, *b, "a");
	cost.b = get_cost_to_top(*b, elem_b, &rev.b);
	if (rev.a == rev.b && !rev.a)
		case1(cost, a, b);
	else if (rev.a == rev.b && rev.a)
		case2(cost, a, b);
	else
		case3(cost, rev, a, b);
	pa(b, a);
}
