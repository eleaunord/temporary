#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
void sort_int_tab(int *tab, unsigned int size)
{
    int j = 0;
    int i = 0;
    
    if (size <= 1)
        return ;
    while (j < size)
    {
        i = 0;
        while(i < size - 1)
        {
            if (tab[i] > tab[i + 1])
                ft_swap(&tab[i], &tab[i + 1]);
            i++;
        }
        j++;
    }
}

int main()
{
    int tab[] = {34, 41, 1, 2};
    int i = 0;

    sort_int_tab(tab, 4);
    while (i < 4)
    {
        printf("%d ", tab[i]);
        i++;
    }
    return 0;
}

// void	sort_int_tab(int *tab, unsigned int size)
// {
// 	int	idx;
// 	int	bubble;

// 	idx = 0;
// 	bubble = 0;
// 	if (size <= 1)
// 		return ;
// 	while (bubble < size)
// 	{
// 		idx = 0;
// 		while (idx < (size - 1))
// 		{
// 			if (tab[idx] > tab[idx + 1])
// 				ft_swap(&tab[idx], &tab[idx + 1]);
// 			idx++;
// 		}
// 		bubble++;
// 	}
// }
