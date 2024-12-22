#include "operations.h"

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_put_s("rra\n");
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_put_s("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_put_s("rrr\n");
}
