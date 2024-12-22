#include "operations.h"

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_put_s("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_put_s("pb\n");
}

void	sa(t_node **a)
{
	swap(a);
	ft_put_s("sa\n");
}

void	sb(t_node **b)
{
	swap(b);
	ft_put_s("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_put_s("ss\n");
}
