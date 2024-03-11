#include <unistd.h>


void ft_putstr(char *s)
{
    int i = 0;

    while (s[i])
        write(1, &s[i++], 1);
}

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 4 && !argv[2][1] && !argv[3][1]) // NB add condition that arg 2 and 3 must be letters and not words
    {
        while(argv[1][i])
        {
            if (argv[1][i] == argv[2][0])
                argv[1][i] = argv[3][0]; 
            i++;
        }
        ft_putstr(argv[1]);
    }
    write(1, "\n", 1);
}