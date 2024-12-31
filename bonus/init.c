/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:46:31 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:46:46 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init(int ac, char **av, t_node **stack_a)
{
	char	**tab;

	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		create_stack(stack_a, tab, 0, 2147483647);
		if (!(*stack_a))
		{
			ft_error("Error\n");
			free_tab(tab);
			return (0);
		}
		free_tab(tab);
	}
	else
	{
		create_stack(stack_a, av, 1, ac);
		if (!(*stack_a))
		{
			ft_error("Error\n");
			return (0);
		}
	}
	return (1);
}
