#include "push_swap.h"

void	sort_3(t_node *lst)
{
	t_node	*i;
	t_node	*j;
	t_node	*low;
	t_node 	*high;
	int	pivot;

	low = lst;
	high = ft_lstlast(lst);
	i = low;
	j = low;
	pivot = high->content;
	while (j != high)
	{
		if (j->content < pivot)
		{
			swap();
			i = i->next;
		}
		j = j->next;
	}
	swap(&a->head);
}