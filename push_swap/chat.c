
#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
    int             content;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;

void swap(t_node **lst)
{
    t_node *first;
    t_node *second;

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
void    stack_initializor(t_node **a, char **argv, int size)
{
	t_node	*tmp;
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
			*a = tmp;
		else
		{
			tmp->prev = *a;
			(*a)->next = tmp;
			*a = tmp;
		}
		// printf("%d ", tmp->content);
		i++;
	}
}
// //a = 40 90 30 80 10 
// //40 is the pivot
void	quick_sort(t_node **a)
{
	t_node	*pivot;
	t_node	*current;

	pivot = *a;
	current = *a;
	while (current != NULL)
	{
		if (current->content < pivot->content)
			swap(a);
		printf("%d ", current->content);
        printf("%s ", "coucou");
		current = current->next;	
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

int	main(int argc, char **argv)
{
	static t_node	*a = NULL;
	// static t_node	*b = NULL;

	if (argc > 1)
		stack_initializor(&a, argv + 1, argc - 1);
	quick_sort(&a);
	free_linked_list(a);
	return(0);
}

