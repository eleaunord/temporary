#include "push_swap.h"

int    find_max(t_node *lst)
{
    int max;
    int current;

    max = lst->content;
    while (lst->next != NULL)
    {
        current = lst->next->content;
        if (current > max)
        {
            max = current;
        }
        lst = lst->next;
    }
    return (max);
}