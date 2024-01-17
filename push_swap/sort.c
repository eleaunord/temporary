#include "push_swap.h"

t_node *find_content_node(t_node **a, int value)
{
    t_node *current;
    t_node *node;

    node = NULL;
    current = *a;
    while (current != NULL)
    {
        if (current->content == value)
            node = current;
        current = current->next;
    }
    return (node);
}

//find index stack b
int find_index_b(t_node **stack, int value)
{
    t_node *current;
    int i;

    i = 0;
    current = *stack;
    while (current != NULL)
    {
        if (current->content == value)
            break ;
        current = current->next;
        i++;
    }
    return (i);
}

//did it without intermediate var i, hopefully works the same
void    set_index(t_node *stack)
{
    int median;

    median = ft_lstsize(stack) / 2;
    stack->index = 0;
    if (!stack)
        return ;
    while (stack != NULL)
    {
        stack->index++;
        if (stack->index < median)
            stack->first_half = true;
        else
            stack->first_half = false;
        stack = stack->next;
        stack->index++;
    }
}

//target node = closest smaller node to a in b
//if we can't find the closest smaller node then the target node is max value
void set_target_a_to_b(t_node *a, t_node *b)
{
    int closest_smallest;
    max_values maxValues = find_max(b);
    t_node  *current_b;
    t_node  *target;

    while (a)
    {
        closest_smallest = INT_MIN;
        current_b = b;
        while (current_b)
        {
            if (a->content > b->content && b->content > closest_smallest)
            {
                closest_smallest = b->content;
                target = current_b;
            }
            current_b = current_b->next;
        }
        if (closest_smallest == INT_MIN)
           target = find_content_node(&b, maxValues.max);
        else
            a->target_node = target;
        a = a->next;
    }
}

//target node = closest biggest node to b in a
//if we can't find the closest smaller node then the target node is min value
void set_target_b_to_a(t_node *a, t_node *b)
{
    int closest_biggest;
    min_values minValues = find_min(b);
    t_node  *current_a;
    t_node  *target;

    while (b)
    {
        closest_biggest = INT_MAX;
        current_a = a;
        while (current_a)
        {
            if (a->content > b->content && b->content < closest_biggest)
            {
                closest_biggest = a->content;
                target = current_a;
            }
            current_a = current_a->next;
        }
        if (closest_biggest == INT_MAX)
           target = find_content_node(&a, minValues.min);
        else
            b->target_node = target;
        b = b->next;
    }
}

//here we look how we can put b in descending order the cheapest way
//x operations to bring a on top stack a + x operations to bring a->target node on top b = push_cost
void    cost_analysis(t_node *a, t_node *b)
{
    int     size_a;
    int     size_b;

    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    while (a)
    {
        a->push_cost = a->index; //initializing since if it's at head_a index will be 0 so = 0
        //bringing a on top of stack a
        if (a->first_half == false)
            a->push_cost = size_a - (a->index);
        // + bringing a->target on top of stack b
        if (a->target_node->first_half == false)
            a->push_cost += size_b - (a->target_node->index);
        else // if the target node is in the first half
            a->push_cost += a->target_node->index;
        a = a->next;
    }
}

void    find_cheapest(t_node *a)
{
    int cheap_cost;
    // t_node  *cheapest_node;
    t_node *current_a = a;
    
    cheap_cost = INT_MAX;
    if (!a)
        return ;
    while (current_a)
    {
        if (current_a->push_cost < cheap_cost)
        {
            cheap_cost = current_a->push_cost;
            a->cheapest_node = current_a;
            // cheapest_node = a;
        }
        current_a = current_a->next;
    }
    // cheapest_node->cheapest = true;
}

//pushing the cheapest_node to sorted b
// cheapest above target node and on top
void    push_a_to_b(t_node *a, t_node *b)
{
    t_node  *head_a = a;
    t_node  *head_b = b;

    //making sure the one at the top are not the cheapest nodes
    if ((head_a != a->cheapest_node) && (head_b != a->cheapest_node->target_node))
    {
        if (a->cheapest_node->first_half == false && a->target_node->first_half == false)
            rr(&b, &a);
        if (a->cheapest_node->first_half == true && a->target_node->first_half == true)
            rrr(&b, &a);
    }
    //resetting indexes
    set_index(a);
    set_index(b);
    //making sure if cheapest of a at top of a and cheapest's target at top of b
    while (head_a != a->cheapest_node)
    {
        if (a->cheapest_node->first_half == false)
            ra(&a);
        else
            rra(&a);
    }
    while (head_b != a->cheapest_node->target_node)
    {
        if (a->cheapest_node->target_node->first_half == false)
            rb(&b);
        else
            rrb(&b);
    }
    //finally pushing a to b
    pb(&b, &a);
}

