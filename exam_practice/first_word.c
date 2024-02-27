
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    first_word(char *word)
{
    int i;

    i = 0;
    while (word[i] == ' ' || word[i] == '\t')
        i++;
    while (word[i] && word[i] != ' ' && word[i] != '\t')
    {
        ft_putchar(word[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
        first_word(argv[1]);
    ft_putchar('\n');
}