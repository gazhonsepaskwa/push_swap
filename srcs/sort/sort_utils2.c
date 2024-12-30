/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:47:29 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:47:30 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

t_node	*max_val_elem(t_node *head)
{
	t_node	*current;
	t_node	*max_elem;

	current = head;
	max_elem = head;
	while (TRUE)
	{
		if (current->val > max_elem->val)
			max_elem = current;
		current = current->next;
		if (current == head)
			break ;
	}
	return (max_elem);
}

t_node	*min_val_elem(t_node *head)
{
	t_node	*current;
	t_node	*min_elem;

	current = head;
	min_elem = head;
	while (TRUE)
	{
		if (current->val < min_elem->val)
			min_elem = current;
		current = current->next;
		if (current == head)
			break ;
	}
	return (min_elem);
}

void	multi_rotate(int count, char *rotate, t_node **a, t_node **b)
{
	while (count != 0)
	{
		if (!ft_strncmp(rotate, "rr ", 3))
			rr(a, b);
		if (!ft_strncmp(rotate, "ra ", 3))
			ra(a);
		if (!ft_strncmp(rotate, "rra", 3))
			rra(a);
		if (!ft_strncmp(rotate, "rb ", 3))
			rb(b);
		if (!ft_strncmp(rotate, "rrb", 3))
			rrb(b);
		if (!ft_strncmp(rotate, "rrr", 3))
			rrr(a, b);
		count--;
	}
}
