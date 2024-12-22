#include "operations.h"

void	ra(t_node **a)
{
	rotate(a);
	ft_put_s("ra\n");
}

void	rb(t_node **b)
{
	rotate(b);
	ft_put_s("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_put_s("rr\n");
}
