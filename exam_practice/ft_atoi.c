#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int sign = 1;
    int res;

    while (str[i])
    {
        while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f' || str[i] == '\v' || str[i] == '\r'))
            i++;
        if ( str[i] && (str[i] == '-' || str[i] == '+'))
        {
            if (str[i] == '-')
                sign = -1;
            i++;
        }
        while(str[i] && (str[i] >= '0' && str[i] <= '9'))
        {
            res = res * 10 + (str[i] - '0'); // NB!!!!!
            i++;
        }
    }
    return (res * sign);
}

int main(void)
{
    char *s = "34";

    printf("%d ", ft_atoi(s));
}