/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:49:19 by eleroty           #+#    #+#             */
/*   Updated: 2023/12/21 18:31:36 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_node
{
    int             content;
    int             *index;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

typedef struct {
    int min;
    int next_min;
} min_values;

typedef struct {
    int max;
    int next_max;
} max_values;

t_node *find_max_node(t_node **a, int value);
void	push_rules_2(t_node **a, t_node **b);
void	last_case(t_node **a, t_node **b);
int	size_five(t_node **a, t_node **b, int size);
bool	is_sorted(t_node **stack);
void    stack_initializor(t_node **a, char **argv, int size);
void	quick_sort(t_node *a);
void	free_linked_list(t_node *lst);
int	main(int argc, char **argv);
void quickSort(t_node *a);
void	free_linked_list(t_node *lst);
// int    find_min(t_node **lst, int prev_min);
void	sort_3(t_node **lst);
void simple(t_node **lst);
min_values find_min(t_node *head);
void push(t_node **dest, t_node **src);
void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);
void printList(t_node *head);
// static void reverse(t_node **lst);
void    rra(t_node **a);
// void    rrb(t_node **b);
// void    rrr(t_node **a, t_node **b);
max_values find_max(t_node *head);

void sort_5(t_node **a, t_node **b);
// void sort_5(t_node **a);

void rotate(t_node **lst);
void    ra(t_node **a);
// void    rb(t_node **b);
// void    rr(t_node **b, t_node **a);

// void swap(t_node *first, t_node *second, t_node **lst);
void	swap(t_node **head);
// int	get_high_index(t_node *a);
void    sa(t_node **a);
// void    sb(t_node **b);
// void    ss(t_node **a, t_node **b);

int ft_lstsize(t_node *lst);
t_node    *ft_lstlast(t_node *lst);
void    ft_lstadd_front(t_node **lst, t_node *new);

#endif