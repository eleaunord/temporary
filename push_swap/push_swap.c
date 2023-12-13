#include "push_swap.h"

#include <stdlib.h>
#include <stdio.h>

void    stack_initializor(t_node **a, char **argv, int size)
{
	t_node	*tmp;
	t_node	*start;
	int	i;

	i = 0;
	while (i < size)
	{
		tmp = malloc(sizeof(t_node));
		if (tmp == NULL)
			return ;
		tmp->content = atoi(argv[i]);
		tmp->next = NULL;
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
		// printf("%d ", tmp->content);
		i++;
	}
	
}

// //a = 40 90 30 80 10 
// //b = .  .  .  .  .
// //40 is the pivot
void swap(t_node **lst)
{
    t_node *first;
    t_node *second;

	printf("%s ", "hey");
    first = *lst;
    second = (*lst)->next;
    if (*lst == NULL || (*lst)->next == NULL)
        return ;
    first->prev = second;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    second->prev = NULL;
    *lst = second; 
}


void quickSort(t_node *a)
{
	int	pivot = a->content;
	// int	len = ft_lstsize(a);

	while(a)
	{
		if (a->content < pivot)
			swap(&a);
		a = a->next;	
	}
}

void	free_linked_list(t_node *lst)
{
	t_node	*tmp;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void printList(t_node *head)
{
    while (head != NULL)
	{
        printf("%d ", head->content);
        head = head->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	static t_node	*a = NULL;
	// static t_node	*b = NULL;

	if (argc > 1)
		stack_initializor(&a, argv + 1, argc - 1);
	// quickSort(a);
	printList(a);
	free_linked_list(a);
	return(0);
}

