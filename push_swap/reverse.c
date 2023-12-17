#include "push_swap.h"

void	reverse(t_node **lst)
{
	t_node	*last;
	t_node	*tmp;

	last = *lst;
	tmp = *lst;
	while (last->next)
	{
		last = last->next;
		if (last->next == NULL)
			break ;
		tmp = tmp->next;
	}
	ft_lstadd_front(lst, last);
	tmp->next = NULL;
}

void    rra(t_node **a)
{
    reverse(a);
}

void    rrb(t_node **b)
{
    reverse(b);
}

void    rrr(t_node **a, t_node **b)
{
    reverse(a);
    reverse(b);
}