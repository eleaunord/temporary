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
		{
			free_linked_list(*a);
			return ;
		}
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
		i++;
	}
	
}

// void	partition(t_node *a)
// {
// 	t_node	*i;
// 	t_node	*j;
// 	t_node	*low;
// 	t_node 	*high;
// 	int	pivot;

// 	low = a;
// 	high = ft_lstlast(a);
// 	i = low;
// 	j = low;
// 	pivot = high->content;
// 	while (j != high)
// 	{
// 		if (j->content < pivot)
// 		{
// 			swap(&a->head);
// 			i = i->next;
// 		}
// 		j = j->next;
// 	}
// 	swap(&a->head);
// }

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
	t_node	*a = NULL;
	t_node	*b = NULL;


	if (argc > 1)
	{
		stack_initializor(&a, argv + 1, argc - 1);
	}
	b = (t_node *)malloc(sizeof(t_node));
	// partition(a);
	// printList(a);
	// printList(b);
	sort_3(&a);
	// sort_5(&a, &b);
	sort_5(&a, &b);
	printList(a);
	// free_linked_list(a);
	// free_linked_list(b);
	return(0);
}