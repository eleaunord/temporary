/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:49:19 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/17 16:29:07 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

// #include "../42cursus/libft/git/1- Libft/inc/libft.h"

// NODES
typedef struct s_node
{
    int             content;
    int             index;
	int				push_cost;
	bool 			first_half;
	// bool			cheapest;
	struct s_node	*cheapest_node;
    struct s_node   *next;
    struct s_node   *prev;
	struct s_node   *target_node;
	struct s_moves  *moves;
} t_node;

// MIN & MAX
typedef struct {
    int min;
    int next_min;
} min_values;

typedef struct {
    int max;
    int next_max;
} max_values;

// FUNCTIONS LIST

// PUSH SWAP
void    stack_initializor(t_node **a, char **argv);
void printList(t_node *head);
int	main(int argc, char **argv);

// PUSH
void	push(t_node **dest, t_node **src);
void    pa(t_node **a, t_node **b);
void    pb(t_node **b, t_node **a);

//REVERSE
void	reverse(t_node **lst);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);

// ROTATE
void rotate(t_node **lst);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **b, t_node **a);

// ERRORS
int	is_error(char *element);
int	*error_duplicate(t_node *a, int value);
void	free_linked_list(t_node *lst);
void	free_errors(t_node *a);

// SORT 3
void	sort_3(t_node **lst);

// SORT
t_node *find_content_node(t_node **a, int value);
int find_index_b(t_node **stack, int value);
void    set_index(t_node *stack);
void set_target_a_to_b(t_node *a, t_node *b);
void set_target_b_to_a(t_node *a, t_node *b);
void    cost_analysis(t_node *a, t_node *b);
void    find_cheapest(t_node *a);
void    push_a_to_b(t_node *a, t_node *b);
void    is_min_on_top(t_node *a);
void sort(t_node **a, t_node **b);

// SWAP
void	swap(t_node **head);
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);

//UTILS
bool	is_sorted(t_node **stack);
max_values find_max(t_node *head);
min_values find_min(t_node *head);

// ERRORS
int	is_error(char *element);
int	*error_duplicate(t_node *a, int value);
void	free_linked_list(t_node *lst);
void	free_errors(t_node *a);

// LIBFT
int ft_lstsize(t_node *lst);
void    ft_lstadd_front(t_node **lst, t_node *new);
t_node    *ft_lstlast(t_node *lst);
void    ft_lstadd_back(t_node **lst, t_node *new);
char	**ft_split(char const *s, char c);

#endif