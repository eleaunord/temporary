
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    alpha_mirror(char *word)
{
    int i;

    i = 0;
    while (word[i])
    {
        if (((word[i] >= 'A')) && (word[i] <= 'Z'))
            word[i] = ('M' - (word[i] - 'N'));
        else if (((word[i] >= 'a')) && (word[i] <= 'z'))
            word[i] = ('m' - (word[i] - 'n'));
        ft_putchar(word[i]);
        i++;
    }
    
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    ft_putchar('\n');
}