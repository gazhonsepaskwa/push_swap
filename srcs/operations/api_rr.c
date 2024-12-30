#include "operations.h"

void	rra(t_node **a)
{
	rev_rotate(a);
	ft_put_s("rra\n");
	// print_stack(a, NULL);
}

void	rrb(t_node **b)
{
	rev_rotate(b);
	ft_put_s("rrb\n");
	// print_stack(NULL, b);
}

void	rrr(t_node **a, t_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_put_s("rrr\n");
	// print_stack(a, b);
}
