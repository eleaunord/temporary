//  * Check if a given stack is sorted
// */
// bool	stack_sorted(t_stack_node *stack)
// {
// 	if (NULL == stack)
// 		return (1);
// 	while (stack->next)
// 	{
// 		if (stack->value > stack->next->value)
// 			return (false);
// 		stack = stack->next;
// 	}
// 	return (true);
// }

// static t_stack_node	*find_highest(t_stack_node *stack)
// {
// 	int				highest;
// 	t_stack_node	*highest_node;

// 	if (NULL == stack)
// 		return (NULL);
// 	highest = INT_MIN;
// 	while (stack)
// 	{
// 		if (stack->value > highest)
// 		{
// 			highest = stack->value;
// 			highest_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (highest_node);
// }

// /*
//  * When i have 3 nodes, easy to sort
//  * 	~If the 1* is the biggest, ra (biggestto bottom)
//  * 	~If the 2* is the biggest, rra (biggest to bottom)
//  * 	~Now i have forcefully the Biggest at the bottom
//  * 		so i just chek 1° and 2°
// */
// void	tiny_sort(t_stack_node **a)
// {
// 	t_stack_node	*highest_node;

// 	highest_node = find_highest(*a);
// 	if (*a == highest_node)
// 		ra(a, false);
// 	else if ((*a)->next == highest_node)
// 		rra(a, false);
// 	if ((*a)->value > (*a)->next->value)
// 		sa(a, false);
// }

// /*
//  * Handle input 5
// */
// void	handle_five(t_stack_node **a, t_stack_node **b)
// {
// 	while (stack_len(*a) > 3)
// 	{
// 		init_nodes(*a, *b);
// 		finish_rotation(a, find_smallest(*a), 'a');
// 		pb(b, a, false);
// 	}
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