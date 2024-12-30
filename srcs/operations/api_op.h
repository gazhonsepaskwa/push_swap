/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_op.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:47:52 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:47:53 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_OP_H
# define API_OP_H

# include "../../push_swap.h"

void	pa(t_node **a, t_node**b);
void	pb(t_node**b, t_node **a);
void	sa(t_node **a);
void	sb(t_node**b);
void	ss(t_node **a, t_node**b);

void	ra(t_node **a);
void	rb(t_node**b);
void	rr(t_node **a, t_node**b);

void	rra(t_node **a);
void	rrb(t_node**b);
void	rrr(t_node **a, t_node**b);

#endif
