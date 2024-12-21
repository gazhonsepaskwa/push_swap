#include "../push_swap.h"

int main(int ac, char **av)
{
	char	**tab;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
	{
		ft_error("./push_swap <values> || ./push_swap ...\n");
		return (1);
	}
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		create_stack(&stack_a, tab, 0);
		if (!stack_a)
		{
			ft_error("[CRASH] Stack not created");
			return (1);
		}
		free_tab(tab);
	}

	print_stacks(stack_a, stack_b);

	push(&stack_a, &stack_b);
	/*push(&stack_a, &stack_b);*/
	/*push(&stack_a, &stack_b);*/
	/*push(&stack_a, &stack_b);*/
	/*push(&stack_a, &stack_b);*/
	/*push(&stack_a, &stack_b);*/
	/*push(&stack_b, &stack_a);*/
	/*swap(&stack_b);*/
	/*rev_rotate(&stack_b);*/
	/*rotate(&stack_b);*/
	ft_put_s("\n");

	print_stacks(stack_a, stack_b);
	/*print_stack(stack_b);*/
	free_stack(stack_a);
	/*ft_debug("stack a freed\n");*/
	free_stack(stack_b);
	/*ft_debug("stack b freed\n");*/
	return (0);
}
