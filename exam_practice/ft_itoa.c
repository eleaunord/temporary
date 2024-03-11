#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
    char *res;
    int count = 0;
    int i = 0;
    int n;

    // NB to precise special case for INT MIN
    if (nbr == -2147483648)
    {
        return("-2147483648");
    }
    n = nbr;
    while (n > 0)
    {
        count++;
        n = n / 10;
    }
    res = (char *)malloc(sizeof(char) * (count + 1));
    if (!res)
        return (NULL);
    res[count] = '\0';
    if (nbr == 0)
    {
        res[0] = '0';
        return (res);
    }
    if (nbr < 0)
    {
        nbr = -nbr;
        res[0] = '-';
    }
    while (nbr)
    {
        res[--count] = (nbr % 10) + '0';
        nbr = nbr / 10;
    }
    return (res);
}