
#ifndef SORT_H
# define SORT_H

#include "../../push_swap.h"
#include "../operations/api_op.h"

int	sorted(t_node **a);
int	get_cll_len(t_node **a);
t_node	*get_min_push_cost(t_node **a, t_node **b, int *reverse);
void do_min_cost_push_a(t_node **a, t_node **b, t_node *elem_a, int rev);
void do_min_cost_push_b(t_node **a, t_node **b, t_node *elem_a, int rev);

#endif
