#include "../push_swap.h"

static t_node *create_node(int val, t_node *prev)
{
	t_node	*self;

	self = malloc(sizeof(t_node));
	if (!self)
		return (NULL);
	self->val = val;
	self->prev = prev;
	self->next = NULL;
	return (self);
}


int create_stack(t_node **stack, char **tab, int start)
{
    int i;
    t_node *prev;

    i = 0;
    *stack = create_node(ft_atoi(tab[start]), NULL);
    if (!(*stack))
        return (free_stack(*stack));
    prev = *stack;
    while (tab[start + i + 1])
    {
        prev->next = create_node(ft_atoi(tab[start + i + 1]), prev);
        if (!prev->next)
            return (free_stack(*stack));
        prev = prev->next;
        i++;
    }
	prev->next = *stack;
    (*stack)->prev = prev;
    return (0);
}

void	print_stack(t_node *stack)
{
	t_node *start;
	t_node *actual;

	if (!stack)
	{
		ft_error("unvalide stack");
		return ;
	}
	start = stack;
	actual = stack;
	ft_printf("%d\n", actual->val);
	while (actual->next != start)
	{
		actual = actual->next;
		ft_printf("%d\n", actual->val);
	}
}

void	print_stacks(t_node *stacka, t_node *stackb)
{
	t_node	*starta;
	t_node	*startb;
	t_node	*actuala;
	t_node	*actualb;

	starta = stacka;
	startb = stackb;
	actuala = stacka;
	actualb = stackb;
	ft_printf("a | b\n=====\n");

	while (actuala || actualb) // Loop while there's data in either stack
	{
		if (actuala)
		{
			ft_printf("%d |", actuala->val);
			actuala = (actuala->next != starta) ? actuala->next : NULL;
		}
		else
			ft_printf("  |");

		if (actualb)
		{
			ft_printf(" %d\n", actualb->val);
			actualb = (actualb->next != startb) ? actualb->next : NULL;
		}
		else
			ft_printf("  \n");
	}
}

int	free_stack(t_node *stack)
{
	t_node *start;
	t_node *second;

	if (!stack)
		return (-1);
	start = stack;
	while (start->next != start)
	{
		second = stack->next;
		stack->next = stack->next->next;
		free(second);
		second = NULL;
	}
	free(start);
	return (-1);
}
