#include <stdlib.h>
#include <stdio.h>

// think about creating a step and checking if start < end and vice and versa
int     *ft_range(int start, int end)
{
    int length = end - start;
    int i = 0;
    int step = 1;

    if (length < 0)
        length *= -1;
    
    int *array;
    array = (int *)malloc(sizeof(int) * (length + 1));
    if (!array)
        return 0;
    if (start > end)
        step = -1;
    while (i <= length)
    {
        array[i] = start;
        start = start + step;
        i++;
    }
    return (array);
}

int main()
{
    int *res = ft_range(0, -3);
    int i = 0;

    while (i <= 3)
    {
        printf("%d ", res[i]);
        i++;
    }
    
}