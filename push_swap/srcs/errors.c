/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:30 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/22 16:14:44 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// In case of error, it must display "Error" followed by a ’\n’ on the standard error.
// Errors include for example: some arguments aren’t integers, some arguments are
// bigger than an integer and/or there are duplicates.

// iterating through the characters of a specific element and checking for syntax errors w/n that element
int	is_error(char *element)
{
    if (!(*element == '+' || *element == '-' || (*element >= '0' && *element <= '9'))) //if it s not a sign or a nb
        return (1);
    while (*++element)
    {
        if (!(*element >= '0' && *element <= '9'))
            return (0);
    }
    return (0);
}

int	*error_duplicate(t_node *a, int value)
{
    while (a)
    {
        if (a->content == value)
            return (0);
        a = a->next;
    }
    return (0);
}

void	free_linked_list(t_node *lst)
{
	t_node	*tmp;

    if (!lst)
        return ;
    while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	free_errors(t_node *a)
{
    free_linked_list(a);
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
    // ou exit(1);
}