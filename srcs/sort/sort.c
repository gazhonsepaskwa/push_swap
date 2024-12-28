#include "sort.h"

void	sort_tree(t_node **a)
{
	int	first = (*a)->val;
	int	second = (*a)->next->val;
	int	third = (*a)->next->next->val;

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

int	sort_other(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		reverse;

	reverse  = FALSE;
	while (TRUE)
	{
		if (sorted(a) && (*b) == NULL)
			break;
		if (get_cll_len(a) == 3)
		{
			sort_tree(a);
			/*while (*b && *a)*/
			/*{*/
			/*	ft_printf(" %p ", *a);*/
			/*	tmp = get_min_push_cost(b, a, &reverse); */
			/*	do_min_cost_push_a(a, b, tmp, reverse);*/
			/*}*/
			break;
		}
		else
		{
			tmp = get_min_push_cost(a, b, &reverse); 
			do_min_cost_push_b(a, b, tmp, reverse);
		}
	}
	return (0);
}

int sort(t_node **a, t_node **b)
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
		/*pb(b,a); // to test*/
		/*pb(b,a); // to test*/
		if (len_a > 4)
			 pb(b, a);
		pb(b, a);
		sort_other(a, b);
	}
	return (0);
}
