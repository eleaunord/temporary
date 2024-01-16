#include "push_swap.h"

// void push(t_node **dest, t_node **src)
// {
//     t_node  *first;

//     if (*src == NULL)
//         return ;
//     first = *src;
//     *src = (*src)->next;
//     if (*src)
//         (*src)->prev = NULL;
//     first->prev = NULL;
//     if (*dest == NULL)
//     {
//         *dest = first;
//         first->next = NULL;
//     }
//     else
//     {
//         first->next = *dest;
//         first->next->prev = first;
//         *dest = first;
//     }
// }
void	push(t_node **dest, t_node **src)
{
	t_node	*node_to_push;

	if (NULL == *src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (NULL == *dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void    pa(t_node **a, t_node **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void    pb(t_node **b, t_node **a)
{
    push(b, a);
    write(1, "pb\n", 3);
}
