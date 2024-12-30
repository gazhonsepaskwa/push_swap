/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:48:29 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:48:38 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../../push_swap.h"

t_node	*deco_node(t_node **from);
void	reco_node(t_node **to, t_node **mooving);
void	push(t_node **from, t_node **to);
void	swap(t_node **first);
void	rotate(t_node **first);
void	rev_rotate(t_node **first);

#endif
