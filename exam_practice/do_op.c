#include <stdio.h>
#include <stdlib.h>

//NB argv[2][0] == ' '
int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        if (argv[2][0] == '+')
            printf("%d", atoi(argv[1]) + atoi(argv[3]));
        if (argv[2][0] == '-')
            printf("%d", atoi(argv[1]) - atoi(argv[3]));
        if (argv[2][0] == '/')
            printf("%d", atoi(argv[1]) / atoi(argv[3]));
        if (argv[2][0] == '*')
            printf("%d", atoi(argv[1]) * atoi(argv[3]));
        if(argv[2][0] == '%')
            printf("%d", atoi(argv[1]) % atoi(argv[3]));
    }
    printf("\n");
}