//locate where smaller number is in the stack and then ra or rra depending on where is it in the median
void    is_min_on_top(t_node *a)
{
    min_values minValues = find_min(a);
    t_node  *head_a = a;
    t_node  *min_node = find_content_node(&a, minValues.min);

    while (head_a != min_node)
    {
        if (min_node->first_half == false)
            ra(&a);
        else
            rra(&a);
    }
}

//stack a has more than 3 nodes
void sort(t_node **a, t_node **b)
{
    int size_a;
    int nb_in_b;

    size_a = ft_lstsize(*a);
    nb_in_b = 0;
    //pushing two limits in b
    while (size_a > 3 && !is_sorted(a) && nb_in_b < 2)
    {
        pb(b, a);
        size_a--;
        nb_in_b++;
    }
    while (size_a > 3 && !is_sorted(a))
    {
        //every a node needs a target node from stack b
        //target = closest smaller nb to a OR max if not found
        //setting indexes for each node of a and keeping track if they're above the median or not
        set_index(*a);
        //setting indexes for each node of b and keeping track if they're above the median or not
        set_index(*b);
        //set a target node for each node of a in b // CLOSEST SMALLER
        set_target_a_to_b(*a, *b);
        //calculating the push cost for each node in a (depending on its position in a and the position of its target node in b)
        cost_analysis(*a, *b);
        //finding the cheapest node to push according to its push cost
        find_cheapest(*a);
        // move cheapest node in a found into sorted stack b until there are 3 nodes left in a
        push_a_to_b(*a, *b);
    }
    sort_3(a);
    while (*b)
    {
        //before we push b node back to stack a we need to make sure it will be pushed on top of the correct node
        //every b node as a target node in a
        // target node == closest biggest ow min
        set_index(*a);
        //setting indexes for each node of b and keeping track if they're above the median or not
        set_index(*b);
        //set a target node for each node of b in a // CLOSEST BIGGEST
        set_target_b_to_a(*a, *b);
        //making sure b target node in a is on top of stack a
        while ((*a) != (*b)->target_node)
        {
            if ((*b)->target_node->first_half == false)
                ra(a);
            else
                rra(a);
        }
        pa(a, b);
    }
    //refresh the current position of stack `a`
    set_index(*a);
    //check if min on top of stack a
    is_min_on_top(*a);
}

// t_node  *current_cheapest(t_node *a)
// {
//     t_node  *cheapest_node;

//     if (!a)
//         return (NULL);
//     while (a)
//     {
//         if(a == cheapest_node)
//             return (a);
//         a = a->next;
//     }
//     return (NULL);
// }

// int closest_biggest(t_node *b, int num, int target)
// {
//     while (b != NULL)
//     {
//         target--;
//         if (b->content < num)
//                 break ;
//         b = b->next;
//     }
//     return (target);
// }




// for cost analysis
// void update_stack(t_node *stack, t_node *element, int index, int move1, int move2)
// {
//     int size = ft_lstsize(stack);

//     if (size % 2 == 0)
//     {
//         if (index + 1 > size / 2)
//             move1 = (size - index);
//         else
//            move2 = index;
//     }
//     else
//     {
//         if (index > size / 2)
//             move1 = (size - index);
//         else
//            move2 = index;
//     }
// }

// int    cost_analysis(t_node *a, t_node *b, t_node *current, t_node *target_pos)
// {
//     int push_cost;
//     t_node *max_b;
//     t_node *min_b;
//     t_node *head_a = a; //initialize new value so we keep *a
//     t_node *head_b = b;
//     max_values maxValues = find_max(b);
//     min_values minValues = find_min(b);
//     int i = 0;
//     int index = 0;
//     int size = ft_lstsize(a);
//     int num = minValues.min;

//     push_cost = 0;
//     //push_cost = nb operations to bring a on top + operations to bring a->target node on top;
//     //ordre croissant (?) nb avant targerr decending order
//     //sort three
//     // pushh all b nodes to a

//     // max and min of b
//     min_b = find_max_node(b, minValues.min); // 0
//     max_b = find_max_node(b, maxValues.max); // 99

//     //check moves for current
//     while (i < size)
//     {
//         //how many moves to put the current node at the top of a
//         update_stack(a, head_a, i, a->moves->rra, a->moves->ra);
//         if (head_a->content > max_b || head_a->content < min_b) //new min or max in b
//         {
//             index = find_max_node_index(b, maxValues.max);
//             update_stack(a, head_a->content, index, b->moves->rrb, b->moves->rb);
//         }
//         else // the current node is neither the max nor the min ; we need to put it below its closest max // closest bigger
//         {
//             num = closest_biggest(b, head_a->content, maxValues.max);
//             index = find_index_b(b, num);
//             update_stack(b, head_a->content, index, b->moves->rrb, b->moves->rb);
//         }
//         head_a = head_a->next;
//         i++;
//         //count = for every update stack ?
//     }

