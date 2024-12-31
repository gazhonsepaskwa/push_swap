/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:46:53 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:46:54 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "operations.h"

int	ft_strequal(char *s1, char *s2);

int	sorted(t_node **a)
{
	t_node	*start;
	t_node	*actual;

	start = (*a);
	actual = (*a);
	while (actual->next != start)
	{
		if (actual->next->val < actual->val)
			return (0);
		actual = actual->next;
	}
	return (1);
}

void	dubble(t_node **a, t_node **b, void (*fct)(t_node **))
{
	fct(a);
	fct(b);
}

int	switch_case(t_node **a, t_node **b, char *line)
{
	if (ft_strequal(line, "sa\n"))
		swap(a);
	else if (ft_strequal(line, "sb\n"))
		swap(b);
	else if (ft_strequal(line, "ra\n"))
		rotate(a);
	else if (ft_strequal(line, "rb\n"))
		rotate(b);
	else if (ft_strequal(line, "rra\n"))
		rev_rotate(a);
	else if (ft_strequal(line, "rrb\n"))
		rev_rotate(b);
	else if (ft_strequal(line, "rr\n"))
		dubble(a, b, rotate);
	else if (ft_strequal(line, "rrr\n"))
		dubble(a, b, rev_rotate);
	else if (ft_strequal(line, "pb\n"))
		push(a, b);
	else if (ft_strequal(line, "pa\n"))
		push(b, a);
	else
		return (1);
	return (0);
}

int	prosses(t_node **a, t_node **b)
{
	char	*line;
	int		error;

	(void)a;
	(void)b;
	line = get_next_line(0);
	while (line)
	{
		error = switch_case(a, b, line);
		free(line);
		line = get_next_line(0);
	}
	if (error == 1)
		return (ft_error("Error\n"));
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	if (check_error(ac, av))
		return (1);
	if (!init(ac, av, &stack_a))
		return (1);
	if (prosses(&stack_a, &stack_b) == -1)
		return (1);
	if (sorted(&stack_a) && !stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
