/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:19 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/22 17:26:43 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdlib.h>
#include <stdio.h>

void    stack_initializor(t_node **a, char **argv)
{
	t_node	*tmp;
	t_node	*start;
	int	i;

	i = 0;
	// iterating through the commandline arguments and checking each arg for syntax errors
	while (argv[i])
	{
		if (is_error(argv[i]))
			free_errors(*a);
		tmp = malloc(sizeof(t_node));
		if (tmp == NULL)
		{
	
			free_linked_list(*a);
			return ;
		}
		tmp->content = ft_atol(argv[i]);
		tmp->next = NULL;
		if (tmp->content > INT_MAX || tmp->content < INT_MIN)
		{
			free_errors(*a);
		}
		if (error_duplicate(*a, (int)tmp->content))
			free_errors(*a);
		if (*a == NULL)
		{	
			*a = tmp;
			start = *a;
		}
		else
		{
			tmp->prev = start;
			start->next = tmp;
			start = tmp;
		}
		i++;
	}	
}

void printList(t_node *head)
{
    while (head != NULL)
	{
        printf("%ld ", head->content);
        head = head->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) // not enough arguments or second argument is null
		return (1);
	else if (argc == 2) // case in which we have a string
	{
		argv = split(argv[1], ' ');
		stack_initializor(&a, argv);
	}
	else
		stack_initializor(&a, argv + 1);
	if (!is_sorted(&a))
	{
		if(ft_size(a) == 2)
			sa(&a);
		else if (ft_size(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
	}
	// printList(a);
	// printList(b);
	free_linked_list(a);
	free_linked_list(b);
	return(0);
}