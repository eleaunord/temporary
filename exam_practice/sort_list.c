#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

// void    ft_swap(int *a, int *b)
// {
//     int tmp;

//     tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

int ascending(int a, int b)
{
	return (a <= b);
}

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
// {
//     t_list *tmp;
    
//     tmp = lst;
//     if (lst = NULL)
//         return NULL;
//     while(lst != NULL)
//     {
//         if ((*cmp)(lst->data, lst->next->data) == 0)
//         {
//             ft_swap(&lst->data, &lst->next->data);
//             lst = tmp;
//         }
//         else
//             lst = lst->next;
//     }
//     lst = tmp;
//     return (lst);
// }

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			ft_swap(&lst->data, &lst->next->data);
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
void print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("%d ", lst->data);
        lst = lst->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *head = NULL;
    t_list *second = NULL;
    t_list *third = NULL;

    // Create a linked list: 3 -> 1 -> 2
    head = (t_list *)malloc(sizeof(t_list));
    second = (t_list *)malloc(sizeof(t_list));
    third = (t_list *)malloc(sizeof(t_list));

    head->data = 3;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 2;
    third->next = NULL;

    // Print the original list
    printf("Original List: ");
    print_list(head);

    // Sort the list in ascending order
    head = sort_list(head, ascending);

    // Print the sorted list
    printf("Sorted List: ");
    print_list(head);

    return 0;
}