#include "operations.h"

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_put_s("pa\n");
	// print_stack(a, b);
}

void	pb(t_node **b, t_node **a)
{
	push(a, b);
	ft_put_s("pb\n");
	// print_stack(a, b);
}

void	sa(t_node **a)
{
	swap(a);
	ft_put_s("sa\n");
	// print_stack(a, NULL);
}

void	sb(t_node **b)
{
	swap(b);
	ft_put_s("sb\n");
	// print_stack(NULL, b);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	ft_put_s("ss\n");
	// print_stack(a, b);
}
