#include "../push_swap.h"

int	only_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		{
			return (0);
		}
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
			return (1);
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

int check_error(int ac, char **av)
{
	char	**tab;	

	if (ac < 2)
		return (ft_error("Error\n"));
	if (ac == 2)
	{
		if (!av[1][0])
			return (-1);
		tab = ft_split(av[1], ' ');
		if (tab_error(tab, 0, 1))
			return (ft_error("Error\n"));
	}
	else
	{
		if (tab_error(av, 1, 0))
			return (ft_error("Error\n"));
	}
	return (0);
}
