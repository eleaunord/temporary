#include "push_swap.h"
// void swap(t_node **lst)
// {
//     t_node *first;
//     t_node *second;

//     first = *lst;
//     second = (*lst)->next;
//     if (*lst == NULL || (*lst)->next == NULL)
//         return ;
//     first->prev = second;
//     first->next = second->next;
//     if (second->next)
//         second->next->prev = first;
//     second->next = first;
//     second->prev = NULL;
//     *lst = second; 
// }

void    sa(t_node **a)
{
    swap(a);
}

void    sb(t_node **b)
{
    swap(b);
}

void    ss(t_node **a, t_node **b)
{
    swap(a);
    swap(b);
}
