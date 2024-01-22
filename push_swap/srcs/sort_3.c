/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:50 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/19 18:01:40 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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