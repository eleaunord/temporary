#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    int i = 0;

    while (s[i])
        ft_putchar(s[i++]);
}

void ft_writenum(int num)
{
    char s[10] = "0123456789";

    if (num > 9)
        ft_writenum(num / 10);
    ft_putchar(s[num % 10]);
}

int main(void)
{
    int i = 1;

    while (i <= 100)
    {
        
        if (i % 3 == 0 && i % 5 == 0)
            ft_putstr("fizzbuzz");
        else if  (i % 3 == 0)
            ft_putstr("fizz");
        else if  (i % 5 == 0)
            ft_putstr("buzz");
        else
            ft_writenum(i);
        i++;
        write (1, "\n", 1);
    }

}