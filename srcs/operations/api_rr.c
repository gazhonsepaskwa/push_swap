/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_rr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:48:03 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:48:15 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
