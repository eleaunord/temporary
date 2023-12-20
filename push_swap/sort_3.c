#include "push_swap.h"

min_values find_min(t_node *head)
{
    min_values result = {INT_MAX, INT_MAX};

    while (head != NULL)
    {
        if (head->content < result.min) 
        {
            result.next_min = result.min;
            result.min = head->content;
        }
        else if (head->content < result.next_min && head->content != result.min)
        {
            result.next_min = head->content;
        }
        head = head->next;
    }

    return result;
}


void	sort_3(t_node **lst)
{
    t_node *head;

    head = *lst;
    min_values minValues = find_min(*lst);
    //minValues.min and minValues.next_min
    if (is_sorted(lst) == true)
		return ;
    if (head->content == minValues.min && head->next->content != minValues.next_min)
    {
        sa(lst);
        ra(lst);
    }
    else if (head->content == minValues.next_min)
    {
        if (head->next->content == minValues.min)
            sa(lst);
        else
            rra(lst); 
    }
    else
    {
        if (head->next->content == minValues.min)
            ra(lst);
        else
        {
            sa(lst);
            rra(lst);
        }
        
    }

}