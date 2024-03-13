
//NB store head pointer
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


//
//include "ft_list.h"
void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *head;

    head = begin_list;
    while(head)
    {
        (*f)(head->data);
        head = head->next;
    }
}