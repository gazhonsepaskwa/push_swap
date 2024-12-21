
#include "../push_swap.h"


t_node *deco_node(t_node **from)
{
	t_node	*mooving;

	if (!((*from)->next == (*from)))
	{
		(*from)->prev->next = (*from)->next;
		(*from)->next->prev = (*from)->prev;
		mooving = (*from);
		(*from) = (*from)->next;
	}
	else
	{
		mooving = (*from);
		(*from) = NULL;
	}
	return (mooving);
}

void	reco_node(t_node **to, t_node **mooving)
{
	if (*to)
	{
		(*mooving)->prev = (*to)->prev;
		(*mooving)->next = (*to);
		(*to)->prev->next = (*mooving);
		(*to)->prev = (*mooving);
	}
	else
	{
		(*mooving)->prev = (*mooving);
		(*mooving)->next = (*mooving);
	}
	(*to) = (*mooving);
}

// have a look to operations.drawio to understand :)
void	push(t_node **from, t_node **to)
{
	(void)to;
	t_node *mooving;
	if (!(*from))
		return ;
	mooving = deco_node(from);
	reco_node(to, &mooving);
}

void	swap(t_node **first)
{
	int tmp;
	if (!(*first))
		return;
	tmp = (*first)->next->val;
	(*first)->next->val = (*first)->val;
	(*first)->val = tmp;
}

void	rotate(t_node **first)
{
	if (!(*first))
		return;
	*first = (*first)->next;
}

void	rev_rotate(t_node **first)
{
	if (!(*first))
		return;
	*first = (*first)->prev;
}

/*pa(t_node a, t_node b)*/
/*{*/
/*	push(a, b);*/
/*	ft_put_s("pa\n");*/
/*}*/
/**/
/*pb(t_node b, t_node a)*/
/*{*/
/*	push(b, a);*/
/*	ft_put_s("pb\n");*/
/*}*/
/**/
/*sa(t_node a)*/
/*{*/
/*	swap(a);*/
/*	ft_put_s("sa\n");*/
/*}*/
/**/
/*sb(t_node b)*/
/*{*/
/*	swap(b);*/
/*	ft_put_s("sb\n");*/
/*}*/
