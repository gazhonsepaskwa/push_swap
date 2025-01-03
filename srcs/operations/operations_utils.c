/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:48:21 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:48:22 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_node	*deco_node(t_node **from)
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
