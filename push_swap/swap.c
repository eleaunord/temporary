#include "push_swap.h"
void	swap(t_node **head)
{
	t_node *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void    sa(t_node **a)
{
    swap(a);
	write(1, "sa\n", 3);
}

void    sb(t_node **b)
{
    swap(b);
	write(1, "sb\n", 3);
}

void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
	write(1, "ss\n", 3);
}
