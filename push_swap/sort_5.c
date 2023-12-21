#include "push_swap.h"

t_node *find_max_node(t_node **a, int value)
{
    t_node *current;
    t_node *max_node;

    max_node = NULL;
    current = *a;
    while (current != NULL)
    {
        if (current->content == value)
            max_node = current;
        current = current->next;
    }
    return (max_node);
}

void max_on_top(t_node **a, t_node *max_node, t_node **pos)
{
    t_node *prev_node = *a;

    if (max_node != NULL)
    {
        // Find the node before max_node
        while (prev_node->next != max_node)
            prev_node = prev_node->next;

        // Update pointers to move max_node to the head
        prev_node->next = max_node->next;
        max_node->next = *pos;
        *pos = max_node;
    }
}

void sort_5(t_node **a, t_node **b)
{
    max_values maxValues = find_max(*a);
    t_node *max_node = NULL;
    t_node *next_max_node = NULL;

    if (is_sorted(a) == true)
        return;
    //
    max_node = find_max_node(a, maxValues.max);
    max_on_top(a, max_node, a);
    //
    next_max_node = find_max_node(a, maxValues.next_max);
    max_on_top(a, next_max_node, &((*a)->next));
    //
    pb(b, a);
    pb(b, a);
    // //
    sort_3(a);
    // //
    pa(a, b);
    ra(a);
    pa(a, b);
    ra(a);
}