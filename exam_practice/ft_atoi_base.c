#include <stdio.h>

//to lower
char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A')); // NB + 32
    else
        return (c);
}

//get digit
int get_digit(const char c, int digits_in_base)
{
    int max;

    if (digits_in_base <= 10)
        max = digits_in_base + '0';
    else
        max = digits_in_base - 10 + 'a';
    
    if ((c >= '0' && c <= '9') && c <= max)
        return (c - '0');
    else if ((c >= 'a' && c <= 'f') && c <= max)
        return (10 + c - 'a');
    else
        return -1;
}

int	ft_atoi_base(const char *str, int str_base)
{
    int digit;
    int res = 0;
    int sign = 1;
    int i = 0;
    // int len = 0;

    // while (str[len])
    //     len++;
    if (str[0] == '-')
        sign = -1;
    while ((digit = get_digit(to_lower(str[i]), str_base)) >= 0)
    {
        res = res * str_base + (digit * sign);
        i++;
    }
    return (res);
}

int main(void)
{
    printf("%d", ft_atoi_base("2A", 16));
    //42
}