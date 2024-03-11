#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
    int *array;
    int i = 0;
    int length = end - start;
    int step = 1;

    // NB PRECISE CASE IF END - START NEGATIVE
    if (length < 0)
        length *= -1;
    array = (int *)malloc(sizeof(int) * (length + 1));
    // NB CASE IF MALLOC FAILS
    if (!array)
        return 0;
    //THINK OF CREATING  A STEP
    if (start < end)
        step = -1;
    while (i <= length)
    {
        array[i] = end;
        end = end + step;
        i++;
    }
    return (array);
}

#include <stdio.h>

int main(void)
{
    int *res = ft_rrange(0, -3);
    int i = 0;

    while (i <= 3)
    {
        printf("%d", res[i]);
        i++;
    }

}