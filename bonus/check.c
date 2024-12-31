/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:46:07 by nalebrun          #+#    #+#             */
/*   Updated: 2024/12/30 17:46:23 by nalebrun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-'
			&& str[i] != '+' && !ft_isdigit(str[i]))
			return (0);
		if (str[i] == '+' || str[i] == '-')
			if (str[i + 1] == 0 || !ft_isdigit(str[i + 1]))
				return (0);
		i++;
	}
	return (1);
}

static int	tab_error(char **tab, int start, int free)
{
	int		i;

	i = 0;
	while (tab[start + i])
	{
		if (!only_num(tab[start + i]))
		{
			if (free)
				free_tab(tab);
			return (1);
		}
		if (ft_atoi(tab[start + i]) == 2147483648L)
		{
			if (free)
				free_tab(tab);
			return (1);
		}
		i++;
	}
	if (free)
		free_tab(tab);
	return (0);
}

int	ft_strequal(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	find_double(char **tab, int start, int free)
{
	int		i;
	int		j;
	char	*current;

	i = start;
	while (tab[i])
	{
		current = tab[i];
		j = start;
		while (j < i)
		{
			if (ft_strequal(tab[j], current))
			{
				if (free)
					free_tab(tab);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
	if (free)
		free_tab(tab);
}

int	check_error(int ac, char **av)
{
	char	**tab;	

	if (ac == 2)
	{
		if (!av[1][0])
			return (ft_error("Error\n"));
		tab = ft_split(av[1], ' ');
		if (find_double(tab, 0, 1))
			return (ft_error("Error\n"));
		if (tab_error(tab, 0, 1))
			return (ft_error("Error\n"));
	}
	else
	{
		if (find_double(av, 1, 0))
			return (ft_error("Error\n"));
		if (tab_error(av, 1, 0))
			return (ft_error("Error\n"));
	}
	return (0);
}
