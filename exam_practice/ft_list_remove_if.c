#include <stddef.h>
#include <stdio.h>

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *current;

    //input pointer or list it points to
    if (!begin_list || (*begin_list) == NULL)
        return ;
    current = *begin_list;
    if (cmp(current->data, data_ref) == 0)
    {
        //update beg list to skip current node
        *begin_list = current->next;
        free(current);
        //recursively call the function to continue removing nodes
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    //move to the next node and recursively call the function
    current = *begin_list;
    ft_list_remove_if(&current->next, data_ref, cmp);

}
