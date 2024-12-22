#include "../push_swap.h"

static int	tab_error(char **tab, int start)
{
	int		i;

	i = 0;
	while (tab[start + i])
	{
		if (ft_atoi(tab[start + i]) == 2147483648L)
		{
			free_tab(tab);
			return (1);
		}
		i++;
	}
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
			return (-1); // sould I print error ?? 
		tab = ft_split(av[1], ' ');
		if (tab_error(tab, 0))
			return (ft_error("Error\n"));
	}
	else
	{
		return (0);
	}
	return (0);
}
