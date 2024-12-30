/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_p_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:47:56 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:47:57 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	ft_put_s("pa\n");
}

void	pb(t_node **b, t_node **a)
{
	push(a, b);
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
