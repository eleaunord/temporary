
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    unsigned int j;
    unsigned int temp;

    i = 0;
    while(i < size - 1)
    {
        j = 0;
        // - i so that we have the number of unsorted elements remaining in the array
        while(j < size - i - 1)
        {
            if (tab[j] > tab[j + 1])
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

int main(void)
{
    int tab[5] = {10, 2, 21, 4, 1};
    int i = 0;

    sort_int_tab(tab, 5);

    // Print the sorted array
    printf("Sorted array: ");
    while(i < 5)
    {
        printf("%d ", tab[i++]);
    }
    printf("\n");
    return 0;
}
