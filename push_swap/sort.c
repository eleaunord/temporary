#include "push_swap.h"

bool	is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (false);
		head = head->next;
	}
	return (true);
}

max_values find_max(t_node *head)
{
    max_values  result = {INT_MAX, INT_MAX};

    while (head != NULL)
    {
        if (head->content > result.max) 
        {
            result.next_max = result.max;
            result.max = head->content;
        }
        else if (head->content > result.next_max && head->content != result.max)
        {
            result.next_max = head->content;
        }
        head = head->next;
    }
    return result;
}

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

