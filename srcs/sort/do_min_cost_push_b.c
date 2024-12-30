/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_min_cost_push_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:47:14 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:47:16 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	case1(t_cost cost, t_node **a, t_node **b)
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
	if (cost.a == cost.b)
		multi_rotate(cost.b, "rr ", a, b);
}

static void	case2(t_cost cost, t_node **a, t_node **b)
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
	if (cost.a == cost.b)
		multi_rotate(cost.b, "rrr", a, b);
}

static void	case3(t_cost cost, t_rev rev, t_node **a, t_node **b)
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

void	do_min_cost_push_b(t_node **a, t_node **b, t_node *best_a)
{
	t_node	*elem_b;
	t_cost	cost;
	t_rev	rev;

	cost.a = get_cost_to_top(*a, best_a, &rev.a);
	elem_b = get_elem(best_a->val, *b, "b");
	cost.b = get_cost_to_top(*b, elem_b, &rev.b);
	if (rev.a == rev.b && !rev.a)
		case1(cost, a, b);
	else if (rev.a == rev.b && rev.a)
		case2(cost, a, b);
	else
		case3(cost, rev, a, b);
	pb(b, a);
}
