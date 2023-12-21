// //for chat requests
// #include "push_swap.h"
// max_values find_max(t_node *head)
// {
//     max_values  result = {INT_MAX, INT_MAX};

//     while (head != NULL)
//     {
//         if (head->content > result.max) 
//         {
//             result.next_max = result.max;
//             result.max = head->content;
//         }
//         else if (head->content > result.next_max && head->content != result.max)
//         {
//             result.next_max = head->content;
//         }
//         head = head->next;
//     }
//     return result;
// }

// void	sort_5(t_node **a)
// {
//     max_values maxValues = find_max(*a);
//     t_node  *max_node = NULL;
//     t_node *next_max_node = NULL;
//     t_node *current;

// 	if (is_sorted(a) == true)
// 		return ;
//     current = *a;
//     while (current != NULL)
//     {
//         if (current->content == maxValues.max)
//             max_node = current;
//         if (current->content == maxValues.next_max)
//             next_max_node = current;
//         current = current->next;        
//     }
//     if (a && max_node)
//     {
//         max_node->next = *a;
//         *a = max_node;
//     }

//     // pb(b, a);
// }

// int	main(int argc, char **argv)
// {
// 	static t_node	*a = NULL;
// 	static t_node	*b = NULL;


// 	if (argc > 1)
// 	{
// 		stack_initializor(&a, argv + 1, argc - 1);
// 	}
// 	b = (t_node *)malloc(sizeof(t_node));
// 	printList(a);
// 	sort_5(&a);
// 	printList(a);
// 	free_linked_list(a);
// 	free_linked_list(b);
// 	return(0);
// }
