#include "push_swap.h"

static void push(t_node **dest, t_node **src)
{
    t_node  *first;

    if (*src == NULL)
        return ;
    first = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    first->prev = NULL;
    if (*dest == NULL)
    {
        *dest = first;
        first->next = NULL;
    }
    else
    {
        first->next = *dest;
        first->next->prev = first;
        *dest = first;
    }
}

void    pa(t_node **a, t_node **b)
{
    push(a, b);
}

void    pb(t_node **b, t_node **a)
{
    push(b, a);
}