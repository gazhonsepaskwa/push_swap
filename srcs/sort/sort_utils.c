#include "sort.h"

int	sorted(t_node **a)
{
	t_node	*start;
	t_node	*actual;

	start = (*a);
	actual = (*a);
	while (actual->next != start)
	{
		if (actual->next->val < actual->val)
			return(0);
		actual = actual->next;
	}
	return (1);
}

int	get_cll_len(t_node **a)
{
	t_node	*start;
	t_node	*actual;
	int		i;

	start = (*a);
	actual = (*a);
	i = 0;
	while (actual->next != start)
	{
		actual = actual->next;
		i++;
	}
	i++;
	return (i);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_node *max_val_elem(t_node *head)
{
    t_node *current = head;
    t_node *max_elem = head;

    while (TRUE)
    {
        if (current->val > max_elem->val)
            max_elem = current;
        current = current->next;
		if (current == head)
			break;
    }
    return max_elem;
}
