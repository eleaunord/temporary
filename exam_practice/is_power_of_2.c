
int	    is_power_of_2(unsigned int n)
{
    unsigned int res = 2;
    unsigned int i = 0;
    
    //NB condition if n == 0
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    while (i <= n)
    {
        if (res == n)
            return (1);
        res = res * 2;
        i++;
    }
    return 0;
}

#include <stdio.h>

int main(void)
{
    printf("%d", is_power_of_2(15));
}

