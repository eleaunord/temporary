#include "push_swap.h"

//dans la libft
int ft_lstsize(t_node *lst) 
{
    int size;

    size = 0;
    while (lst->next != NULL)
    {
        ++size;
        lst = lst->next;
    }
    return (size);
}

void    ft_lstadd_front(t_node **lst, t_node *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}

t_node    *ft_lstlast(t_node *lst)
{

    if (!lst)
        return (NULL);
    while (lst->next != NULL)
    {
        lst = lst->next;
    }
    return (lst);
}
void    ft_lstadd_back(t_node **lst, t_node *new)
{
    t_node  *last;

    if (lst == NULL)
        return ;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new;
}