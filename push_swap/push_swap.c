#include "push_swap.h"

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
		if (tmp->content > INT_MAX || tmp->content < INT_MIN) //Check for overflow
			free_errors(*a);
		if (error_duplicate(*a, (int)tmp->content))
			free_errors(*a);
		i++;
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
	// not sure if static variables are correct

	if (argc == 1 || (argc == 2 && !argv[1][0])) // not enough arguments or second argument is null
		return (1);
	else if (argc == 2) // case in which we have a string
		argv = ft_split(argv[1], ' ');
	stack_initializor(&a, argv + 1);
	if (!is_sorted(&a))
	{
		if(ft_lstsize(a) == 2)
			sa(&a);
		else if (ft_lstsize(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
	}

	// b = (t_node *)malloc(sizeof(t_node));
	// b->content = 0;
	// b->next = NULL;
	// partition(a);
	// printList(a);
	// printList(b);
	// sort_3(&a);
	// sort_5(&a, &b);
	// sort_5(&a, &b);
	// printList(a);
	// printList(b);
	// b = NULL;
	// printList(b);

	free_linked_list(a);
	free_linked_list(b);
	return(0);
}