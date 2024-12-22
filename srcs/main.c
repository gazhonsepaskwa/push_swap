#include "../push_swap.h"
#include "operations/api_op.h"

int main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (check_error(ac, av))
		return (1);
	if (!init(ac, av, &stack_a))
		return (1);
	print_stacks(stack_a, stack_b);
	
	pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	pa(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	/*pb(&stack_b, &stack_a);*/
	/*pb(&stack_b, &stack_a);*/
	rra(&stack_a);
	rrb(&stack_b);
	print_stacks(stack_a, stack_b);

	ft_put_s("\n");

	print_stacks(stack_a, stack_b);
	/*print_stack(stack_b);*/
	free_stack(stack_a);
	/*ft_debug("stack a freed\n");*/
	free_stack(stack_b);
	/*ft_debug("stack b freed\n");*/
	return (0);
}
