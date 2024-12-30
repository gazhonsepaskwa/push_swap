/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:48:50 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:48:51 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	int				val;
	struct s_node	*next;
}	t_node;

// stack.c
int		create_stack(t_node **stack, char **tab, int start, int lim);
int		free_stack(t_node *stack);
void	print_stack(t_node **a, t_node **b);

// check.c
int		check_error(int ac, char **av);

// sort.c
int		sort(t_node **a, t_node **b);

// init.c
int		init(int ac, char **av, t_node **stack_a);

#endif
