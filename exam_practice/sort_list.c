
// #include "list.h"
#include <stdlib.h>

typedef struct s_list
{
	int     data;
	t_list  *next;
} t_list;

//


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int temp = 0;
     // NB to put temporary list to keep the original head of lst (we need it for return after)
    t_list *temp_list;

    temp_list = lst;
    while (lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            temp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = lst->data;
            // after the swap the lst pointer is reset to the original head of the lst
            lst = temp_list;
        }
        else // NB to put else
            lst = lst->next;
    }
    // est lst to original head
    lst = temp_list;
    return(lst);
}