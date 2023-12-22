#include "push_swap.h"

// t_node *find_max_node(t_node **a, int value)
// {
//     t_node *current;
//     t_node *max_node;

//     max_node = NULL;
//     current = *a;
//     while (current != NULL)
//     {
//         if (current->content == value)
//             max_node = current;
//         current = current->next;
//     }
//     return (max_node);
// }

// void max_on_top(t_node **a, t_node *max_node, t_node **pos)
// {
//     t_node *prev_node;

//     if (max_node != NULL && *a != NULL)
//     {
//         if (*a == max_node)
//             return;
//         prev_node = *a;
//         // Find the node before max_node
//         // NB : accessing NULL->next results in a segmentation fault
//         while (prev_node->next != max_node && prev_node->next != NULL)
//             prev_node = prev_node->next;
//         // Check if max_node is not in the list
//         if (prev_node->next == NULL)
//             return;
//         // Update pointers to move max_node to the head
//         prev_node->next = max_node->next;
//         max_node->next = *pos;
//         *pos = max_node;
//     }
// }

// void sort_5(t_node **a, t_node **b)
// {
//     max_values maxValues = find_max(*a);
//     t_node *max_node = NULL;
//     t_node *next_max_node = NULL;

//     if (is_sorted(a) == true)
//         return;
//     //
//     max_node = find_max_node(a, maxValues.max);
//     max_on_top(a, max_node, a);
//     //
//     next_max_node = find_max_node(a, maxValues.next_max);
//     max_on_top(a, next_max_node, &((*a)->next));
//     //
//     pb(b, a);
//     pb(b, a);
//     // //
//     sort_3(a);
//     // //
//     pa(a, b);
//     ra(a);
//     pa(a, b);
//     ra(a);
// }

int	count_n(t_node *list)
{
	int	n;

	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	return (n);
}

static void	five_finish(t_node **a, t_node **b)
{
	sort_3(a);
	while (count_n(*b) != 0)
	{
		if ((*b)->content == 0)
            pb(b, a);
		else
		{
            pb(b, a);
            ra(a);
		}
	}
}

void	sort_for_5(t_node **a, t_node **b, int argc)
{
	t_node	*max_min;

	max_min = *a;
	while (count_n(*a) != 3)
	{
		if (max_min->content == 0)
		{
			max_min = max_min->next;
            pb(b, a);
		}
		else if (max_min->content == argc - 2)
		{
			max_min = max_min->next;
			pb(b, a);
		}
		else
		{
			max_min = max_min->next;
            ra(a);
		}
	}
	five_finish(a, b);
}