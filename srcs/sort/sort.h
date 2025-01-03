/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:47:40 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:47:43 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../../push_swap.h"
# include "../operations/api_op.h"
# include <limits.h>

typedef struct s_cost
{
	int	a;
	int	b;
	int	min;
}		t_cost;

typedef struct s_rev
{
	int	a;
	int	b;
}		t_rev;

// sort_utils
t_node	*max_val_elem(t_node *head);
t_node	*min_val_elem(t_node *head);
void	multi_rotate(int count, char *rotate, t_node **a, t_node **b);
void	shift_up(t_node **a);
int		get_cll_len(t_node **a);
int		sorted(t_node **a);
int		ft_abs(int num);

// sort_other
t_node	*get_min_push_cost(t_node *a, t_node *b, char *stack);
t_node	*get_elem(int trgt_val, t_node *b, char *stack);
void	do_min_cost_push_b(t_node **a, t_node **b, t_node *best_a);
void	do_min_cost_push_a(t_node **a, t_node **b, t_node *best_a);
int		get_cost_to_top(t_node *head, t_node *node, int *rev);

#endif
