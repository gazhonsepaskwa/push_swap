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
int		create_stack(t_node **stack, char **tab, int start);
void	print_stack(t_node *stack);
int		free_stack(t_node *stack);
void	print_stacks(t_node *stacka, t_node *stackb);

// check.c
int check_error(int ac, char **av);

// init.c
int init(int ac, char **av, t_node **stack_a);

#endif
