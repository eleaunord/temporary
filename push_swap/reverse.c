#include "push_swap.h"

static void reverse(t_node **lst)
{
    t_node  *last;

    if (*lst == NULL || (*lst)->next == NULL)
        return ;
    last = ft_lstlast(*lst);
    last->prev->next = NULL;
    last->next = *lst;
    last->prev = NULL;
    *lst = last;
    last->next->prev = last;
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