#include <unistd.h>

void ft_putnbr(int n)
{
    int digit;

    while(n >= 10)
        ft_putnbr(n / 10);
    digit = n % 10 + '0';
    write(1, &digit, 1);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && argv)
    {
        ft_putnbr(argc - 1);
    }
    else
        write(1, "0", 1);
    write(1, "\n", 1);
}