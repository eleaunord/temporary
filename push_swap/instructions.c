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
int    find_min(t_node *lst)
{
    int min;
    int current;

    min = lst->content;
    while (lst->next != NULL)
    {
        current = lst->next->content;
        if (current < min)
        {
            min = current;
        }
        lst = lst->next;
    }
    return (min);
}
