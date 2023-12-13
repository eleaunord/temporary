/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:49:19 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/13 14:26:29 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int             content;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

void    stack_initializor(t_node **a, char **argv, int size);
void	quick_sort(t_node *a);
void	free_linked_list(t_node *lst);
int	main(int argc, char **argv);
void quickSort(t_node *a);
void	free_linked_list(t_node *lst);

// static void push(t_node **dest, t_node **src);
// void    pa(t_node **a, t_node **b);
// void    pb(t_node **b, t_node **a);

// static void reverse(t_node **lst);
// void    rra(t_node **a);
// void    rrb(t_node **b);
// void    rrr(t_node **a, t_node **b);

// static void rotate(t_node **lst);
// void    ra(t_node **a);
// void    rb(t_node **b);
// void    rr(t_node **b, t_node **a);

void swap(t_node **lst);
void    sa(t_node **a);
// void    sb(t_node **b);
// void    ss(t_node **a, t_node **b);

int ft_lstsize(t_node *lst);

#endif