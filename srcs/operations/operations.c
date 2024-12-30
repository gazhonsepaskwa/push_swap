#include "operations.h"

void	push(t_node **from, t_node **to)
{
	t_node	*mooving;

	if (!(*from))
		return ;
	mooving = deco_node(from);
	reco_node(to, &mooving);
}

void	swap(t_node **first)
{
	int	tmp;

	if (!(*first))
		return ;
	tmp = (*first)->next->val;
	(*first)->next->val = (*first)->val;
	(*first)->val = tmp;
}

void	rotate(t_node **first)
{
	if (!(*first))
		return ;
	*first = (*first)->next;
}

void	rev_rotate(t_node **first)
{
	if (!(*first))
		return ;
	*first = (*first)->prev;
}
