
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

void	push(t_node **from, t_node **to);
void	swap(t_node **first);
void	rotate(t_node **first);
void	rev_rotate(t_node **first);

# endif
