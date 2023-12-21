#include "push_swap.h"

void rotate(t_node **lst)
{
    t_node  *last;

    if (*lst == NULL || (*lst)->next == NULL)
        return ;
    last = ft_lstlast(*lst);
    last->next = *lst;
    *lst = (*lst)->next;
    (*lst)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
}

void    ra(t_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_node **b, t_node **a)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}