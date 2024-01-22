/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:52:01 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/22 17:26:00 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

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

//did it without intermediate var i, hopefully works the same UPDATED
void    set_index(t_node *stack)
{
    int median;
    int i;

    median = ft_size(stack) / 2;
    i = 0;
    if (!stack)
        return ;
    while (stack != NULL)
    {
        stack->index = i;
        if (i <= median)
            stack->first_half = true;
        else
            stack->first_half = false;
        stack = stack->next;
        i++;
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
            if (current_a->content > b->content && current_a->content < closest_biggest)
            {
                closest_biggest = current_a->content;
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

    size_a = ft_size(a);
    size_b = ft_size(b);
    while (a)
    {
        a->push_cost = a->index; //initializing since if it's at head_a index will be 0 so = 0
        //bringing a on top of stack a
        if (!(a->first_half))
            a->push_cost = size_a - (a->index);
        if (a->target_node != NULL)
        {
            // + bringing a->target on top of stack b
            if (a->target_node->first_half)
                a->push_cost += a->target_node->index;
            else // if the target node is NOT in the first half
                a->push_cost += size_b - (a->target_node->index);
        }
        else
            break ;
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
        //== false
        if (a->cheapest_node->first_half)
            ra(&a);
        else
            rra(&a);
    }
    while (head_b != a->cheapest_node->target_node)
    {
        //== false
        if (a->cheapest_node->target_node->first_half)
            rb(&b);
        else
            rrb(&b);
    }
    //finally pushing a to b
    pb(&b, &a);
}

//locate where smaller number is in the stack and then ra or rra depending on where is it in the median
void    is_min_on_top(t_node **a)
{
    min_values minValues = find_min(*a);
    t_node  *min_node = find_content_node(a, minValues.min);

    while ((*a) != min_node)
    {
        // == false
        if (min_node->first_half)
        {
            ra(a);
        }
        else
            rra(a);
    }
}

//stack a has more than 3 nodes
void sort(t_node **a, t_node **b)
{
    int size_a;
    int nb_in_b;

    size_a = ft_size(*a);
    nb_in_b = 0;
    //pushing two limits in b
    while (size_a > 3 && !is_sorted(a) && nb_in_b <= 2)
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
        //making sure b target node in a is on top of stack a OKAY
        while ((*a) != (*b)->target_node && (*b)->target_node != NULL)
        {
            //==false
            if ((*b)->target_node->first_half)
                ra(a);
            else
                rra(a);
        }
        pa(a, b);
    }
    //refresh the current position of stack `a`
    set_index(*a);
    //check if min on top of stack a
    is_min_on_top(a);
}