//     return (push_cost);
// }
// void    push_at_top_a(t_node *a, t_node *element, int index)
// {
//     int size = ft_lstsize(a);

//     a->moves->ra = 0;
// 	a->moves->rra = 0;
//     if (a->content == element->content)
//         return;
//     if (size % 2 == 0)
//     {
//         if (index + 1 > size / 2)
//             a->moves->rra = (size - index);//nb of reverse rotations to bring the element to the top
//         else
//             a->moves->ra = index;//nb of rotations to bring the element to the top
//     }
//     else
//     {
//         if (index > size / 2)
//             a->moves->rra = (size - index);
//         else
//             a->moves->ra = index;
//     }
// }

// void update_min_or_max_b(t_node *a, t_node *b, t_node element)
// {
//     int size = ft_lstsize(b);
//     int index;
//     max_values maxValues = find_max(b);

//     b->moves->rb = 0;
// 	b->moves->rrb = 0;
//     index = find_index_b(b, maxValues.max);
//     if (size % 2 == 0)
//     {
//         if (index + 1 > size / 2)
//             b->moves->rrb = (size - index);
//         else
//             b->moves->rb = index;
//     }
//     else
//     {
//         if (index > size / 2)
//             b->moves->rrb = (size - index);
//         else
//             b->moves->rb = index;
//     }
// }

// void    update_b(t_node *a, t_node *b, t_node element)
// {
//     int size = ft_lstsize(a);
//     int index = find_index_b(b);

//     if (size % 2 == 0)
//     {
//         if (index + 1 > size / 2)
//             a->moves->rra = (size - index);//nb of reverse rotations to bring the element to the top
//         else
//             a->moves->ra = index;//nb of rotations to bring the element to the top
//     }
//     else
//     {
//         if (index > size / 2)
//             a->moves->rra = (size - index);
//         else
//             a->moves->ra = index;
//     }
// }
// void	new_num_in_stack_b(t_stacks *stacks, int num)
// {
// 	int	i;
// 	int	size;
// 	int	nbr;

// 	stacks->moves->rb = 0;
// 	stacks->moves->rrb = 0;
// 	nbr = search_num_stack_b(stacks, num);
// 	if (stacks->head_b->content == nbr)
// 		return ;
// 	i = find_index_stack_b(stacks, nbr);
// 	size = ft_listsize_b(stacks->head_b);
// 	if (size % 2 == 0)
// 	{
// 		if (i + 1 > size / 2)
// 			stacks->moves->rrb = (size - i);
// 		else
// 			stacks->moves->rb = i;
// 	}
// 	else
// 	{
// 		if (i > size / 2)
// 			stacks->moves->rrb = (size - i);
// 		else
// 			stacks->moves->rb = i;
// 	}
// }

// void min_on_top(t_node **a, t_node *min, t_node **pos)
// {
//     t_node *prev_node;

//     if (min != NULL && *a != NULL)
//     {
//         if (*a == min)
//             return;
//         prev_node = *a;
//         // Find the node before min_node
//         // NB : accessing NULL->next results in a segmentation fault
//         while (prev_node->next != min && prev_node->next != NULL)
//             prev_node = prev_node->next;

//         // Check if max_node is not in the list
//         if (prev_node->next == NULL)
//             return;
//         // Update pointers to move max_node to the head
//         prev_node->next = min->next;
//         min->next = *pos;
//         *pos = min;
//     }
// }
// void sort(t_node **a, t_node **b)
// {
// 	pb(b, a);
// 	pb(b, a);

// 	t_node *current = *a;
// 	min_node = find_min_node(a, minValues.min);

// 	if (current->content == min_node)
// }
// void sort_5(t_node **a, t_node **b)
// {
// 	min_values minValues = find_min(*a);
// 	int	count = ft_lstsize(*a);
	
// 	t_node *min_node = NULL;
// 	t_node *next_min_node = NULL;
// 	min_node = find_min_node(, minValues.min);
//     if (is_sorted(a) == true)
//         return;
//     min_node = find_min_node(a, minValues.min);
// 	min_on_top(a, min_node, a);
// 	next_min_node = find_min_node(a, minValues.next_min);
	
// 	while (count > 3)
// 	{
// 		order_5(a, min_node);
// 		pb(b, a);
// 	}

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

// // /*
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

// void	finish_rotation(t_stack_node **stack,
// 							t_stack_node *top_node,
// 							char stack_name)
// {
// 	while (*stack != top_node)
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top_node->above_median)
// 				ra(stack, false);
// 			else
// 				rra(stack, false);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top_node->above_median)
// 				rb(stack, false);
// 			else
// 				rrb(stack, false);
// 		}	
//