
#ifndef SORT_H
# define SORT_H

# include "../../push_swap.h"
# include "../operations/api_op.h"
# include <limits.h>

typedef struct s_cost
{
	int	a;
	int	b;
	int	min;
}		t_cost;

typedef struct s_rev
{
	int	a;
	int	b;
}		t_rev;

// sort_utils
int		sorted(t_node **a);
int		get_cll_len(t_node **a);
int		ft_abs(int num);
t_node	*max_val_elem(t_node *head);

// sort_other
t_node	*get_min_push_cost(t_node *a, t_node *b);
int	get_cost_to_top(t_node *head, t_node *node, int *rev);
t_node *get_elem_b(int trgt_val, t_node *b);
void	do_min_cost_push(t_node **a, t_node **b, t_node *best_a);

#endif
