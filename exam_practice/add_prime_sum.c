#include <unistd.h>
#include <stdio.h>

int ft_minatoi(char *s)
{
    int res = 0;
    int i = 0;

    while (s[i])
        res = res * 10 + (s[i++] - '0');
    return (res);
}

void ft_minputnbr(int n)
{
    if (n >= 10)
        ft_minputnbr(n / 10);
    char res = n % 10 + '0'; //NB
    write(1, &res, 1);
} 

int is_prime(int num)
{
    int i = 2;

    if (num <= 1)
        return 1;
    //iterate over the square root of num
    while (i * i <= num)
    {
        if (num % i == 0)
            return 1;
        i++;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    unsigned int n;
    unsigned int sum = 0;
    char res;

    if (argc == 2)
    {
        n = ft_minatoi(argv[1]);
        while(n > 0)
        {
            if (is_prime(n) != 1)
                sum += n;
            n--;
        }
        ft_minputnbr(sum);
    }
    write(1, "\n", 1);
}